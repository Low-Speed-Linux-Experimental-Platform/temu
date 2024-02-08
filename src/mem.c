//
// Created by hanyuan on 2024/2/8.
//
#include "mem.h"

uint32_t registers[32];
uint32_t program_counter = 0;

static uint8_t rom_ptr[ROM_SIZE];
static uint8_t ram_ptr[RAM_SIZE];

uint8_t *mem_get_rom_ptr() {
    return rom_ptr;
}

uint8_t mem_read_b(uint32_t addr) {
    if (addr >= ROM_START_ADDR && addr < ROM_START_ADDR + ROM_SIZE) {
        return rom_ptr[addr - ROM_START_ADDR];
    } else if (addr >= RAM_START_ADDR && addr < RAM_START_ADDR + RAM_SIZE) {
        return ram_ptr[addr - RAM_START_ADDR];
    } else {
        /* Illegal memory access interrupt */
        return 0xff;
    }
}

uint16_t mem_read_h(uint32_t addr) {
    if (addr >= ROM_START_ADDR && addr + 2 < ROM_START_ADDR + ROM_SIZE) {
        return rom_ptr[addr - ROM_START_ADDR] | (rom_ptr[addr - ROM_START_ADDR + 1] << 8);
    } else if (addr >= RAM_START_ADDR && +2 < RAM_START_ADDR + RAM_SIZE) {
        return ram_ptr[addr - RAM_START_ADDR] | (ram_ptr[addr - RAM_START_ADDR + 1] << 8);
    } else {
        /* Illegal memory access interrupt */
        return 0xffff;
    }
}

uint32_t mem_read_w(uint32_t addr) {
    if (addr >= ROM_START_ADDR && addr + 4 < ROM_START_ADDR + ROM_SIZE) {
        return
                rom_ptr[addr - ROM_START_ADDR] |
                (rom_ptr[addr - ROM_START_ADDR + 1] << 8) |
                (rom_ptr[addr - ROM_START_ADDR + 2] << 16) |
                (rom_ptr[addr - ROM_START_ADDR + 3] << 24);
    } else if (addr >= RAM_START_ADDR && addr + 4 < RAM_START_ADDR + RAM_SIZE) {
        return
                ram_ptr[addr - RAM_START_ADDR] |
                (ram_ptr[addr - RAM_START_ADDR + 1] << 8) |
                (ram_ptr[addr - RAM_START_ADDR + 2] << 16) |
                (ram_ptr[addr - RAM_START_ADDR + 3] << 24);
    } else {
        /* Illegal memory access interrupt */
        return 0xffffffff;
    }
}