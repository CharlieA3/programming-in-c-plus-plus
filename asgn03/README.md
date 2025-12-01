# Assignment: Development Tools



## Overview

In this assignment you will get practice using different C++
development tools.  Each program has code in a .cpp file for you to
run with a different tool, and a .txt file for you to write your
answer in. There are no tests for this assignment.

In this assignment, the provided Makefile includes some different sets
of compile flags in comments for you to use (lines starting with #).
You will need to modify the Makefile by commenting in the appropriate
lines to get the right compile flags to use with each tool.

**Note: This assignment has no reference implementation or tests for the test script. Use the executable for each program created by the build.**

Requirements:
* Complete the four sections listed below. Each section has a cpp file and associated txt file to fill out.
* Follow the course Development General Guidelines.

Restrictions:
* n/a

Editable files:
* You can edit each program's `.cpp` file and the associated `.txt` file.
* You'll need to modify the `Makefile` for some parts, but do not commit the changes.

Tips:
* n/a

## gdb_mystery

Compile and run the program using the VSCode debugger. Determine the following values
while the program is running, and *describe what you did with the
debugger to find them.*

* VALUE 1: The value of m2 in mystery2 when the division by 0 error occurs.
* VALUE 2: The value of m1b in in mystery1b when mystery1a prints "mystery".
* VALUE 3: The value of i in mystery1b (before being decremented) the second time m1b is assigned 28 (i.e. use an ignore count of 1, or resume once).

In VS Code, you can run the program in the debugger by clicking on the
Run sidebar on the left (the bug triangle), choosing "debug
gdb_mystery" in the dropdown at the top, and clicking the green
arrow. You can click to the left of the line numbers to add/remove
breakpoints, and right click a breakpoint to set its properties.



## valgrind_vector_as_string

Compile and run the program using Valgrind. Try different inputs to
find memory errors in the code. Find three *different types* of memory
errors in the program using valgrind.  For each type of error you
find, describe what caused the error and *include relevant output
from valgrind* in your answer. You do not need to change the code or
fix the errors.

In VS Code, Valgrind can be run in the terminal by running `valgrind
./valgrind_vector_as_string`.



## gcov_loops

Compile and run the program using Gcov. For the lines marked with
comments "LINE #", determine how many times each line was executed.

In VS Code, Gcov can be run in the terminal by first building with
gcov flags (*by editing the Makefile so that the `for gcov` flags are
not commented out*), then running `./gcov_loops` and then running
`gcov gcov_loops.cpp`.



## callgrind_compare_vector

Use callgrind to determine if it is faster to access
std::vector elements using the at() member function or square brackets
[]. *Add code to use these vector functions*, run the resulting
program, and examine the resulting timing information with callgrind. Add
a short description of what you found in your answer and *include
relevant lines from the callgrind_annotate output to support your determination*.

Hint: You may need to make sure the vector functions are called enough
times to show up in the output.

In VS Code, callgrind can be run in the terminal by by first running
`valgrind --tool=callgrind ./callgrind_compare_vector` and then
running `callgrind_annotate --auto=no --inclusive=yes --show-percs=yes
callgrind.out.[id]` (where `[id]` should match the process id in
valgrind's output when it was run). You might also find the
`--threshold=100` argument useful.
