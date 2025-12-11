#ifndef REGISTER_FILE
#define REGISTER_FILE

#include <cstdint>
#include <iostream>
#include <iomanip>
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
    void display()
    {
        std::cout << "registers:" << std::endl;
        for (int i = 0; i < NUM_REGISTERS; i++)
        {
            // Combine bytes into 16-bit value
            uint16_t value = reg[i][0] | (reg[i][1] << 8);

            std::cout << "R" << i << ": 0x"
                      << std::hex << std::setw(4) << std::setfill('0') << value
                      << " (dec: " << std::dec << value << ")" << std::endl;
        }
        std::cout << std::endl
                  << std::endl
                  << std::endl;
    }

private:
    unsigned char reg[NUM_REGISTERS][CPU_WIDTH_BYTES];
};

#endif