// code derived from Will Usher's SDL 2.0 Tutorial
// https://www.willusher.io/pages/sdl2/

#include <iostream>
#include <string>

#include "cpu.hpp"

int main(int argc, char **argv)
{
  try
  {
    CPU cpu;

    if (argc < 2)
    {
      std::cerr << "Missing instruction file" << std::endl;
      return 1;
    }

    std::string filename = argv[1];

    cpu.loadProgram(filename);
    std::cout << "instructions loaded: " << cpu.getInstructionCount() << std::endl;

    while (cpu.hasInstructions())
    {
      cpu.clock();
    }

    std::cout << "done" << std::endl;
  }
  catch (const std::out_of_range &e)
  {
    std::cerr << "memory Error: " << e.what() << std::endl;
    return 1;
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << "runtime Error: " << e.what() << std::endl;
    return 1;
  }
  catch (const std::exception &e)
  {
    std::cerr << "error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}

/* Design

CPU class {
  unique pointer to each part of the CPU
  - register file, alu, data memory
  - instruction memory file as input from the user
  - mapper function
  - decoder function
  - clock function for iteration
  -
}



NEXT STEPS:

1. write out register file logic
2. write out memory logic


*/