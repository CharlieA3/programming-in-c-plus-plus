#ifndef ALU_BLOCK
#define ALU_BLOCK

#include <cstdint>

struct ALU_Result
{
    uint16_t output;
    bool take_branch;
    bool overflow;
};

// yes, this class is just a function, I know, weird
// my decision for this was to make this class scalable for different ISAs
class ALU
{
public:
    ALU_Result riscv16_op(std::int16_t a, std::int16_t b, std::uint8_t opcode);
};

#endif