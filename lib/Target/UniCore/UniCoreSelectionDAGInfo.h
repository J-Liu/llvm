//==-- UniCoreSelectionDAGInfo.h - UniCore SelectionDAG Info ---*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the UniCore subclass for TargetSelectionDAGInfo.
//
//===----------------------------------------------------------------------===//

#ifndef UNICORESELECTIONDAGINFO_H
#define UNICORESELECTIONDAGINFO_H

#include "llvm/Target/TargetSelectionDAGInfo.h"

namespace llvm {

class UniCoreTargetMachine;

class UniCoreSelectionDAGInfo : public TargetSelectionDAGInfo {
public:
  explicit UniCoreSelectionDAGInfo(const UniCoreTargetMachine &TM);
  ~UniCoreSelectionDAGInfo();
};

}

#endif // UNICORESELECTIONDAGINFO_H
