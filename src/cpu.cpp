#include "cpu.hpp"

void CPU::clock()
{
    user_instruction = inst_mem_ptr->pop_instruction();

    RISCV16_Mapped mapped = RISCV16_Mapped::map_inst(user_instruction);

    // the mapper is included in the decoder as well
    RISCV16_Decoded decoder = RISCV16_Decoded::decode(user_instruction);

    uint8_t readaddr1 = multiplexer(mapped.rs1, mapped.rd, decoder.reg_src);
    uint8_t readaddr2 = mapped.rs2;

    uint8_t write_addr = multiplexer(mapped.rs2, mapped.rd, decoder.reg_dst);

    Register_File_Output reg_file_out = reg_file_ptr->read_two(readaddr1, readaddr2);

    RISCV16S alu_input1 = multiplexer(reg_file_out.data1, static_cast<RISCV16S>(0), decoder.alu_src_1);
    RISCV16S alu_input2 = multiplexer(reg_file_out.data2, static_cast<RISCV16S>(decoder.imm_instruction), decoder.alu_src_2);

    ALU_Result alu_result = alu_ptr->execute(alu_input1, alu_input2, decoder.opcode);

    RISCV16S data_mem_out = static_cast<RISCV16S>(data_mem_ptr->read_word((int)alu_result.output));
    if (decoder.mem_write)
    {
        data_mem_ptr->store_word(alu_result.output, reg_file_out.data2);
    }

    // determines if we are writing back to a register from memory
    RISCV16S write_data = multiplexer(alu_result.output, data_mem_out, decoder.mem_to_reg);

    if (decoder.reg_write)
    {
        reg_file_ptr->write(write_addr, write_data);
    }

    if (alu_result.overflow)
    {
        // TODO: do I need to do anything else?
        printf("Overflow occured on instruction %d\n", program_counter);
    }

    if (alu_result.take_branch)
    {
        program_counter += static_cast<int>(mapped.offset);
    }
    else
    {
        program_counter++;
    }
}

