#ifndef SC_CPU
#define SC_CPU

#include <cstdint>
#include <memory>

#include "alu.hpp"
#include "memory.hpp"
#include "register_file.hpp"
#include "cpu_constants.hpp"

// values used by instructions
struct RISCV16_Mapped
{
    // registers - 3 bits used
    uint8_t rs1;
    uint8_t rs2;
    uint8_t rd;
    uint8_t immediate; // [6:0]
    uint8_t nzimm;     // [5:0]
    uint16_t offset;   // [8:0]
    uint8_t opcode;    // [3:0]

    // takes an instruction and maps it to the proper values based on my condensed instruction set
    static RISCV16_Mapped map_inst(uint16_t instruction);
};

struct RISCV16_Decoded
{
    // toggles - for enabling or disabling muxs and writing power
    bool reg_write;
    bool reg_dst;
    bool alu_src_1;
    bool alu_src_2;
    bool mem_write;
    bool mem_to_reg;
    bool reg_src;

    // immediate value [15:0] - use as a value for alternate instruction or
    uint16_t imm_instruction;

    // opcode [3:0] - tells the cpu what operation to perform
    uint8_t opcode;

    // takes some of the mapped values and outputs all control signals dependant on the opcode
    static RISCV16_Decoded decode(uint16_t instruction);
};

template <typename T>
T multiplexer(T input1, T input2, bool control)
{
    return (control) ? input2 : input1;
}

class CPU
{
public:
    CPU()
    {
        inst_mem_ptr = std::make_unique<Instruction_Memory>();
        mapper_ptr = std::make_unique<RISCV16_Mapped>();
        inst_dec_ptr = std::make_unique<RISCV16_Decoded>();
        reg_file_ptr = std::make_unique<Register_File>();
        alu_ptr = std::make_unique<ALU<RISCV16S>>();
    }

    // performs next clock cycle - increments PC or branches to next instruction
    void clock();

private:
    // modular-ish cpu components
    std::unique_ptr<Instruction_Memory> inst_mem_ptr;
    std::unique_ptr<RISCV16_Mapped> mapper_ptr;
    std::unique_ptr<RISCV16_Decoded> inst_dec_ptr;
    std::unique_ptr<Register_File> reg_file_ptr;
    std::unique_ptr<ALU<RISCV16S>> alu_ptr;
    std::unique_ptr<Data_Memory> data_mem_ptr;
    // can take in any inputs (template function), returning the appropriate one depending on the opcode which allows
    // std::unique_ptr<Multiplexer> mux;

    // tracks which instruction the cpu is about to execute
    int program_counter;

    // instructions - user instruction is what the program counter is tracking, immediate instruction is a value used within instructions depending on opcode
    uint16_t user_instruction;
};

#endif