//===- UniCoreTargetMachine.h - Define TargetMachine for UniCore -*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the UniCore specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef UNICORE_TARGETMACHINE_H
#define UNICORE_TARGETMACHINE_H

#include "UniCoreRegisterInfo.h"
#include "llvm/DataLayout.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
  class formatted_raw_ostream;

  class UniCoreTargetMachine : public LLVMTargetMachine {
  const DataLayout          DL;        // Calculates type size & alignment

  public:
    UniCoreTargetMachine(const Target &T, StringRef TT,
                        StringRef CPU, StringRef FS,
                        const TargetOptions &Options,
                        Reloc::Model RM, CodeModel::Model CM,
                        CodeGenOpt::Level OL);

    virtual const DataLayout *getDataLayout() const     { return &DL;}
  };
} // End llvm namespace

#endif
