//===- UniCoreRegisterInfo.h - UniCore Register Information Impl -*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the UniCore implementation of the MRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_UNICOREREGISTERINFO_H
#define LLVM_TARGET_UNICOREREGISTERINFO_H

#include "llvm/Target/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "UniCoreGenRegisterInfo.inc"

namespace llvm {

class TargetInstrInfo;
class UniCoreTargetMachine;

struct UniCoreRegisterInfo : public UniCoreGenRegisterInfo {
private:
  UniCoreTargetMachine &TM;
  const TargetInstrInfo &TII;
public:
  UniCoreRegisterInfo(UniCoreTargetMachine &tm, const TargetInstrInfo &tii);

  const uint16_t *getCalleeSavedRegs(const MachineFunction *MF = 0) const;

  BitVector getReservedRegs(const MachineFunction &MF) const;

  void eliminateFrameIndex(MachineBasicBlock::iterator II,
                           int SPAdj, RegScavenger *RS = NULL) const;

  unsigned getFrameRegister(const MachineFunction &MF) const;
};

} // end namespace llvm

#endif // LLVM_TARGET_UNICOREREGISTERINFO_H
