# Assignment: Basic Programs

## Overview

In this assignment you will get set up and create basic programs.

Requirements:
* Complete the five programs listed below by filling in their respective `.cpp` files.
* Follow the course Development General Guidelines.

Restrictions:
* n/a

Editable files:
* You can edit each program's `.cpp` file.


### fizzbuzz

This program prompts the user to separately enter two integers F and B, read from standard input. If either F or B <= 0, or there is an input error, the program prints "Invalid input." and exits. Otherwise, it prints out the numbers from 1 to 20 each on their own line; however, for numbers that are multiples of F it prints "Fizz" instead of the number, numbers that are multiples of B it prints "Buzz" instead of the number, and for numbers that are multiples of both F and B it prints "FizzBuzz" instead of the number.



### rectangle

This program prompts the user to separately enter two integers W and H, read from standard input. If either W or H <= 0 or >= 21, or there is an input error, the program prints "Invalid input." and exits. Otherwise, it prints out a rectangle made of X that is W wide and H high.



### calc

This program prompts the user to to separately enter a word W and a double X, read from standard input. If there is an input error, or W is not "sin" or "cos", the the program prints "Invalid input." and exits.  Otherwise, it prints the result of applying the function named by W to X, with at most three digits of precision.



### sum

This program does not prompt the user, and reads whitespace-separated integers from standard input until end-of-file or any stream error conditions are encountered, and then prints the sum of the integers.



### lineno

This program does not prompt the user, and reads lines of text from standard input until until end-of-file or any stream error conditions are encountered, and prints the lines with the line number prepended.  The line number should start at 1, be followed by a colon, and be left padded with spaces to at least three characters long.
