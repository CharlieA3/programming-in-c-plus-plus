PROGRAMS=robotsgame_main

CXXFLAGS=-std=c++20 -O0 -fno-inline -g -Wall -Wextra -Wpedantic -Werror -pedantic-errors -Wno-unused-parameter -Wno-unused-private-field
LDFLAGS=-std=c++20

## for gcov
#CXXFLAGS:=$(CXXFLAGS) -fprofile-arcs -ftest-coverage
#LDFLAGS:=$(LDFLAGS) -fprofile-arcs



all: $(PROGRAMS)

robotsgame_main: robotsgame_main.o Game.o Entity.o Cell.o
	g++ $(LDFLAGS) $^ -o $@

%.o: %.cpp *.hpp Makefile
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf test.log *~ .vscode/*~ *.o *.dSYM $(PROGRAMS) *.gcda *.gcno *.gcov callgrind.out.*
