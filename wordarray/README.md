# Assignment: Word Array



## Overview

In this assignment you will implement "WordArray": a data structure that stores a collection of words. This collection is a dynamically allocated array of dynamically allocated C-strings. You will also implement some operations on the WordArray. (functions that manipulate WordArrays)

A word array has both a maximum number of words it can hold (the total
size of the array) and current number of words (the number of elements
in the array that are currently being used to hold words). The words are stored
contiguously at the beginning of the array (that is, they are not
separated by blank entries) and unused entries are set to null.

The wordarray_main.cpp program provides a text interface for manipulating word arrays through commands. A command reference is given below.

Remember to to fill out the ABOUT.txt (and LLM.txt if needed).

Requirements:
* Complete the functions in `WordArray.cpp`

Restrictions:
* You may not use strdup / strndup from cstring. I would suggest writing your own strdup and calling it something else (e.g. `my_strdup`).
* You must not use C++ string objects, only C-strings
* You must not use any fixed-size (i.e. static) arrays, only dynamic arrays.
* You must manually manage the memory of the array and C-strings using the new/new[]/delete/delete[] operators.
* You must not use smart pointers. (If you don't know what these are, don't worry and feel free to ignore this)
* You must not use other memory management functions such as malloc / free (If you don't know what these are, don't worry)
* Follow the course Development General Guidelines.

Editable files:
* You can edit `WordArray.cpp`.

Tips:
* You may use any functions from the &lt;cstring&gt; header (except strdup/strndup).
* It is okay to dynamically allocate and deallocate an array of 0 size.  This may simplify your implementation.
* You can use `strtok` to find words in a C-string; however, it has to be a non-const C-string since `strtok` may change it.
* For this assignment, words in a C-string are separated by any number of spaces.
* There is some code in WordArray to prevent the compiler from automatically generating copy member functions. (You'll see the code `= delete`, this simply tells the compiler not to auto-generate those functions).

## Command reference

`wordarray_main` allows you to run a variety of commands to test out your implementation.

Commands operate on named word arrays. Note that the string [string]
may contain spaces.

*[name] new-size [maxsize]*
&nbsp; Allocate and construct the word array `[name]` with max size `[maxsize]`.

*[name] new-string [string]*
&nbsp; Allocate and construct the word array `[name]` with the C-string `[string]`.

*[name] delete*
&nbsp; Destruct and deallocate the word array `[name]`.

*[name] meta*
&nbsp; Print meta-information about the data structure in the word array `[name]`. Specifically, it prints the num_words currently in the array, the max_words the array can store, and a visual representation of the filled and unfilled slots in the array.

*[name] print*
&nbsp; Print the word array `[name]`.

*[name] findFirst [word]*
&nbsp; Find the first occurence of `[word]` (if any) in the word array `[name]`.

*[name] removeAll [word]*
&nbsp; Remove all occurences of `[word]` from the word array `[name]`.

*[name] append [name2]*
&nbsp; Append all words from the word array `[name2]` onto the word array `[name]`.

---------------

As an example, here is what the data structures would look like after
running each of these commands in sequence:

`a new-size 4`

<img src="README-example1a.png" height="100">

`b new-string abc de`

<img src="README-example1b.png" height="200">

`a append b`

<img src="README-example1c.png" height="200">

`a removeAll abc`

<img src="README-example1d.png" height="200">
