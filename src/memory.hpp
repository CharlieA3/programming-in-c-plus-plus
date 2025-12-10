#ifndef CPU_MEMORY
#define CPU_MEMORY

#include <cstdint>
#include <cstddef>
#include <queue>
#include "cpu_constants.h"

class CPU;

class Memory // will give attributes to data memory and instruction memory
{
protected:
    int depth;
    // concept (H) here
    unsigned char *memory;

public:
    Memory(int d) : depth(d)
    {
        memory = new unsigned char[depth * CPU_WIDTH_BYTES];
    }

    virtual ~Memory()
    {
        delete[] memory;
    }

    unsigned char &at(int address, int byte)
    {
        return memory[address * CPU_WIDTH_BYTES + byte];
    }

    // allows me to override in inheriting classes, =0 makes it pure virtual so there is no implementation in base class - concept (F)
    virtual short read(unsigned short address) = 0;
    virtual void store(unsigned short address, short value) = 0;
};

class Instruction_Memory : public Memory
{
public:
    Instruction_Memory() : Memory(INSTR_MEM_SIZE) {}
    short read(unsigned short address);
    void store(unsigned short address, short value);
    void load_from_file_into_queue(const char *filename);
    size_t queue_size() const;

private:
    std::queue<std::uint16_t> instruction_q;
};

class Data_Memory : public Memory
{
public:
    Data_Memory() : Memory(DATA_MEM_SIZE) {}
    short read(unsigned short address);
    void store(unsigned short address, short value);
};

// static const int DATA_MEM_DEPTH = 1024;

#endif