// this logic was used from my lab class where we made a single cycle processor, i just had to type the while thing out
// lets pray I didn't mistype a bit
RISCV16_Mapped RISCV16_Mapped::map_inst(RISCV16 instruction)
{
    RISCV16_Mapped result;

    result.rs1 = 0;
    result.rs2 = 0;
    result.rd = 0;
    result.immediate = 0;
    result.nzimm = 0;
    result.offset = 0;
    result.opcode = 0;

    uint8_t bits_15_13 = (instruction >> 13) & 0x07;

    switch (bits_15_13)
    {
    case 0x06:
    {
        uint8_t bits_1_0 = instruction & 0x03;
        switch (bits_1_0)
        {
        case 0x00:
            result.immediate = ((instruction >> 5) & 0x01) << 6 |
                               ((instruction >> 12) & 0x01) << 5 |
                               ((instruction >> 10) & 0x03) << 3 |
                               ((instruction >> 6) & 0x01) << 2;
            result.rs1 = (instruction >> 7) & 0x07;
            result.rs2 = (instruction >> 2) & 0x07;
            result.opcode = 0x01;
            break;

        case 0x01:
            result.offset = ((instruction >> 12) & 0x01) << 8 |
                            ((instruction >> 12) & 0x01) << 7 |
                            ((instruction >> 5) & 0x03) << 5 |
                            ((instruction >> 2) & 0x01) << 4 |
                            ((instruction >> 10) & 0x03) << 2 |
                            ((instruction >> 3) & 0x03);
            result.rs1 = (instruction >> 7) & 0x07;
            result.opcode = 0x0A;
            break;
        }
        break;
    }

    case 0x02:
        result.immediate = ((instruction >> 5) & 0x01) << 6 |
                           ((instruction >> 12) & 0x01) << 5 |
                           ((instruction >> 10) & 0x03) << 3 |
                           ((instruction >> 6) & 0x01) << 2;
        result.rs1 = (instruction >> 7) & 0x07;
        result.rd = (instruction >> 2) & 0x07;
        result.opcode = 0x00;
        break;

    case 0x04:
    {
        uint8_t bits_11_10 = (instruction >> 10) & 0x03;
        switch (bits_11_10)
        {
        case 0x01:
        {
            uint8_t bits_1_0 = instruction & 0x03;
            switch (bits_1_0)
            {
            case 0x02:
                result.rd = (instruction >> 7) & 0x07;
                result.rs2 = (instruction >> 2) & 0x07;
                result.opcode = 0x02;
                break;

            case 0x01:
                result.nzimm = ((instruction >> 12) & 0x01) << 5 |
                               ((instruction >> 5) & 0x03) << 3 |
                               ((instruction >> 2) & 0x07);
                result.rd = (instruction >> 7) & 0x07;
                result.rs1 = (instruction >> 7) & 0x07;
                result.opcode = 0x08;
                break;
            }
            break;
        }

        case 0x03:
        {
            uint8_t bits_6_5 = (instruction >> 5) & 0x03;
            switch (bits_6_5)
            {
            case 0x03:
                result.rs1 = (instruction >> 7) & 0x07;
                result.rd = (instruction >> 7) & 0x07;
                result.rs2 = (instruction >> 2) & 0x07;
                result.opcode = 0x04;
                break;

            case 0x02:
                result.rs1 = (instruction >> 7) & 0x07;
                result.rd = (instruction >> 7) & 0x07;
                result.rs2 = (instruction >> 2) & 0x07;
                result.opcode = 0x06;
                break;

            case 0x01:
                result.rs1 = (instruction >> 7) & 0x07;
                result.rd = (instruction >> 7) & 0x07;
                result.rs2 = (instruction >> 2) & 0x07;
                result.opcode = 0x07;
                break;
            }
            break;
        }

        case 0x02:
            result.immediate = ((instruction >> 12) & 0x01) << 6 |
                               ((instruction >> 5) & 0x03) << 3 |
                               ((instruction >> 2) & 0x07);
            result.rs1 = (instruction >> 7) & 0x07;
            result.rd = (instruction >> 7) & 0x07;
            result.opcode = 0x05;
            break;
        }
        break;
    }

    case 0x00:
    {
        uint8_t bits_1_0 = instruction & 0x03;
        switch (bits_1_0)
        {
        case 0x01:
            result.nzimm = ((instruction >> 12) & 0x01) << 5 |
                           ((instruction >> 5) & 0x03) << 3 |
                           ((instruction >> 2) & 0x07);
            result.rs1 = (instruction >> 7) & 0x07;
            result.rd = (instruction >> 7) & 0x07;
            result.opcode = 0x03;
            break;

        case 0x02:
            result.nzimm = ((instruction >> 12) & 0x01) << 5 |
                           ((instruction >> 5) & 0x03) << 3 |
                           ((instruction >> 2) & 0x07);
            result.rd = (instruction >> 7) & 0x07;
            result.opcode = 0x09;
            break;
        }
        break;
    }

    case 0x07:
        result.offset = ((instruction >> 12) & 0x01) << 8 |
                        ((instruction >> 12) & 0x01) << 7 |
                        ((instruction >> 5) & 0x03) << 5 |
                        ((instruction >> 2) & 0x01) << 4 |
                        ((instruction >> 10) & 0x03) << 2 |
                        ((instruction >> 3) & 0x03);
        result.rs1 = (instruction >> 7) & 0x07;
        result.opcode = 0x0B;
        break;
    }

    return result;
}

