//===-- UniCoreRegisterInfo.cpp - UniCore Register Information ------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the UniCore implementation of the TargetRegisterInfo
// class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "unicore-reg-info"

#include "UniCoreRegisterInfo.h"
#include "UniCore.h"
#include "UniCoreTargetMachine.h"
#include "llvm/IR/Function.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/ADT/BitVector.h"
#include "llvm/Support/ErrorHandling.h"

#define GET_REGINFO_TARGET_DESC
#include "UniCoreGenRegisterInfo.inc"

using namespace llvm;

UniCoreRegisterInfo::UniCoreRegisterInfo(UniCoreTargetMachine &tm,
                                         const TargetInstrInfo &tii)
  : UniCoreGenRegisterInfo(UniCore::PC), TM(tm), TII(tii) {
}

const uint16_t *
UniCoreRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  return CSR_SaveList;
}

BitVector
UniCoreRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());

  Reserved.set(UniCore::R16);
  Reserved.set(UniCore::SP);
  Reserved.set(UniCore::PC);

  return Reserved;
}

void
UniCoreRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                         int SPAdj, RegScavenger *RS) const {}

unsigned
UniCoreRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  return UniCore::SP;
}
