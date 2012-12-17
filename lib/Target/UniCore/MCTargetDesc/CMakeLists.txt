add_llvm_library(LLVMUniCoreDesc
  UniCoreMCAsmInfo.cpp
  UniCoreMCTargetDesc.cpp
  )

add_dependencies(LLVMUniCoreDesc UniCoreCommonTableGen)
