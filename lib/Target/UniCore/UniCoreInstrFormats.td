//===- UniCoreInstrFormats.td - UniCore Instruction Formats -*- tablegen -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Describe UniCore instructions format here
//

// Generic UniCore instruction
class UniCoreInst<dag outs, dag ins,
                  string asmstr, list<dag> pattern> : Instruction {
  field bits<32> Inst;

  let Namespace = "UniCore";

  bits<2> optype;
  bits<4> opcode;
  let Inst{31-30} = optype;
  let Inst{29-26} = opcode;

  dag OutOperandList = outs;
  dag InOperandList  = ins;

  let AsmString   = asmstr;
  let Pattern     = pattern;
}

class InstRI<bits<4> op, dag outs, dag ins,
             string asmstr, list<dag> pattern>
  : UniCoreInst<outs, ins, asmstr, pattern> {
  let optype = 0b10;
  let opcode = op;
}
