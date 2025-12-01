# Assignment: C-string Library



## Overview

In this assignment you will implement a subset of the C standard
library for manipulating C-strings.

The cstringlib_main.cpp program provides a text interface for manipulating a single C-string through commands. A command reference is given below.

Starting from the provided repository, which includes starter code,
reference implementations, and test cases, fill in the areas marked
TODO to complete the program in C++.

You can try out the reference implementation in the `ref` folder. See the command reference below for advice on using the reference implementation.

Requirements:
* Write the implementation for the functions in `cstringlib.cpp`. They should act the same as the functions from the &lt;cstring&gt; header file. [You can find the documentation for cstring here](http://www.cplusplus.com/reference/cstring/). Complete the implementation by filling in the areas commented TODO.
* Follow the course Development General Guidelines.
* **Optional:** You can also implement the strtok function for extra credit, but it is not required.
  * **You may not refer to external resources when implementing strtok** (other than the library documentation above).
  * `strtok` modifies the string `str` passed in as an argument.  `strtok` also has to use a global variable to keep track of where it is in the string that is being split into tokens. It is okay to use global variables in the implementation of `strtok`.
    * (A global variable is one that is placed outside a function or class. Because it exists outside a function or class, it can be used by all functions or classes. A variable that belongs to a function will be reset when the function is called, but a global variable will not.)
  * The first argument to strtok may be null.

Restrictions:
* You must not call other library functions or use other library classes (e.g. `std::string` or `std::vector` or anything from `<cstring>`).
* You must implement the functions in terms of built-in types (e.g. char \*, char, int) and size_t. 
* Your code must be written to handle C-strings of arbitrary size (that is, no fixed-size buffers should be used).

Editable files:
* You can edit `cstringlib.cpp`.

Tips:
* This assignment uses the pointer style (`char *`) for C-strings instead of the array style (`char []`) like in the book.  In practice for this assignment, you can use these pointers in similar ways as arrays.
* `nullptr` represents a null pointer that doesn't point to anything. This is different from an empty string (`""`) or a null character (`'\0'`). A null pointer is often returned from C-string functions to indicate that they did not succeed for some reason.
* For functions that return a pointer, you can use an expression like `str + n` to return a pointer to the `n`th character in the C-string `str`.
* The buffer used to hold the C-string for testing is initially filled with `x`s.  If you see them displayed, there may be an issue null-terminating the C-string.
* You can assume that the C-string pointer arguments to the functions are not null and are valid C-strings.

## Command reference

`cstringlib_main` allows you to run a variety of commands to test out your implementation. `cstringlib_main` has a single buffer that stores a string. All commands operate using that buffer, sometimes modifying it.

Tip: The buffer will initially be empty. As your first command, try using strncpy to fill it with something.

Specifically: commands operate on a single C-string buffer of size 21 (enough space
for a C-string of length 20 plus the terminating null character). The C-string
is stored in the buffer [strbuf], which has size [strbufsize]. Note
that the string [string] may contain spaces.

*print*  
&nbsp; Print the C-string.

*printall*  
&nbsp; Print the entire buffer containing the C-string, with null characters and other special characters displayed as underscores.

*strlen*  
&nbsp; Get the length of the C-string with `strlen([strbuf])`.

*strncpy [string]*  
&nbsp; Copy into the C-string with `strncpy([strbuf], [string], [strbufsize] - 1)`, and ensure the last character in the buffer is a null character.

*strncat [string]*  
&nbsp; Concatenate into the C-string with `strncat([strbuf], [string], [strbufsize] - strlen([strbuf]) - 1)`.

*strcmp [string]*  
&nbsp; Compare to the C-string with `strcmp([strbuf], [string])`.

*strchr [char]*  
&nbsp; Search for a character in the C-string with `strchr([strbuf], [char])`.

*strrchr [char]*  
&nbsp; Reverse search for a character in the C-string with `strrchr([strbuf], [char])`.

*strstr [string]*  
&nbsp; Search for a substring in the C-string with `strstr([strbuf], [string])`.

*strtok-str [string]*  
&nbsp; Start tokenizing the C-string with `strtok([strbuf], [string])`.

*strtok-null [string]*  
&nbsp; Continue tokenizing the C-string with `strtok(nullptr, [string])`.
