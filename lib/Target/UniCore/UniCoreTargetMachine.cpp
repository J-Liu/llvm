//===-- UniCoreTargetMachine.cpp - Define TargetMachine for UniCore -------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Implements the info about UniCore target spec.
//
//===----------------------------------------------------------------------===//

#include "UniCoreTargetMachine.h"
#include "UniCore.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

extern "C" void LLVMInitializeUniCoreTarget() {
  // Register the target.
  RegisterTargetMachine<UniCoreTargetMachine> X(TheUniCoreTarget);
}

UniCoreTargetMachine::
UniCoreTargetMachine(const Target &T, StringRef TT,
                     StringRef CPU, StringRef FS, const TargetOptions &Options,
                     Reloc::Model RM, CodeModel::Model CM,
                     CodeGenOpt::Level OL)
  : LLVMTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL),
    Subtarget(TT, CPU, FS),
    DL("e-p:32:32:32-i8:8:8-i16:16:16-i32:32:32-n32"),
    InstrInfo(*this)
{
}
