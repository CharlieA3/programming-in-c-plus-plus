#include "register_file.hpp"

Register_File_Output Register_File::read_two(uint8_t readaddr1, uint8_t readaddr2)
{
    if (readaddr1 >= NUM_REGISTERS || readaddr2 >= NUM_REGISTERS)
    {
        throw std::out_of_range("Register address invalid");
    }

    Register_File_Output output;
    // extend to 16 bit
    output.data1 = reg[readaddr1][0] | (reg[readaddr1][1] << 8);
    output.data2 = reg[readaddr2][0] | (reg[readaddr2][1] << 8);

    return output;
}

void Register_File::write(uint8_t writeaddr, RISCV16S writedata)
{
    if (writeaddr >= NUM_REGISTERS)
    {
        throw std::out_of_range("Register address invalid");
    }

    reg[writeaddr][0] = writedata & 0xFF;
    reg[writeaddr][1] = (writedata >> 8) & 0xFF;
}

uint16_t Register_File::read(uint8_t addr)
{
    if (addr >= NUM_REGISTERS)
    {
        throw std::out_of_range("Register address invalid");
    }

    return reg[addr][0] | (reg[addr][1] << 8);
}