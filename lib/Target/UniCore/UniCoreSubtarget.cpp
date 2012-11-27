//===-- UniCoreSubtarget.cpp - UniCore Subtarget Information --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the UniCore specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "UniCoreSubtarget.h"
#include "UniCore.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "UniCoreGenSubtargetInfo.inc"

using namespace llvm;

void UniCoreSubtarget::anchor() { }

UniCoreSubtarget::UniCoreSubtarget(const std::string &TT,
                                   const std::string &CPU,
                                   const std::string &FS) :
  UniCoreGenSubtargetInfo(TT, CPU, FS) {
  std::string CPUName = "unicore32";

  // Parse features string.
  ParseSubtargetFeatures(CPUName, FS);

  UniCoreABI = O32;
  UniCoreArchVersion = UniCore32;  
}
