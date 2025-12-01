PROGRAMS_VECTOR2D=\
	TEST_Vector2D_assign \
	TEST_Vector2D_ctor_copy \
	TEST_Vector2D_ctor_default \
	TEST_Vector2D_ctor_elementwise \
	TEST_Vector2D_element_access \
	TEST_Vector2D_element_get \
	TEST_Vector2D_element_set \
	TEST_Vector2D_oper_addition \
	TEST_Vector2D_oper_division \
	TEST_Vector2D_oper_equality \
	TEST_Vector2D_oper_multiplication \
	TEST_Vector2D_oper_negate \
	TEST_Vector2D_oper_subtraction \
	$(NULL)

PROGRAMS_SHAPES=\
	TEST_Shapes_shape_abstract \
	TEST_Shapes_circle_create \
	TEST_Shapes_circle_display \
	TEST_Shapes_circle_translate \
	TEST_Shapes_circle_destroy \
	TEST_Shapes_triangle_create \
	TEST_Shapes_triangle_display \
	TEST_Shapes_triangle_translate \
	TEST_Shapes_triangle_destroy \
	$(NULL)

PROGRAMS=$(PROGRAMS_VECTOR2D) $(PROGRAMS_SHAPES)

CXXFLAGS=-std=c++20 -O0 -fno-inline -g -Wall -Wextra -Wpedantic -Werror -pedantic-errors
LDFLAGS=-std=c++20

## for gcov
#CXXFLAGS:=$(CXXFLAGS) -fprofile-arcs -ftest-coverage
#LDFLAGS:=$(LDFLAGS) -fprofile-arcs



all: $(PROGRAMS)

$(PROGRAMS_VECTOR2D): %: %.o Vector2D.o
	g++ $(LDFLAGS) $^ -o $@

$(PROGRAMS_SHAPES): %: %.o Shapes.o Vector2D.o
	g++ $(LDFLAGS) $^ -o $@

%.o: %.cpp *.hpp Makefile
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf test.log *~ .vscode/*~ *.o *.dSYM $(PROGRAMS) *.gcda *.gcno *.gcov callgrind.out.*
