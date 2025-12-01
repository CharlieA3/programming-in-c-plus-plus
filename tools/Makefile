PROGRAMS=gdb_mystery valgrind_vector_as_string gcov_loops callgrind_compare_vector

CXXFLAGS=-std=c++20 -O0 -fno-inline -g -Wall -Wextra -Wpedantic -Wno-unused # -Werror -pedantic-errors
LDFLAGS=-std=c++20

## for gcov
CXXFLAGS:=$(CXXFLAGS) -fprofile-arcs -ftest-coverage
LDFLAGS:=$(LDFLAGS) -fprofile-arcs



all: $(PROGRAMS)

$(PROGRAMS): %: %.o
	g++ $(LDFLAGS) $< -o $@

%.o: %.cpp Makefile
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf test.log *~ .vscode/*~ *.o *.dSYM $(PROGRAMS) *.gcda *.gcno *.gcov callgrind.out.*
