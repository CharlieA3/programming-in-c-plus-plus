PROGRAMS=\
	TEST_push_1i \
	TEST_push_2i \
	TEST_push_3i \
	TEST_push_4i \
	TEST_push_5i \
	TEST_push_6i \
	TEST_push_1s \
	TEST_push_2s \
	TEST_push_3s \
	TEST_push_4s \
	TEST_push_5s \
	TEST_push_6s \
	TEST_pop_1i \
	TEST_pop_2i \
	TEST_pop_3i \
	TEST_pop_4i \
	TEST_pop_5i \
	TEST_pop_6i \
	TEST_pop_1s \
	TEST_pop_2s \
	TEST_pop_3s \
	TEST_pop_4s \
	TEST_pop_5s \
	TEST_pop_6s \
	TEST_iter_loop_i \
	TEST_iter_find_i \
	TEST_iter_for_each_i \
	TEST_iter_range_for_i \
	TEST_iter_pre_i \
	TEST_iter_post_i \
	TEST_iter_loop_s \
	TEST_iter_find_s \
	TEST_iter_for_each_s \
	TEST_iter_range_for_s \
	TEST_iter_pre_s \
	TEST_iter_post_s \
	$(NULL)

CXXFLAGS=-std=c++20 -O0 -fno-inline -g -Wall -Wextra -Wpedantic -Werror -pedantic-errors
LDFLAGS=-std=c++20

## for gcov
#CXXFLAGS:=$(CXXFLAGS) -fprofile-arcs -ftest-coverage
#LDFLAGS:=$(LDFLAGS) -fprofile-arcs



all: $(PROGRAMS)

$(PROGRAMS): %: %.o
	g++ $(LDFLAGS) $^ -o $@

%.o: %.cpp *.hpp Makefile
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf test.log *~ .vscode/*~ *.o *.dSYM $(PROGRAMS) *.gcda *.gcno *.gcov callgrind.out.*
