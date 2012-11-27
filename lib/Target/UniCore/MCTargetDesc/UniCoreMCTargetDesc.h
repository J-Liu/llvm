//===-- UniCoreMCTargetDesc.h - UniCore Target Descriptions -----*- C++ -*-===//
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

#ifndef UNICOREMCTARGETDESC_H
#define UNICOREMCTARGETDESC_H

#include "llvm/Support/DataTypes.h"

namespace llvm {
class Target;

extern Target TheUniCoreTarget;
} // End llvm namespace

// Defines symbolic names for UniCore registers.
// This defines a mapping from register name to register number.
#define GET_REGINFO_ENUM
#include "UniCoreGenRegisterInfo.inc"

// Defines symbolic names for the UniCore instructions.
#define GET_INSTRINFO_ENUM
#include "UniCoreGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "UniCoreGenSubtargetInfo.inc"

#endif
