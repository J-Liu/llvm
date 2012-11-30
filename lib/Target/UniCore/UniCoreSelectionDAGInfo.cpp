//===-- UniCoreSelectionDAGInfo.cpp - UniCore SelectionDAG Info ----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the UniCoreSelectionDAGInfo class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "unicore-selectiondag-info"
#include "UniCoreTargetMachine.h"

using namespace llvm;

UniCoreSelectionDAGInfo::UniCoreSelectionDAGInfo(const UniCoreTargetMachine &TM)
  : TargetSelectionDAGInfo(TM) {
}

UniCoreSelectionDAGInfo::~UniCoreSelectionDAGInfo() {
}
