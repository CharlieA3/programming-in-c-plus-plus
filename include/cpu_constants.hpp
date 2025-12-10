#ifndef CPU_CONSTANTS
#define CPU_CONSTANTS

#include <cstdint>

// global RISCV CPU parameters
const int CPU_WIDTH = 16;
const int CPU_WIDTH_BYTES = 2;

const int INSTR_WORDS_HELD = 32;
const int DATA_WORDS_HELD = 64;
const int NUM_REGISTERS = 8; // depth of register file
// could use these but number of instruction held is better I think
const int INSTR_MEM_SIZE = 512;
const int DATA_MEM_SIZE = 1024;

// can be expanded - could also do namespace here for different cpus in the future??
typedef std::int16_t RISCV16S;
typedef std::uint16_t RISCV16;

#endif