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
  field bits<16> Inst;

  let Namespace = "UniCore";

  dag OutOperandList = outs;
  dag InOperandList  = ins;

  let AsmString   = asmstr;
  let Pattern     = pattern;
}
