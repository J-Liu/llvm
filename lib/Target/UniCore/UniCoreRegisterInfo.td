//===-- UniCoreRegisterInfo.td - UniCore Register defs -----*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the CPU0 register file
//===----------------------------------------------------------------------===//


class UniCoreGPRReg<bits<5> num, string n> : Register<n> {
  field bits<5> Num = num;
  let Namespace = "UniCore";
}

//===----------------------------------------------------------------------===//
//  Registers
//===----------------------------------------------------------------------===//

def A1    : UniCoreGPRReg< 0,  "r0">,    DwarfRegNum<[0]>;
def A2    : UniCoreGPRReg< 1,  "r1">,    DwarfRegNum<[1]>;
def A3    : UniCoreGPRReg< 2,  "r2">,    DwarfRegNum<[2]>;
def A4    : UniCoreGPRReg< 3,  "r3">,    DwarfRegNum<[3]>;
def R4    : UniCoreGPRReg< 4,  "r4">,    DwarfRegNum<[6]>;
def R5    : UniCoreGPRReg< 5,  "r5">,    DwarfRegNum<[7]>;
def R6    : UniCoreGPRReg< 6,  "r6">,    DwarfRegNum<[6]>;
def R7    : UniCoreGPRReg< 7,  "r7">,    DwarfRegNum<[7]>;
def R8    : UniCoreGPRReg< 8,  "r8">,    DwarfRegNum<[8]>;
def R9    : UniCoreGPRReg< 9,  "r9">,    DwarfRegNum<[9]>;
def R10   : UniCoreGPRReg< 10, "r10">,   DwarfRegNum<[10]>;
def R11   : UniCoreGPRReg< 11, "r11">,   DwarfRegNum<[11]>;
def R12   : UniCoreGPRReg< 12, "r12">,   DwarfRegNum<[12]>;
def R13   : UniCoreGPRReg< 13, "r13">,   DwarfRegNum<[13]>;
def R14   : UniCoreGPRReg< 14, "r14">,   DwarfRegNum<[14]>;
def R15   : UniCoreGPRReg< 15, "r15">,   DwarfRegNum<[15]>;
def R16   : UniCoreGPRReg< 16, "r16">,   DwarfRegNum<[16]>;
def R17   : UniCoreGPRReg< 17, "r17">,   DwarfRegNum<[17]>;
def R18   : UniCoreGPRReg< 18, "r18">,   DwarfRegNum<[18]>;
def R19   : UniCoreGPRReg< 19, "r19">,   DwarfRegNum<[19]>;
def R20   : UniCoreGPRReg< 20, "r20">,   DwarfRegNum<[20]>;
def R21   : UniCoreGPRReg< 21, "r21">,   DwarfRegNum<[21]>;
def R22   : UniCoreGPRReg< 22, "r22">,   DwarfRegNum<[22]>;
def R23   : UniCoreGPRReg< 23, "r23">,   DwarfRegNum<[23]>;
def R24   : UniCoreGPRReg< 24, "r24">,   DwarfRegNum<[24]>;
def SB    : UniCoreGPRReg< 25, "r25">,   DwarfRegNum<[25]>;
def SL    : UniCoreGPRReg< 26, "r26">,   DwarfRegNum<[26]>;
def FP    : UniCoreGPRReg< 27, "r27">,   DwarfRegNum<[27]>;
def IP    : UniCoreGPRReg< 28, "r28">,   DwarfRegNum<[28]>;
def SP    : UniCoreGPRReg< 29, "r29">,   DwarfRegNum<[29]>;
def LR    : UniCoreGPRReg< 30, "r30">,   DwarfRegNum<[30]>;
def PC    : UniCoreGPRReg< 31, "pc">,    DwarfRegNum<[31]>;


//===----------------------------------------------------------------------===//
// Register Classes
//===----------------------------------------------------------------------===//

def GPRRegs : RegisterClass<"UniCore", [i32], 32, (add
  // Reserved
  R16,
  // Return Values and Arguments
  A1, A2,
  // Arguments
  A3, A4,
  // Not preserved across procedure calls
  R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, IP, LR,
  // Callee save
  R17, R18, R19, R20, R21, R22, R23, R24, SB, SL, FP,
  // Reserved
  SP, PC)>;
