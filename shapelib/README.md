# Assignment: Shape Library



## Overview

In this assignment you will implement a small library of shapes that
use a 2D vector class.  The shapes use an inheritance hierarchy, and
the 2D vector uses operator overloading.

Starting from the provided repository, which includes starter code,
reference implementations, and test cases, fill in the function
implementations to complete the shape library.

You can try out the reference implementation in the `ref` folder.

Requirements:
* Complete the implementations of Vector2D and Shapes so that all the test files compile and run (according to the testing script).
  * Put implementation in cpp files, and declarations in hpp files
* Follow the course Development General Guidelines.

Restrictions:
* The Shape class must be abstract.
* Shape must have no member variables.
* All Shape member functions, other than constructors and destructors, must not have implementations.  Any Shape constructors or destructors must have empty implementations.
* All function implementations (definitions) must be in source (.cpp) files.

Editable files:
* You can edit `Vector2D.hpp`, `Vector2D.cpp`, `Shapes.hpp` and `Shapes.cpp`.

Tips:
* In implementation files, you can write the line "using namespace std", which prevents you from having to write std:: in front of certain objects and helper functions (e.g. cout, endl). You cannot do this in header files, so you must include the std:: when using standard library objects.
  * Your compiler should tell you when you need to add std:: in front of something
* This assignment has a larger number of executables for the tests.  Most of the tests are mainly based on the code compiling.
* It's possible to return a reference to a member variable from a member function.
* It's possible to have both const and non-const versions of member functions at the same time (overloading).
* operator[] can be overloaded in the same way as operator().
* If a destructor is declared, it has to be defined, even if it is pure virtual.
* `ostream` shouldn't be passed to or returned from functions by value, but can be passed and returned by reference.
