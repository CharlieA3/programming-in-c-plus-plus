#include "alu.hpp"

ALU_Result ALU::riscv16_op(int16_t a, int16_t b, std::uint8_t opcode)
{
    ALU_Result result;
    result.overflow = false;
    result.take_branch = false;

    switch (opcode)
    {
    // inversion
    case 0x01:
        result.output = ~b;
        break;

        // and
    case 0x02:
        result.output = a & b;
        break;

    // or
    case 0x03:
        result.output = a | b;
        break;

    // arithmetic shift right (signed)
    case 0x04:
        result.output = a >> b;
        break;

    // logical shfit left
    case 0x05:
        result.output = a << b;
        break;

    // beqz (branch if equal to zero)
    case 0x06:
        result.output = 0;
        result.take_branch = (a == 0);
        break;

    // bnez (branch if not equal to zero)
    case 0x07:
        result.output = 0;
        result.take_branch = (a != 0);
        break;

    // xor
    case 0x08:
        result.output = a ^ b;
        break;

    // add
    default:
        result.output = a + b;
        // overflow if (both positive and result negative) OR (both negative and result positive)
        bool a_pos = !(a & 0x8000);             // checks if the 15th bit of a is a 1 (neg)
        bool b_pos = !(b & 0x8000);             // checks if the 15th bit of b is a 1 (neg)
        bool f_neg = (result.output & 0x8000);  // is the output positive
        bool f_pos = !(result.output & 0x8000); // is the output negative

        result.overflow = (a_pos && b_pos && f_neg) || (f_pos && !a_pos && !b_pos);
        break;
    }

    return result;
}