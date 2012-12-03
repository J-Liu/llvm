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
#include "llvm/PassManager.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/MC/MCAsmInfo.h"
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
    InstrInfo(*this), TLInfo(*this), TSInfo(*this),
    FrameLowering(Subtarget)
{
}

namespace {
/// UniCore Code Generator Pass Configuration Options.
class UniCorePassConfig : public TargetPassConfig {
public:
  UniCorePassConfig(UniCoreTargetMachine *TM, PassManagerBase &PM)
    : TargetPassConfig(TM, PM) {}

  UniCoreTargetMachine &getUniCoreTargetMachine() const {
    return getTM<UniCoreTargetMachine>();
  }

  virtual bool addInstSelector();
};
} // namespace

TargetPassConfig *UniCoreTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new UniCorePassConfig(this, PM);
}

bool UniCorePassConfig::addInstSelector() {
  // Install an instruction selector.
  addPass(createUniCoreISelDag(getUniCoreTargetMachine(), getOptLevel()));
  return false;
}
