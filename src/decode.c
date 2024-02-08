//
// Created by hanyuan on 2024/2/8.
//
#include "mem.h"

const uint8_t RV32I_LUI = 0x37;
const uint8_t RV32I_AUIPC = 0x17;
const uint8_t RV32I_JAL = 0x6f;
const uint8_t RV32I_JALR = 0x67;
const uint8_t RV32I_BRANCH = 0x63;
const uint8_t RV32I_LOAD = 0x03;
const uint8_t RV32I_STORE = 0x23;
const uint8_t RV32I_ARITH_IMM = 0x13;
const uint8_t RV32I_ARITH = 0x33;
const uint8_t RV32I_ZIFENCEI_FENCE = 0x0f;
const uint8_t RV32I_ZICSR_ECALL_EBREAK = 0x73;

const uint8_t RV32A = 0x2f;

/* 返回值是对pc指针的改变量 */
void decode(uint32_t inst) {
    uint8_t opcode = inst & 0x7f;
    switch (opcode) {
        case RV32I_LUI:
            break;
    }
}

static uint32_t pow(uint32_t x, uint32_t y) {
    uint32_t ans = 1;
    for (uint32_t i = 0; i < y; i++) {
        ans *= x;
    }
    return ans;
}

static uint32_t extract(uint32_t inst, uint8_t start, uint8_t end) {
    return (inst >> start) & (pow(2, (end - start + 1)) - 1);
}

#define INST_EXT(end, begin)  extract(inst,begin,end)

static void decode_type_r(uint32_t inst, uint8_t *rd, uint8_t *funct3, uint8_t *rs1, uint8_t *rs2, uint8_t *funct7) {
    *rd = INST_EXT(11, 7);
    *funct3 = INST_EXT(14, 12);
    *rs1 = INST_EXT(19, 15);
    *rs2 = INST_EXT(24, 20);
    *funct7 = INST_EXT(31, 25);
}

static void LUI(uint32_t inst) {

}