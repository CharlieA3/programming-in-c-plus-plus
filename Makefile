PROGRAMS=doc_main compare_main

CXXFLAGS=-std=c++98 -O0 -fno-inline -g -Wall -Wextra -Wpedantic -Werror -pedantic-errors
LDFLAGS=-std=c++98

## for gcov
#CXXFLAGS:=$(CXXFLAGS) -fprofile-arcs -ftest-coverage
#LDFLAGS:=$(LDFLAGS) -fprofile-arcs



all: $(PROGRAMS)

doc_main: doc_main.o Document.o Lookup.o
	g++ $(LDFLAGS) $^ -o $@

compare_main: compare_main.o Document.o Lookup.o
	g++ $(LDFLAGS) $^ -o $@

%.o: %.cpp *.hpp Makefile
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf test.log *~ .vscode/*~ *.o *.dSYM $(PROGRAMS) *.gcda *.gcno *.gcov callgrind.out.*
