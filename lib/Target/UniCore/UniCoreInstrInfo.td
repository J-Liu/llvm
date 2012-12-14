//===-- UniCoreInstrInfo.td - UniCore Instruction defs ----*- tablegen -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file describes the UniCore instructions in TableGen format.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "UniCoreInstrFormats.td"

//===----------------------------------------------------------------------===//
// UniCore type profiles
//===----------------------------------------------------------------------===//

def SDT_UniCoreCallSeqStart : SDCallSeqStart<[SDTCisVT<0, i32>]>;
def SDT_UniCoreCallSeqEnd   : SDCallSeqEnd<[SDTCisVT<0, i32>, SDTCisVT<1, i32>]>;

//===----------------------------------------------------------------------===//
// UniCore specific nodes
//===----------------------------------------------------------------------===//

def ret           :  SDNode<"UniCoreISD::Ret", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue]>;
def callseq_start :  SDNode<"ISD::CALLSEQ_START", SDT_UniCoreCallSeqStart,
                            [SDNPHasChain, SDNPOutGlue]>;
def callseq_end   :  SDNode<"ISD::CALLSEQ_END",   SDT_UniCoreCallSeqEnd,
                            [SDNPHasChain, SDNPOptInGlue, SDNPOutGlue]>;

//===----------------------------------------------------------------------===//
// Pattern Fragments
//===----------------------------------------------------------------------===//
def LO16 : SDNodeXForm<imm, [{
  // Transformation function: return low 16 bits.
  return getI16Imm(N->getZExtValue() & 0xFFFFULL);
}]>;

def HI16 : SDNodeXForm<imm, [{
  // Transformation function: return bits 16-31.
  return getI16Imm(N->getZExtValue() >> 16);
}]>;

def i32hi16 : PatLeaf<(i32 imm), [{
  // i32hi16 predicate - true if the 32-bit immediate has only leftmost 16
  // bits set.
  return ((N->getZExtValue() & 0xFFFF0000ULL) == N->getZExtValue());
}], HI16>;

def immZExt16 : PatLeaf<(imm),
                [{return isUInt<16>(N->getZExtValue()); }], LO16>;

//===----------------------------------------------------------------------===//
// ALU Instructions
//===----------------------------------------------------------------------===//
class ALU_RI<bits<4> subOp, dag outs, dag ins, string asmstr,
             list<dag> pattern>
  : InstRI<subOp, outs, ins, asmstr, pattern> {
  bits<5> rD;
  bits<5> rA;
  bits<16> imm16;

  let Inst{25-21} = rD;
  let Inst{20-16} = rA;
  let Inst{15-0} = imm16;
}

class ALU_RIz<bits<4> subOp, string asmstr, SDNode OpNode>
  : ALU_RI<subOp, (outs GPRRegs:$rD), (ins GPRRegs:$rA, i32imm:$imm16),
           !strconcat(asmstr, "\t$rD, $rA, $imm16"),
           [(set GPRRegs:$rD, (OpNode GPRRegs:$rA, immZExt16:$imm16))]>;

let isAsCheapAsAMove = 1 in {
  def ORI : ALU_RIz<0xa, "l.ori", or>;
}

class MOVHI_I <dag outs, dag ins, list<dag> pattern>
  : UniCoreInst<outs, ins,  "mov\t$rD, $imm", pattern> {
  bits<16> imm;
  bits<5> rD;
  let optype = 0;
  let opcode = 0x6;

  let Inst{16} = 0;
  let Inst{15-0} = imm;
  let Inst{25-21} = rD;
}

let isReMaterializable = 1, isAsCheapAsAMove = 1 in {
  def MOVHI : MOVHI_I<(outs GPRRegs:$rD), (ins i32imm:$imm),
                      [(set GPRRegs:$rD, i32hi16:$imm)]>;
}

//===----------------------------------------------------------------------===//
// Instruction list..
//===----------------------------------------------------------------------===//

let neverHasSideEffects = 1 in
// Just a slot to make the build progress success.
def NOP : UniCoreInst<(outs), (ins), "nop", []>;

// lr is returning address
let isReturn = 1, isTerminator = 1, isBarrier = 1 in {
  def Ret : UniCoreInst<(outs), (ins),
                        "jump\tlr",
                        [(ret)]>;
}

//===----------------------------------------------------------------------===//
// Non-Instruction Patterns
//===----------------------------------------------------------------------===//

// arbitrary immediate
def : Pat<(i32 imm:$imm), (ORI (MOVHI (HI16 imm:$imm)), (LO16 imm:$imm))>;
