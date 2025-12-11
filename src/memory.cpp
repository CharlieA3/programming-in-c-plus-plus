#include <fstream>

#include "memory.hpp"

const char *errmsg_open_file = "Cannot open file";

RISCV16 Instruction_Memory::pop_instruction()
{
    if (instruction_q.empty())
    {
        throw std::runtime_error("No more instructions");
    }
    // this should copy do I can now pop
    RISCV16 instruction = instruction_q.front();
    instruction_q.pop();

    return instruction;
}

RISCV16 Instruction_Memory::read_word(int address)
{
    if (address < 0 || address >= depth)
    {
        throw std::out_of_range("Read instruction memory out of bounds");
    }
    return at(address);
}

void Instruction_Memory::store_word(int address, RISCV16 value)
{
    if (address < 0 || address >= depth)
    {
        throw std::out_of_range("Write instruction memory out of bounds");
    }
    memory[address] = value;
}

void Instruction_Memory::load_from_file_into_queue(std::string filename)
{
    std::ifstream input_file("instruction_files/" + filename + ".txt");

    if (!input_file.is_open())
    {
        throw std::runtime_error(errmsg_open_file);
    }

    std::string line;
    int line_number = 0;
    while (getline(input_file, line))
    {
        line_number++;

        if (line.length() != 4)
        {
            throw std::runtime_error("Invalid instruction length at line " + std::to_string(line_number));
        }

        for (size_t i = 0; i < line.length(); i++)
        {
            char c = line[i];
            if (!((c >= '0' && c <= '9') ||
                  (c >= 'a' && c <= 'f') ||
                  (c >= 'A' && c <= 'F')))
            {
                throw std::runtime_error("Invalid hex character at line " + std::to_string(line_number));
            }
        }

        // converts the instruction to uint16_t
        RISCV16 instruction = 0;
        for (size_t i = 0; i < 4; i++)
        {
            char c = line[i];
            int digit;

            if (c >= '0' && c <= '9')
            {
                digit = c - '0';
            }
            else if (c >= 'a' && c <= 'f')
            {
                digit = c - 'a' + 10;
            }
            else if (c >= 'A' && c <= 'F')
            {
                digit = c - 'A' + 10;
            }

            instruction = (instruction << 4) | digit;
        }
        instruction_q.push(instruction);
    }
}

RISCV16S Data_Memory::read_word(int address)
{
    if (address < 0 || address >= depth)
    {
        throw std::out_of_range("Read out of bounds");
    }
    return memory[address];
}

void Data_Memory::store_word(int address, RISCV16S value)
{
    if (address < 0 || address >= depth)
    {
        throw std::out_of_range("Write out of bounds");
    }
    memory[address] = value;
}