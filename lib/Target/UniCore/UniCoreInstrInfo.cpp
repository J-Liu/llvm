//===-- UniCoreInstrInfo.cpp - UniCore Instruction Information ------------===//
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

#include "UniCoreInstrInfo.h"
#include "UniCore.h"
#include "UniCoreTargetMachine.h"
#include "llvm/Function.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_INSTRINFO_CTOR
#include "UniCoreGenInstrInfo.inc"

using namespace llvm;

UniCoreInstrInfo::UniCoreInstrInfo(UniCoreTargetMachine &tm)
  : UniCoreGenInstrInfo(),
    RI(tm, *this), TM(tm) {}

#if 0
void UniCoreInstrInfo::copyPhysReg(MachineBasicBlock &MBB,
                                    MachineBasicBlock::iterator I, DebugLoc DL,
                                    unsigned DestReg, unsigned SrcReg,
                                    bool KillSrc) const {
  unsigned Opc;
  if (UniCore::GR32RegClass.contains(DestReg, SrcReg))
    Opc = UniCore::OR32rr;
  else
    llvm_unreachable("Impossible reg-to-reg copy");

  BuildMI(MBB, I, DL, get(Opc), DestReg)
    .addReg(SrcReg, getKillRegState(KillSrc))
    .addReg(SrcReg, getKillRegState(KillSrc));
}
#endif
