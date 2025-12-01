CXXTEST_HOME?=cxxtest
CXXTEST_GEN=$(CXXTEST_HOME)/bin/cxxtestgen
CXXTEST_INCLUDE=$(CXXTEST_HOME)

PROGRAMS=runner

CXXFLAGS=-std=c++20 -O0 -fno-inline -g -Wall -Wextra -Wpedantic -Werror -Wno-ignored-qualifiers -Wno-deprecated-enum-float-conversion -pedantic-errors
LDFLAGS=-std=c++20

## for gcov
CXXFLAGS:=$(CXXFLAGS) -fprofile-arcs -ftest-coverage
LDFLAGS:=$(LDFLAGS) -fprofile-arcs



all: $(PROGRAMS)

runner: runner.o IntArray.o IntArray.cxxtest.o
	g++ $(LDFLAGS) $^ -o $@

%.o: %.cpp *.hpp Makefile
	g++ -I$(CXXTEST_INCLUDE) $(CXXFLAGS) -c $< -o $@

%.cxxtest.cpp: %.cxxtest.hpp
	python3 -W ignore $(CXXTEST_GEN) --part --error-printer $< -o $@

runner.cpp:
	python3 -W ignore $(CXXTEST_GEN) --root --error-printer -o $@

clean:
	rm -rf test.log *~ .vscode/*~ *.o *.dSYM $(PROGRAMS) *.gcda *.gcno *.gcov callgrind.out.* runner.cpp *.cxxtest.cpp
