//===-- UniCoreMCAsmInfo.h - UniCore asm properties ------------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the UniCoreMCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef UNICORETARGETASMINFO_H
#define UNICORETARGETASMINFO_H

#include "llvm/MC/MCAsmInfo.h"

namespace llvm {
  class StringRef;
  class Target;

  class UniCoreMCAsmInfo : public MCAsmInfo {
    virtual void anchor();
  public:
    explicit UniCoreMCAsmInfo(const Target &T, StringRef TT);
  };

} // namespace llvm

#endif
