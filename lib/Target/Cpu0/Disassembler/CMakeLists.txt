add_llvm_library(LLVMCpu0Disassembler
  Cpu0Disassembler.cpp
  )

# workaround for hanging compilation on MSVC9 and 10
if( MSVC_VERSION EQUAL 1400 OR MSVC_VERSION EQUAL 1500 OR MSVC_VERSION EQUAL 1600 )
set_property(
  SOURCE Cpu0Disassembler.cpp
  PROPERTY COMPILE_FLAGS "/Od"
  )
endif()
