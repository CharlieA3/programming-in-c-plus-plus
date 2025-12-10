#ifndef REGISTER_FILE
#define REGISTER_FILE

#include <cstdint>
#include "cpu_constants.hpp"

struct Register_File_Output
{
    std::uint16_t data1;
    std::uint16_t data2;
};

// using 2D array to represent registers (concept A)
class Register_File
{
public:
    void display_IO();

    Register_File_Output write_register(uint8_t readaddr1, uint8_t readaddr2, uint8_t writeaddr, uint16_t writedata, unsigned char reg[NUM_REGISTERS][CPU_WIDTH_BYTES]);

private:
    // this should be a 8 x 2 bytes piece of memory to hold the current values for the 8 registers
    unsigned char reg[NUM_REGISTERS][CPU_WIDTH_BYTES];
};

#endif