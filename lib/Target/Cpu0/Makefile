##===- lib/Target/Cpu0/Makefile ----------------------------*- Makefile -*-===##
#
#                     The LLVM Compiler Infrastructure
#
# This file is distributed under the University of Illinois Open Source
# License. See LICENSE.TXT for details.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../..
LIBRARYNAME = LLVMCpu0CodeGen
TARGET = Cpu0

# Make sure that tblgen is run, first thing.
BUILT_SOURCES = Cpu0GenRegisterInfo.inc \
                Cpu0GenInstrInfo.inc \
                Cpu0GenSubtargetInfo.inc

DIRS = TargetInfo MCTargetDesc

include $(LEVEL)/Makefile.common
