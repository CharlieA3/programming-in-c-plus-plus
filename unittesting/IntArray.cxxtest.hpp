#ifndef INT_ARRAY_CXXTEST_HPP
#define INT_ARRAY_CXXTEST_HPP

#include <cxxtest/TestSuite.h>
#include <iostream>
#include <utility>
#include "IntArray.hpp"

class IntArrayTestSuite : public CxxTest::TestSuite
{
public:
  void test_constructor_default()
  {
    IntArray def = IntArray();
    TS_ASSERT(def.ptr());
    TS_ASSERT(def.size() == 0);
  }

  void test_constructor_size_t()
  {
    IntArray def = IntArray(5);
    TS_ASSERT(def.size() == 5);

    for (size_t i = 0; i < def.size(); i++)
    {
      TS_ASSERT(def[i] == 0);
    }
  }

  void test_constructor_init()
  {
    IntArray def = IntArray{1, 2, 3, 4, 5};

    TS_ASSERT(def.ptr());
    TS_ASSERT(def.size() == 5);

    for (size_t i = 0; i < def.size(); i++)
    {
      TS_ASSERT(def[i] == (int)i + 1);
    }
  }

  void test_constructor_copy()
  {
    IntArray def({1, 2, 3});
    IntArray def2(def);
    TS_ASSERT(def.ptr() != def2.ptr());
    TS_ASSERT(def.size() == def2.size());

    for (size_t i = 0; i < def2.size(); i++)
    {
      TS_ASSERT(def[i] == def2[i]);
    }
  }

  void test_constructor_move()
  {
    IntArray def({1, 2, 3});
    size_t def_size = def.size();
    const int *def_pointer = def.ptr();
    IntArray def2(std::move(def));

    TS_ASSERT(def2.ptr() == def_pointer);
    TS_ASSERT(def2.size() == def_size);

    for (size_t i = 0; i < def_size; i++)
    {
      TS_ASSERT(def2[i] == (int)i + 1);
    }

    TS_ASSERT(def.ptr() == nullptr);
    TS_ASSERT(def.size() == 0);
  }

  void test_assignment_copy()
  {
    IntArray def({1, 2, 3});
    IntArray def2({4, 5, 6});
    IntArray def3({7, 8});

    def2 = def;

    TS_ASSERT(def.ptr() != def2.ptr());
    TS_ASSERT(def.size() == def2.size());

    for (size_t i = 0; i < def2.size(); i++)
    {
      TS_ASSERT(def[i] == def2[i]);
    }

    // self assignment
    IntArray a({1, 2, 3});
    a = a;
    TS_ASSERT(a.size() == 3);
    TS_ASSERT(a[0] == 1);

    // copying using different size array
    def = def3;
    TS_ASSERT(def.size() == 2);
    TS_ASSERT(def[0] == 7);
    TS_ASSERT(def[1] == 8);
  }

  void test_assignment_move()
  {
    IntArray def({1, 2, 3});
    size_t def_size = def.size();
    const int *def_pointer = def.ptr();
    IntArray def2({1, 1, 1});
    def2 = std::move(def);

    TS_ASSERT(def.ptr() == nullptr);
    TS_ASSERT(def.size() == 0);

    TS_ASSERT(def2.ptr() == def_pointer);
    TS_ASSERT(def2.size() == def_size);

    for (size_t i = 0; i < def_size; i++)
    {
      TS_ASSERT(def2[i] == (int)i + 1);
    }

    // self move?
    IntArray def3({1, 2, 3});
    def3 = std::move(def3);
    TS_ASSERT(def3.size() == 3);
  }

  void test_elem_nonconst()
  {
    IntArray def({1, 2, 3});

    // modify in different ways
    def[0] = 10;
    TS_ASSERT(def[0] == 10);

    def[1] = def[0] + 5;
    TS_ASSERT(def[1] == 15);

    TS_ASSERT_THROWS_ANYTHING((def[3]));
  }

  void test_elem_const()
  {
    const IntArray def({1, 2, 3});

    TS_ASSERT(def[0] == 1);
    TS_ASSERT(def[1] == 2);
    TS_ASSERT(def[2] == 3);

    TS_ASSERT_THROWS_ANYTHING((def[3]));
  }

  void test_oper_equals()
  {
    const IntArray def({1, 2, 3});
    const IntArray def2({1, 2, 3});
    const IntArray def3({4, 5, 6});
    const IntArray def4({7});

    bool tc = def == def2;
    bool fc = def == def3;

    TS_ASSERT(tc == true);
    TS_ASSERT(fc == false);
    TS_ASSERT(!(def == def4))
  }

  void test_oper_not_equals()
  {
    const IntArray def({1, 2, 3});
    const IntArray def2({1, 2, 3});
    const IntArray def3({4, 5, 6});

    bool fc = def != def2;
    bool tc = def != def3;

    bool found_this_line_to_cover = def == def2;
    TS_ASSERT(found_this_line_to_cover == true);

    TS_ASSERT(tc == true);
    TS_ASSERT(fc == false);
  }
};

#endif
