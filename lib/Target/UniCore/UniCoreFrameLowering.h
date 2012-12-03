//- UniCoreFrameLowering.h - Define frame lowering for UniCore --*- C++ -*--//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//
//
//===----------------------------------------------------------------------===//

#ifndef UNICORE_FRAMEINFO_H
#define UNICORE_FRAMEINFO_H

#include "UniCore.h"
#include "UniCoreSubtarget.h"
#include "llvm/Target/TargetFrameLowering.h"

namespace llvm {
  class UniCoreSubtarget;

class UniCoreFrameLowering : public TargetFrameLowering {
protected:
  const UniCoreSubtarget &STI;

public:
  explicit UniCoreFrameLowering(const UniCoreSubtarget &sti)
    : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, 8, 0), STI(sti) {
  }

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  void emitPrologue(MachineFunction &MF) const;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const;

  bool hasFP(const MachineFunction &MF) const;
};

} // End llvm namespace

#endif
