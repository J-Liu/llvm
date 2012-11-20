//===-- UniCoreTargetInfo.cpp - UniCore Target Implementation -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "UniCore.h"
#include "llvm/Module.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

Target llvm::TheUniCoreTarget;

extern "C" void LLVMInitializeUniCoreTargetInfo() {
  RegisterTarget<Triple::unicore32> X(TheUniCoreTarget, "unicore32", "UniCore");
}
