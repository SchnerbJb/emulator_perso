#ifndef EMULATOR_H

#define EMULATOR_H

#define MASK_1BIT 0b00000001
#define MASK_2BIT 0b00000011
#define MASK_3BIT 0b00000111
#define MASK_4BIT 0b00001111
#define MASK_5BIT 0b00011111
#define MASK_6BIT 0b00111111
#define MASK_7BIT 0b01111111
#define MASK_8BIT 0b11111111

#define LDH_MSB 0xFF

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "utils.h"

enum CPU_REGISTERS8
{
    B,
    C,
    D,
    E,
    H,
    L,
    IHL,
    A
};

enum CPU_REGISTERS16
{
    BC,
    DE,
    HL,
    SP,
};

enum REGISTERMEM
{
    HLI = 2,
    HLD,
};

enum FLAGS
{
    NZ,
    Z,
    NC,
    CA
};

typedef struct HeaderData
{
    char nintendoLogo[48];
    char title[16];
    uint16_t newlicensecode;
    uint8_t sgbFlag;
    uint8_t cartridgeType;
    uint8_t romsize;
    uint8_t ramsize;
    uint8_t destcode;
    uint8_t oldlicenstcode;
    uint8_t romversion;
    uint8_t headercheksum;
    uint16_t globalchecksum;

} HeaderData;

typedef struct CartridgeData
{
    HeaderData *hd;
} CartridgeData;

typedef struct
{
    uint16_t *value;
    int count;
    int capacity;
} dynamic_array16;

typedef struct Emulator
{
    CartridgeData *cdptr;
    uint8_t acc, fz, fn, fc, fh, b, c, d, e, h, l;
    uint16_t pc, sp;
    uint8_t *memory;
    uint8_t ime;
    uint8_t ime_next;
} Emulator;

typedef void (*arithmeticptr)(Emulator *, uint8_t);

void tick(Emulator *eptr);
Emulator *initEmulator();
void update(Emulator *eptr, clock_t delta_time);
int loadRom(Emulator *eptr, char *pathname);

// access
uint8_t readNext(Emulator *eptr);
uint8_t at(Emulator *eptr, uint16_t address);
void write(Emulator *eptr, uint16_t address, uint8_t value);

void readNextInstruction(Emulator *eptr);
void readNextCBInstruction(Emulator *eptr);
void block0(Emulator *eptr, uint8_t opcode);
void block1(Emulator *eptr, uint8_t opcode);
void block2(Emulator *eptr, uint8_t opcode);
void block3(Emulator *eptr, uint8_t opcode);

void print_state(Emulator *eptr);

// instruction Specific
uint8_t getRegister8(Emulator *eptr, enum CPU_REGISTERS8 reg);
void setRegister8(Emulator *eptr, enum CPU_REGISTERS8 reg, uint8_t value);
uint16_t getRegister16(Emulator *eptr, enum CPU_REGISTERS16 reg);
void setRegister16(Emulator *eptr, enum CPU_REGISTERS16 reg, uint16_t value);
uint8_t getFlag(Emulator *eptr, enum FLAGS f);

void load16memA(Emulator *eptr, enum CPU_REGISTERS16 reg);
void loadA16mem(Emulator *eptr, enum CPU_REGISTERS16 reg);

void add8(Emulator *eptr, uint8_t value);
void sub8(Emulator *eptr, uint8_t value);
void adc8(Emulator *eptr, uint8_t value);
void sbc8(Emulator *eptr, uint8_t value);
void and8(Emulator *eptr, uint8_t value);
void xor8(Emulator *eptr, uint8_t value);
void or8(Emulator *eptr, uint8_t value);
void cp8(Emulator *eptr, uint8_t value);

void inc8(Emulator *eptr, enum CPU_REGISTERS8 reg);
void dec8(Emulator *eptr, enum CPU_REGISTERS8 reg);

void add16(Emulator *eptr, enum CPU_REGISTERS16 reg);

void addsp(Emulator *eptr, uint8_t value);
void loadspe(Emulator *eptr, uint8_t value);
void jmp(Emulator *eptr, uint16_t address);
void jr(Emulator *eptr, int8_t offset);
void ret(Emulator *eptr);
void reti(Emulator *eptr);
void rst(Emulator *eptr, uint8_t target);
void push(Emulator *eptr, enum CPU_REGISTERS16 reg);
void pop(Emulator *eptr, enum CPU_REGISTERS16 reg);
void call(Emulator *eptr, uint16_t address);
void ret(Emulator *eptr);
void reti(Emulator *eptr);
void noop(Emulator *eptr);
void stop(Emulator *eptr);
void scf(Emulator *eptr);
void daa(Emulator *eptr);
void halt(Emulator *eptr);
void di(Emulator *eptr);
void ei(Emulator *eptr);

void rlca(Emulator *eptr);
void rrca(Emulator *eptr);
void rla(Emulator *eptr);
void rra(Emulator *eptr);
void daa(Emulator *eptr);
void cpl(Emulator *eptr);
void scf(Emulator *eptr);
void ccf(Emulator *eptr);

void rlc(Emulator *eptr, enum CPU_REGISTERS8 reg);
void rrc(Emulator *eptr, enum CPU_REGISTERS8 reg);
void rl(Emulator *eptr, enum CPU_REGISTERS8 reg);
void rr(Emulator *eptr, enum CPU_REGISTERS8 reg);
void sla(Emulator *eptr, enum CPU_REGISTERS8 reg);
void sra(Emulator *eptr, enum CPU_REGISTERS8 reg);
void swap(Emulator *eptr, enum CPU_REGISTERS8 reg);
void srl(Emulator *eptr, enum CPU_REGISTERS8 reg);

void bit(Emulator *eptr, uint8_t index, enum CPU_REGISTERS8 reg);
void res(Emulator *eptr, uint8_t index, enum CPU_REGISTERS8 reg);
void set(Emulator *eptr, uint8_t index, enum CPU_REGISTERS8 reg);

#endif