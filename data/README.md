# Assignment: Data Processing Programs



## Overview

In this assignment you will get set up and create programs that
process data using vectors and strings.

Starting from the provided repository, which includes starter code, reference
implementations, and test cases, write the following programs
in C++.

You can try out the reference implemetation in the `ref` folder.

Remember to to fill out the ABOUT.txt.

Requirements:
* Complete the four programs listed below by filling in their respective `.cpp` files.
* Follow the course Development General Guidelines.

Restrictions:
* Some programs have their own restrictions.

Editable files:
* You can edit each program's `.cpp` file.

Tips:
* n/a



### median

This program computes the median of a list of numbers.

The program reads in numbers, as doubles, from standard input until
any error.  You can assume any numbers read in are already
sorted in increasing order. If there are no numbers read, it prints an
error message.  Otherwise, it prints the median of all the numbers
read. (The median is the middle number if there are an odd amount of
numbers, or the average of the two middle numbers if there are an even
amount of numbers.) The value should be printed with a fixed two
digits of precision.



### reverse

This program reverses text.

The program reads in lines of text from standard input until any
error. It then prints each line in reverse order with the characters
in each line reversed.

Restrictions:
* **Do not use any library functions that reverse the string directly.**



### frame

This program puts a frame around text.

The program reads in lines of text from standard input until any
error. It then prints the text that was read in with a *rectangular*
frame of * characters around the text, based on the longest line of
text, horizontally separated by at least one space from the nearest
character.



### grid

This program lets the user place pieces on a 5x5 2D grid.

The program prompts the user for a row and column to place a piece
(0-indexed). Any additional input on a line after the row and column
are read is ignored. If the row and column can be read with no errors
and they are in range, a piece is placed at that location and the user
is asked to place another piece. If there is an error reading the
location, or it is out of range, the program displays the grid with a
'X' where there is a piece and a '.' where there is no piece and
exits. Placing a piece where there already is one has no effect.

Requirements:
* **Represent the grid as a vector of vectors of bool.**
