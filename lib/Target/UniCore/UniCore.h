//===-- UniCore.h - Top-level interface for UniCore -------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in
// the LLVM UniCore back-end.
//
//===----------------------------------------------------------------------===//

#ifndef TARGET_UNICORE_H
#define TARGET_UNICORE_H

#include "MCTargetDesc/UniCoreMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
  class UniCoreTargetMachine;
  class FunctionPass;
  class formatted_raw_ostream;

  FunctionPass *createUniCoreISelDag(UniCoreTargetMachine &TM,
                                     CodeGenOpt::Level OptLevel);
} // end namespace llvm;

#endif
