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
                Cpu0GenDisassemblerTables.inc \
                Cpu0GenCodeEmitter.inc \
                Cpu0GenMCCodeEmitter.inc \
                Cpu0GenAsmWriter.inc \
                Cpu0GenDAGISel.inc \
                Cpu0GenCallingConv.inc \
                Cpu0GenSubtargetInfo.inc

DIRS = Disassembler InstPrinter TargetInfo MCTargetDesc

include $(LEVEL)/Makefile.common
