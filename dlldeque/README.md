# Assignment: DLL Deque / Unit Testing

## Overview

This is a 2-part assignment.  Each part is in its own subfolder.  The first part, implementing a double-ended queue as a doubly-linked list, is in `dlldeque`.  The second part, implementing unit tests with CxxTest, is in `unittesting`.



## DLL Deque Overview

In this part, you will implement a generic deque (double-ended queue) using smart pointers. Your deque will be a doubly-linked list, with extra pointers pointing at the head and tail. Each element of the deque will be a "node", which contains an item of the deque along with pointers to the next and previous node. This structure makes it very efficient to add or remove elements from the beginning or end.

You will also need to implement the iterator for DLLDeque, so it
can be used in STL algorithms and range-based for loops (`for (auto elem : list)`)

You can try out the reference implementation in the `ref` folder.

Requirements:
* Implement the DLLDeque functions and iterator operators so that all tests pass.
* Change the typedefs of raw pointers in DLLDeque to smart pointers (either std::shared_ptr or std::weak_ptr). The smart pointers must automatically manage the memory for the linked list.
* Follow the course Development General Guidelines.

Restrictions:
* You must not directly call new or delete or use raw pointers (other than `this` and `nullptr`).

Editable files:
* `DLLDeque.tmpl.hpp` and the typedefs at the top of `DLLDeque.hpp`.



## Unit Testing Overview

In this assignment you will implement unit tests for a dynamic array.

You are provided with an implementation of a class IntArray that manages a dynamic array of integers. You are also provided with placeholder CxxTest suites for IntArray.

This assignment has no reference implementation or test cases, instead your score is based on code coverage of `IntArray.cpp`. More instructions below.

Requirements:
* Add unit tests to `IntArray.cxxtest.hpp` to test IntArray.
* The IntArray test suite should test *every* function and *every* line of code of `IntArray.cpp`. Each test should focus on testing a single function (except for explicitly testing `IntArray::~IntArray()`, `IntArray::ptr()`, and `IntArray::size()`).  This can be confirmed with gcov.
* Note: This assignment has no reference implementation or tests for the test script. Compiling your code will create a `runner` executable which you can run with `./runner` in a terminal.
* Follow the course Development General Guidelines.

Restrictions:
* n/a

Editable files:
* `IntArray.cxxtest.hpp`

Getting CxxTest: You'll need to get CxxTest and add it to your repo; use the following steps.

* Visit the [CxxTest repo](https://github.com/CxxTest/cxxtest/), download, and extract revision a19f85fdf9 into a folder called `cxxtest`.
  * This can be done in a terminal using:
    * `curl -o cxxtest.zip -L https://github.com/CxxTest/cxxtest/archive/a19f85fdf90f97e16d6e3e7e3d2d68c31cd89e3c.zip`
    * `unzip cxxtest.zip`
    * `mv cxxtest-a19f85fdf90f97e16d6e3e7e3d2d68c31cd89e3c cxxtest`
    * `rm cxxtest.zip`
* Make the cxxtestgen file executable.  This can be done by entering `chmod +x cxxtest/bin/cxxtestgen` in a terminal.
* Add and commit all the files in the cxxtest folder.

Tips:
* In order to test the assignment operator, you must first construct an object, change it, *then* assign it to something different.
* To test the `const []` operator, the array itself must be const.
* Usually you have to enable certain flags for `gcov`. This is already done for your convenience.
* To test code coverage, the following workflow is helpful:
  * remove all old code coverage files with `rm *.gcda`
  * compile your code with `make`
  * run the runner file with `./runner`
  * create a new code coverage file with `gcov IntArray.cpp`
  * open the `IntArray.cpp.gcov` file to see what lines still need to be covered.
* You can automate the running of commands by creating a bash file.
  * A bash file is any file that ends with `.sh`. Example: `my_bash_file.sh`
  * The first line in the file itself is `#!/bin/bash`
  * Then, add each command you want to run as a separate line.
  * Make the file into a program by running `chmod +x my_bash_file.sh` in a terminal.
  * Run your bash file with `./my_bash_file.sh`. All the commands within the file will be run one after another.
