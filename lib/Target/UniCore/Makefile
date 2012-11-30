##===- lib/Target/UniCore/Makefile ------------------------*- Makefile -*--===##
#
#                     The LLVM Compiler Infrastructure
#
# This file is distributed under the University of Illinois Open Source
# License. See LICENSE.TXT for details.
#
##===----------------------------------------------------------------------===##
LEVEL = ../../..
LIBRARYNAME = LLVMUniCoreCodeGen
TARGET = UniCore

# Make sure that tblgen is run, first thing.
BUILT_SOURCES = UniCoreGenRegisterInfo.inc \
                UniCoreGenInstrInfo.inc \
                UniCoreGenAsmWriter.inc \
                UniCoreGenCallingConv.inc \
                UniCoreGenSubtargetInfo.inc \
                UniCoreGenDAGISel.inc		

DIRS = InstPrinter TargetInfo MCTargetDesc

include $(LEVEL)/Makefile.common
