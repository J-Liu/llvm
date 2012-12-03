//===- UniCoreMachineFuctionInfo.h - UniCore machine func info -*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares UniCore-specific per-machine-function information.
//
//===----------------------------------------------------------------------===//

#ifndef OPENRISCMACHINEFUNCTIONINFO_H
#define OPENRISCMACHINEFUNCTIONINFO_H

#include "llvm/CodeGen/MachineFunction.h"

namespace llvm {

/// UniCoreMachineFunctionInfo - This class is derived from MachineFunction and
/// contains private UniCore target-specific information for each MachineFunction.
class UniCoreMachineFunctionInfo : public MachineFunctionInfo {
  virtual void anchor();
public:
  UniCoreMachineFunctionInfo() {}

  explicit UniCoreMachineFunctionInfo(MachineFunction &MF) {}
};

} // End llvm namespace

#endif
