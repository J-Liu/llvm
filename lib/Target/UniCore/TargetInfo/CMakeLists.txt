include_directories( ${CMAKE_CURRENT_BINARY_DIR}/.. ${CMAKE_CURRENT_SOURCE_DIR}/.. )

add_llvm_library(LLVMUniCoreInfo
  UniCoreTargetInfo.cpp
  )

add_dependencies(LLVMUniCoreInfo UniCoreCommonTableGen)
