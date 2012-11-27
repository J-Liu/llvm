//===-- UniCore.td - Describe the UniCore Target Machine ---*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This is the top level entry point for the UniCore target.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Target-independent interfaces
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// Register File, Calling Conv, Instruction Descriptions
//===----------------------------------------------------------------------===//

include "UniCoreRegisterInfo.td"
include "UniCoreInstrInfo.td"
include "UniCoreSchedule.td"

//===----------------------------------------------------------------------===//
// UniCore Subtarget features                                              //
//===----------------------------------------------------------------------===//


//===----------------------------------------------------------------------===//
// UniCore processors supported.
//===----------------------------------------------------------------------===//
class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"unicore32", []>;

//===----------------------------------------------------------------------===//
// Instruction Descriptions
//===----------------------------------------------------------------------===//

def UniCoreInstrInfo : InstrInfo;

//===----------------------------------------------------------------------===//
// Target Declaration
//===----------------------------------------------------------------------===//

def UniCore : Target {
  let InstructionSet = UniCoreInstrInfo;
}
