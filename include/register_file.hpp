#ifndef REGISTER_FILE
#define REGISTER_FILE

#include <cstdint>
#include <stdexcept>

#include "cpu_constants.hpp"

struct Register_File_Output
{
    RISCV16S data1;
    RISCV16S data2;
};

// using 2D array to represent registers (concept A)
class Register_File
{
public:
    Register_File_Output read_two(uint8_t readaddr1, uint8_t readaddr2);
    void write(uint8_t writeaddr, RISCV16S writedata);
    uint16_t read(uint8_t addr);

private:
    unsigned char reg[NUM_REGISTERS][CPU_WIDTH_BYTES];
};

#endif