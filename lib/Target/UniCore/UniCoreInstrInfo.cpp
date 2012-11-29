//===-- UniCoreInstrInfo.cpp - UniCore Instruction Information -----------===//
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
