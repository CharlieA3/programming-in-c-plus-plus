#ifndef ALU_BLOCK
#define ALU_BLOCK

#include <cstdint>

template <typename T>
struct ALU_Result
{
    T output;
    bool take_branch;
    bool overflow;
};

template <typename T>
class ALU
{
public:
    ALU_Result<T> execute(T a, T b, uint8_t opcode);
};

template <typename T>
ALU_Result<T> ALU<T>::execute(T a, T b, uint8_t opcode)
{
    ALU_Result<T> result;
    result.overflow = false;
    result.take_branch = false;

    switch (opcode)
    {
    case 0x01:
        result.output = ~b;
        break;

    case 0x02:
        result.output = a & b;
        break;

    case 0x03:
        result.output = a | b;
        break;

    case 0x04:
        result.output = a >> b;
        break;

    case 0x05:
        result.output = a << b;
        break;

    case 0x06:
        result.output = 0;
        result.take_branch = (a == 0);
        break;

    case 0x07:
        result.output = 0;
        result.take_branch = (a != 0);
        break;

    case 0x08:
        result.output = a ^ b;
        break;

    default:
        result.output = a + b;
        bool a_pos = !(a & 0x8000);
        bool b_pos = !(b & 0x8000);
        bool f_neg = (result.output & 0x8000);
        bool f_pos = !(result.output & 0x8000);
        result.overflow = (a_pos && b_pos && f_neg) || (f_pos && !a_pos && !b_pos);
        break;
    }

    return result;
}

#endif