#ifndef CPU_MEMORY
#define CPU_MEMORY

#include <cstdint>
#include <cstddef>
#include <queue>
#include <string>
#include <stdexcept>
#include "cpu_constants.hpp"

class Memory // will give attributes to data memory and instruction memory
{
protected:
    int depth;
    // concept (H) here
    RISCV16 *memory;

public:
    Memory(int words) : depth(words)
    {
        memory = new RISCV16[words];
    }

    virtual ~Memory()
    {
        delete[] memory;
    }

    // word addressable, not byte addressable
    RISCV16 &at(int address)
    {
        return memory[address];
    }

    // allows me to override in inheriting classes, =0 makes it pure virtual so there is no implementation in base class - concept (F)
    virtual RISCV16 read_word(int address) = 0;
    virtual void store_word(int address, RISCV16 value) = 0;
};

// instruction memory holds instructions from a file given to the program
// the instruction memory is 512 bytes currently so it can hold 32 instructions (for testing)
class Instruction_Memory : public Memory
{
public:
    Instruction_Memory() : Memory(INSTR_WORDS_HELD) {}
    // returns 16 bit value from the given address
    RISCV16 read_word(int address);
    void store_word(int address, RISCV16 value);
    void load_from_file_into_queue(std::string filename);

private:
    std::queue<std::uint16_t> instruction_q;
};

class Data_Memory : public Memory
{
public:
    Data_Memory() : Memory(DATA_WORDS_HELD) {}
    RISCV16 read_word(int address);
    void store_word(int address, RISCV16 value);
};

#endif