// code derived from Will Usher's SDL 2.0 Tutorial
// https://www.willusher.io/pages/sdl2/

#include <iostream>
#include <string>

#include "cpu.hpp"

int main(int argc, char **argv)
{

  // future design - parameters get passed into the MCU so every components can be initialized in a modular way
  CPU cpu();

  // create instruction file here, load file into queue - using a queue for future user interaction for entering instructions

  
  
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