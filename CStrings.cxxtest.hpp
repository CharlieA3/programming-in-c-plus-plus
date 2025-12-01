#include <cxxtest/TestSuite.h>
#include <cstring>
#include <iostream>

class CStrings : public CxxTest::TestSuite
{
  static const size_t BUF_SIZE = 1024;
  char * m_buffer;

public:

  void setUp() {
    std::cout << "setUp" << std::endl;
    m_buffer = new char[BUF_SIZE];
  }

  void tearDown() {
    std::cout << "tearDown" << std::endl;
    delete [] m_buffer;
  }

  void testStrcpy()
  {
    strncpy(m_buffer, "Hello, world!", BUF_SIZE);
    TS_ASSERT_SAME_DATA(m_buffer, "Hello, world!", 14);
  }

  void testStrcmp()
  {
    TS_ASSERT(strcmp("AAA", "BBB") < 0);
    TS_ASSERT(strcmp("aaa", "BBB") > 0);
    TS_ASSERT(strcmp("xyz", "xyz") == 0);
  }

};
