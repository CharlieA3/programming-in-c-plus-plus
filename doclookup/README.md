# Assignment: Document Lookup



## Overview

This assignment has two parts: You will implement a document lookup system using different standard library collections. You will also analyze the performance of these various collections using callgrind.

You can try out the reference implementation in the `ref` folder. A guide to running the reference implementation is given at the bottom of this README

Requirements:
* Implement the document lookup system so that all tests pass with `test.py`. See the section below called `doc_main` for more details.
* Use callgrind to analyze the speed of various STL collections. See the section below called `compare_main` for more details.
* Follow the course Development General Guidelines.

Restrictions:
* You must use iterators to loop through strings and collections. To help practice iterators, `auto` and range-based for loops are not available. (This program compiles using C++98, which didn't have these features.)
* You must not use any standard library algorithms (i.e. from &lt;algorithm&gt;), but you can use any member functions on the collections.

Editable files:
* `Document.cpp`, `Lookup.cpp`, and `compare_main.cpp`.

Tips:
* `stringstream` can be helpful in splitting up a line word by word.

-------------------

### doc_main

Implement the functions marked TODO in `Document.cpp` and `Lookup.cpp` to
implement a document loading and word lookup system.  The functions in
`Document.cpp` read in and print out documents. The functions in
`Lookup.cpp` add documents to a collection and look up words in the
documents.

`doc_main.cpp` implements a simple text command input system for using
the system.  A command reference is given below.

Restrictions:
* `add_document` and `lookup_word` on a `MapCollection` must not do a linear search through the collection, but must use `map` member functions (e.g. `map::find`) that use the map's data structure.

Tips:
* In addition to the `T::iterator` types provided by collections (such as `vector<int>::iterator`), there are also `T::const_iterator` types for iterating through const collections.
* In C++98, an `ifstream` for reading files can't be initialized from a string object; however, you can use string's `c_str()` member function to get a type that can be used to initialize an ifstream.

### compare_main

Use callgrind to compare the relative performance of the different types
of collections.

Fill in implementations of the `use_...` functions in `compare_main.cpp`, in
the areas marked TODO to use the collections. For each iteration of
the loop, initialize the collection from scratch from the document and
search for a word that is *not in the collection*.

You can modify the constants at the top of the file to change the
document name and number of iterations.

For both the primes_small and primes_large documents, use callgrind to analyze the performance of the collections *two times* each: The first time, use the flags that are currently in the Makefile. The second time, change the `-O0` flag to `-O2` and remove the `-fno-inline` flag. This enables optimizations so your code runs faster.

You'll need to edit the Makefile, don't commit these changes.

**Write your observations into `compare.txt`**

Include the *percentage* of instructions your program spent in each
of the `use_...` functions and a short summary of what you observed in
terms of the relative performance of each function.

## Command reference

*list*  
&nbsp; List the documents.

*print [docname]*  
&nbsp; Print the document named *docname*.

*lookup-v [word]*  
&nbsp; Lookup *word* (print the documents that contain *word*) using a vector collection.

*lookup-l [word]*  
&nbsp; Lookup *word* (print the documents that contain *word*) using a list collection.

*lookup-m [word]*  
&nbsp; Lookup *word* (print the documents that contain *word*) using a map collection.
