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
#include "llvm/Function.h"
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
