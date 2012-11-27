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
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_REGINFO_MC_DESC
#include "UniCoreGenRegisterInfo.inc"

using namespace llvm;

static MCRegisterInfo *createUniCoreMCRegisterInfo(StringRef TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitUniCoreMCRegisterInfo(X, UniCore::PC);
  return X;
}

extern "C" void LLVMInitializeUniCoreTargetMC() {
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheUniCoreTarget,
                                    createUniCoreMCRegisterInfo);
}
