//===-- UniCoreCallingConv.td - Calling Conv. for UniCore --*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for UniCore architecture.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// UniCore Return Value Calling Convention
//===----------------------------------------------------------------------===//
def RetCC_UniCore : CallingConv<[
  // i32 are returned in registers A1, A2
  CCIfType<[i32], CCAssignToReg<[A1, A1]>>
]>;

//===----------------------------------------------------------------------===//
// UniCore Argument Calling Conventions
//===----------------------------------------------------------------------===//
def CC_UniCore : CallingConv<[
  // Promote i8 arguments to i32.
  CCIfType<[i8], CCPromoteToType<i32>>,
  // Promote i8 arguments to i32.
  CCIfType<[i16], CCPromoteToType<i32>>,

  // The first 4 integer arguments of non-varargs functions are passed in
  // integer registers.
  CCIfNotVarArg<CCIfType<[i32], CCAssignToReg<[A1, A2, A3, A4]>>>,

  // Integer values get stored in stack slots that are 4 bytes in
  // size and 4-byte aligned.
  CCIfType<[i32], CCAssignToStack<4, 4>>
]>;

//===----------------------------------------------------------------------===//
// Callee-saved register lists.
//===----------------------------------------------------------------------===//

def CSR: CalleeSavedRegs<(add R17, R18, R19, R20, R21, R22, R23, R24, SB, SL, FP, IP, SP, LR)>;
