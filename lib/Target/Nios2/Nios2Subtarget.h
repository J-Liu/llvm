//===-- Nios2Subtarget.h - Define Subtarget for the Nios2 ------*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Nios2 specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef NIOS2SUBTARGET_H
#define NIOS2SUBTARGET_H

#include "llvm/Target/TargetSubtargetInfo.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/MC/MCInstrItineraries.h"
#include <string>

#define GET_SUBTARGETINFO_HEADER
#include "Nios2GenSubtargetInfo.inc"

namespace llvm {
class StringRef;

class Nios2Subtarget : public Nios2GenSubtargetInfo {
  virtual void anchor();

public:
  // NOTE: O64 will not be supported.
  enum Nios2ABIEnum {
    UnknownABI, O32, N32, N64, EABI
  };

protected:

  enum Nios2ArchEnum {
    Nios2Std
  };

  // Nios2 architecture version
  Nios2ArchEnum Nios2ArchVersion;

  // Nios2 supported ABIs
  Nios2ABIEnum Nios2ABI;

  // IsLittle - The target is Little Endian
  bool IsLittle;

  // isLinux - Target system is Linux. Is false we consider ELFOS for now.
  bool IsLinux;

  // UseSmallSection - Small section is used.
  bool UseSmallSection;

  // Features
  bool HasHWMul;
  bool HasHWDiv;

  InstrItineraryData InstrItins;

  /// TargetTriple - What processor and OS we're targeting.
  Triple TargetTriple;

  /// Options passed via command line that could influence the target
  const TargetOptions &Options;


private:
  void initializeEnvironment();
  void resetSubtargetFeatures(StringRef CPU, StringRef FS);

public:
  /// \brief Reset the features for the Nios2 target.
  virtual void resetSubtargetFeatures(const MachineFunction *MF);

  virtual bool enablePostRAScheduler(CodeGenOpt::Level OptLevel,
                                     AntiDepBreakMode& Mode,
                                     RegClassVector& CriticalPathRCs) const;

  unsigned getTargetABI() const { return Nios2ABI; }

  /// This constructor initializes the data members to match that
  /// of the specified triple.
  Nios2Subtarget(const std::string &TT, const std::string &CPU,
                const std::string &FS, const TargetOptions &Options);

  /// ParseSubtargetFeatures - Parses features string setting specified
  /// subtarget options.  Definition of function is auto generated by tblgen.
  void ParseSubtargetFeatures(StringRef CPU, StringRef FS);

  bool isLittle() const { return IsLittle; }
  bool isLinux() const { return IsLinux; }
  bool useSmallSection() const { return UseSmallSection; }

  // Specific features
  bool hasHWMul() const { return HasHWMul; }
  bool hasHWDiv() const { return HasHWDiv; }

  const Triple &getTargetTriple() const { return TargetTriple; }
};
} // End llvm namespace

#endif
