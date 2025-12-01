# Assignment: Pathfinding

## Overview

In this assignment you will implement functions to find a path through a grid-based world (like in robots game). Specifically, you will implement the breadth-first-search (BFS) algorithm, and the A\* algorithm using the standard library algorithms.

[You can find an introduction to and overview of the BFS and A*
algorithms
here](https://www.redblobgames.com/pathfinding/a-star/introduction.html). The
page provides Python implementation examples, which you can use as a
starting point. You should implement the "early exit" version of
BFS. The page has a link to a C++ implementation, but do not refer to
or copy that implementation.

A\* uses a priority queue to get elements with high priority. You **may not** use the C++ priority queue, and should instead build your own priority queue using a vector and C++ heap functions. (Notably, these heap functions refer to a heap data structure, a simpler form of a priority queue, and do not refer to the heap section of memory).

You can find information on turning a vector into a heap [here](https://www.fluentcpp.com/2018/03/13/heaps-priority-queues-stl-part-1/) and [here](https://www.fluentcpp.com/2018/03/16/heaps-cpp-stl/)

The file `pathfinding_main.cpp` implements a simple text command input system for using the system. A command reference is given below.

Starting from the provided repository, which includes starter code,
reference implementations, and test cases, fill in the areas marked
TODO to complete the program in C++.

Requirements:
* Complete the world initialization functions and pathfinding algorithms so that all tests pass.
* You should implement the "early exit" version of BFS.
* Follow the course Development General Guidelines.

Restrictions:
* You must implement the pathfinding algorithms using the standard library objects
  provided at the beginning of pathfind_bfs and pathfind_astar (i.e. std::vector, std::deque, std::map). For example, you must implement the BFS frontier queue using a deque.
* You must implement the A\* frontier priority queue directly using a vector and the standard library heap algorithms (i.e. `std::push_heap`, `std::pop_heap`, etc). Do not use `std::priority_queue`. More information about the heap data structure [here](https://www.fluentcpp.com/2018/03/13/heaps-priority-queues-stl-part-1/) and [here](https://www.fluentcpp.com/2018/03/16/heaps-cpp-stl/)


Editable files:
* `World.cpp` and `Pathfinding.cpp`.

Tips:
* Since there may be multiple possible shortest paths from the start to the goal, the tests will not check the exact path found, but just the length and connectivity of the path.

## Command reference

Worlds for pathfinding are initialized using an id, which is a seed used to randomly add elements to the world. This program works with ids between 1 and 99. Try `print 25`

*print [worldId]*  
&nbsp; Print the world with *worldId*.

*neighbors [worldId]*  
&nbsp; Print the neighbors of the points along the diagonal and edges of the world with *worldId*.

*bfs-print [worldId]*  
&nbsp; Print extended information about the path found using BFS for the world with *worldId*.

*bfs-summary [worldId]*  
&nbsp; Print a summary of the path found using BFS for the world with *worldId*.

*astar-print [worldId]*  
&nbsp; Print extended information about the path found using A* for the world with *worldId*.

*astar-summary [worldId]*  
&nbsp; Print a summary of the path found using A* for the world with *worldId*.
