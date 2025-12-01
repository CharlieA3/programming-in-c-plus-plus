# Assignment: Robots Game



## Overview

In this assignment you will implement a simplified text version of the game
[Robots](https://en.wikipedia.org/wiki/Robots_(1984_video_game)).

Starting from the provided repository, which includes starter code,
reference implementations, and test cases, fill in the function
implementations to complete the Robots game in C++.

You can try out the reference implementation in the `ref` folder.

Requirements:
* Implement the simplified version of the game Robots.
* Follow the course Development General Guidelines.

Restrictions:
* Error conditions must be handled by throwing exceptions, to be caught in main.
* You must not change the entity count (e.g. call `EntityCounter::increment` or `EntityCounter::decrement`) outside Entity.cpp.

Editable files:
* You can edit `Entity.cpp` and `Game.cpp`.

Tips:
* All the user input is line-based. Use the non-member getline to read the user's input, don't use operator >>.
* The first line entered is the name of the world file to use.
* One constructor for Player takes in another Player. This constructor should copy all the data in the other Player.
* In a turn, first the player moves, then the robots move, then any collisions are handled.
