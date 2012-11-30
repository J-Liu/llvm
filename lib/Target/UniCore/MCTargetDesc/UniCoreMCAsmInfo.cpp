//===-- UniCoreMCAsmInfo.cpp - UniCore asm properties ---------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declarations of the UniCoreMCAsmInfo properties.
//
//===----------------------------------------------------------------------===//

#include "UniCoreMCAsmInfo.h"
#include "llvm/ADT/StringRef.h"
using namespace llvm;

void UniCoreMCAsmInfo::anchor() { }

UniCoreMCAsmInfo::UniCoreMCAsmInfo(const Target &T, StringRef TT) {
}
