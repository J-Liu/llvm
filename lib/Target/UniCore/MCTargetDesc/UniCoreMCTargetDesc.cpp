//===-- UniCoreMCTargetDesc.cpp - UniCore Target Descriptions -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides UniCore specific target descriptions.
//
//===----------------------------------------------------------------------===//

#include "UniCoreMCTargetDesc.h"
#include "llvm/MC/MCCodeGenInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_INSTRINFO_MC_DESC
#include "UniCoreGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "UniCoreGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "UniCoreGenRegisterInfo.inc"

using namespace llvm;

static MCInstrInfo *createUniCoreMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitUniCoreMCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createUniCoreMCRegisterInfo(StringRef TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitUniCoreMCRegisterInfo(X, UniCore::PC);
  return X;
}

static MCSubtargetInfo *createUniCoreMCSubtargetInfo(StringRef TT, StringRef CPU,
                                                      StringRef FS) {
  MCSubtargetInfo *X = new MCSubtargetInfo();
  InitUniCoreMCSubtargetInfo(X, TT, CPU, FS);
  return X;
}

extern "C" void LLVMInitializeUniCoreTargetMC() {
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheUniCoreTarget, createUniCoreMCInstrInfo);

  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheUniCoreTarget,
                                    createUniCoreMCRegisterInfo);

  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheUniCoreTarget,
                                          createUniCoreMCSubtargetInfo);
}
