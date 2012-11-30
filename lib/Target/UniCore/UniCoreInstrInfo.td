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
//  Arbitrary patterns that map to one or more instructions
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Instruction list..
//===----------------------------------------------------------------------===//

let neverHasSideEffects = 1 in
// Just a slot to make the build progress success.
def NOP : UniCoreInst<(outs), (ins), "nop", []>;

let isReturn = 1, isTerminator = 1, isBarrier = 1 in {
  def Ret : UniCoreInst<(outs), (ins),
                        "ret",
                        [(ret)]>;
}
