//===-- UniCoreInstrInfo.h - UniCore Instruction Information ---*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the UniCore implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_UNICOREINSTRINFO_H
#define LLVM_TARGET_UNICOREINSTRINFO_H

#include "UniCoreRegisterInfo.h"
#include "llvm/Target/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "UniCoreGenInstrInfo.inc"

namespace llvm {

class UniCoreTargetMachine;

class UniCoreInstrInfo : public UniCoreGenInstrInfo {
  const UniCoreRegisterInfo RI;
  UniCoreTargetMachine &TM;
public:
  explicit UniCoreInstrInfo(UniCoreTargetMachine &TM);

  /// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
  /// such, whenever a client has an instance of instruction info, it should
  /// always be able to get register info as well (through this method).
  ///
  virtual const TargetRegisterInfo &getRegisterInfo() const { return RI; }
#if 0
  void copyPhysReg(MachineBasicBlock &MBB,
                   MachineBasicBlock::iterator I, DebugLoc DL,
                   unsigned DestReg, unsigned SrcReg,
                   bool KillSrc) const;
#endif
};

}

#endif
