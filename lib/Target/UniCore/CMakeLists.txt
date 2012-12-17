set(LLVM_TARGET_DEFINITIONS UniCore.td)

tablegen(LLVM UniCoreGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM UniCoreGenInstrInfo.inc -gen-instr-info)

#tablegen(LLVM UniCoreGenAsmWriter.inc -gen-asm-writer)
#tablegen(LLVM UniCoreGenAsmMatcher.inc -gen-asm-matcher)

#tablegen(LLVM UniCoreGenCodeEmitter.inc -gen-emitter)
#tablegen(LLVM UniCoreGenMCCodeEmitter.inc -gen-emitter -mc-emitter)

tablegen(LLVM UniCoreGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM UniCoreGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM UniCoreGenCallingConv.inc -gen-callingconv)
tablegen(LLVM UniCoreGenSubtargetInfo.inc -gen-subtarget)

#tablegen(LLVM UniCoreGenDisassemblerTables.inc -gen-disassembler)
#tablegen(LLVM UniCoreGenEDInfo.inc -gen-enhanced-disassembly-info)
add_public_tablegen_target(UniCoreCommonTableGen)

add_llvm_target(UniCoreCodeGen
#  UniCoreDelaySlotFiller.cpp
  UniCoreISelDAGToDAG.cpp
  UniCoreISelLowering.cpp
  UniCoreInstrInfo.cpp
  UniCoreFrameLowering.cpp
  UniCoreMachineFunctionInfo.cpp
  UniCoreRegisterInfo.cpp
  UniCoreSubtarget.cpp
  UniCoreTargetMachine.cpp
  UniCoreSelectionDAGInfo.cpp
  UniCoreAsmPrinter.cpp
  UniCoreMCInstLower.cpp
  UniCoreTargetObjectFile.cpp
  )

add_subdirectory(InstPrinter)
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