RISCV16_Decoded RISCV16_Decoded::decode(RISCV16 instruction)
{
    RISCV16_Decoded result;

    RISCV16_Mapped mapped = RISCV16_Mapped::map_inst(instruction);

    result.reg_write = false;
    result.reg_dst = false;
    result.alu_src_1 = false;
    result.alu_src_2 = false;
    result.mem_write = false;
    result.mem_to_reg = false;
    result.reg_src = false;
    result.imm_instruction = 0;
    result.opcode = 0;

    switch (mapped.opcode)
    {
    // load word
    case 0x00:
        result.reg_write = true;
        result.reg_dst = true;
        result.imm_instruction = mapped.immediate;
        result.alu_src_1 = false;
        result.alu_src_2 = true;
        result.opcode = 0x00;
        result.mem_write = false;
        result.mem_to_reg = true;
        result.reg_src = false;
        break;

    // store word
    case 0x01:
        result.reg_write = false;
        result.reg_dst = false;
        result.imm_instruction = mapped.immediate;
        result.alu_src_1 = false;
        result.alu_src_2 = true;
        result.opcode = 0x00;
        result.mem_write = true;
        result.mem_to_reg = false;
        result.reg_src = false;
        break;

    // add
    case 0x02:
        result.reg_write = true;
        result.reg_dst = true;
        result.imm_instruction = mapped.immediate;
        result.alu_src_1 = false;
        result.alu_src_2 = false;
        result.opcode = 0x00;
        result.mem_write = false;
        result.mem_to_reg = false;
        result.reg_src = true;
        break;

    // addi
    case 0x03:
        result.reg_write = true;
        result.reg_dst = true;
        result.imm_instruction = mapped.nzimm;
        result.alu_src_2 = true;
        result.opcode = 0x00;
        result.mem_write = false;
        result.mem_to_reg = false;
        result.reg_src = true;
        break;

    // and
    case 0x04:
        result.reg_write = true;
        result.reg_dst = true;
        result.imm_instruction = mapped.immediate;
        result.alu_src_1 = false;
        result.alu_src_2 = false;
        result.opcode = 0x02;
        result.mem_write = false;
        result.mem_to_reg = false;
        result.reg_src = true;
        break;

    // andi
    case 0x05:
        result.reg_write = true;
        result.reg_dst = true;
        result.imm_instruction = mapped.immediate;
        result.alu_src_1 = false;
        result.alu_src_2 = true;
        result.opcode = 0x02;
        result.mem_write = false;
        result.mem_to_reg = false;
        result.reg_src = true;
        break;

    // or
    case 0x06:
        result.reg_write = true;
        result.reg_dst = true;
        result.imm_instruction = mapped.immediate;
        result.alu_src_1 = false;
        result.alu_src_2 = false;
        result.opcode = 0x03;
        result.mem_write = false;
        result.mem_to_reg = false;
        result.reg_src = true;
        break;

    // xor
    case 0x07:
        result.reg_write = true;
        result.reg_dst = true;
        result.imm_instruction = mapped.immediate;
        result.alu_src_1 = false;
        result.alu_src_2 = false;
        result.opcode = 0x04;
        result.mem_write = false;
        result.mem_to_reg = false;
        result.reg_src = true;
        break;

    // srai
    case 0x08:
        result.reg_write = true;
        result.reg_dst = true;
        result.imm_instruction = mapped.nzimm;
        result.alu_src_1 = false;
        result.alu_src_2 = true;
        result.opcode = 0x04;
        result.mem_write = false;
        result.mem_to_reg = false;
        result.reg_src = true;
        break;

    // slli
    case 0x09:
        result.reg_write = true;
        result.reg_dst = true;
        result.imm_instruction = mapped.nzimm;
        result.alu_src_1 = false;
        result.alu_src_2 = true;
        result.opcode = 0x05;
        result.mem_write = false;
        result.mem_to_reg = false;
        result.reg_src = true;
        break;

    // beqz
    case 0x0A:
        result.reg_write = false;
        result.reg_dst = false;
        result.imm_instruction = mapped.offset;
        result.alu_src_1 = false;
        result.alu_src_2 = true;
        result.opcode = 0x06;
        result.mem_write = false;
        result.mem_to_reg = false;
        result.reg_src = false;
        break;

    // bneqz
    case 0x0B:
        result.reg_write = false;
        result.reg_dst = false;
        result.imm_instruction = mapped.offset;
        result.alu_src_1 = false;
        result.alu_src_2 = true;
        result.opcode = 0x07;
        result.mem_write = false;
        result.mem_to_reg = false;
        result.reg_src = false;
        break;

    default:
        result.reg_write = false;
        result.reg_dst = false;
        result.imm_instruction = mapped.immediate;
        result.alu_src_1 = false;
        result.alu_src_2 = false;
        result.opcode = 0x00;
        result.mem_write = false;
        result.mem_to_reg = false;
        result.reg_src = false;
        break;
    }

    return result;
}

void RISCV16_Decoded::display_control_signals()
{
    printf("reg_write: %d\n", reg_write);
    printf("reg_dst: %d\n", reg_dst);
    printf("alu_src_1: %d\n", alu_src_1);
    printf("alu_src_2: %d\n", alu_src_2);
    printf("mem_write: %d\n", mem_write);
    printf("mem_to_reg: %d\n", mem_to_reg);
    printf("reg_src: %d\n", reg_src);
}

void RISCV16_Decoded::display_op_and_inst()
{
    printf("decoder opcode: %hhu\n", opcode);
    printf("immeidate instruction: %hu\n", imm_instruction);
}