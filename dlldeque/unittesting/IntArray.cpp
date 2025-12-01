#include "IntArray.hpp"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <utility>
using namespace std;

IntArray::IntArray():
  IntArray(0)
{
}

IntArray::IntArray(size_t sz):
  m_arr(new int[sz]),
  m_sz(sz)
{
  memset(m_arr, 0, sizeof(int) * m_sz);
}

IntArray::IntArray(const initializer_list<int> & lst):
  m_arr(new int[lst.size()]),
  m_sz(lst.size())
{
  size_t ii = 0;
  for (int elem: lst) {
    m_arr[ii] = elem;
    ++ ii;
  }
}

IntArray::IntArray(const IntArray & o):
  m_arr(new int[o.m_sz]),
  m_sz(o.m_sz)
{
  memcpy(m_arr, o.m_arr, sizeof(int) * m_sz);
}

IntArray::IntArray(IntArray && o):
  m_arr(o.m_arr),
  m_sz(o.m_sz)
{
  o.m_arr = nullptr;
  o.m_sz = 0;
}

IntArray::~IntArray() {
  delete [] m_arr;
}

const int *IntArray::ptr() const {
  return m_arr;
}

size_t IntArray::size() const {
  return m_sz;
}

IntArray & IntArray::operator=(const IntArray & o) {
  if (this != &o) {
    if (m_sz != o.m_sz) {
      delete [] m_arr;
      m_arr = new int[o.m_sz];
      m_sz = o.m_sz;
    }
    memcpy(m_arr, o.m_arr, sizeof(int) * m_sz);
  }
  return *this;
}

IntArray & IntArray::operator=(IntArray && o) {
  if (this != &o) {
    delete [] m_arr;
    m_arr = o.m_arr;
    m_sz = o.m_sz;
    o.m_arr = nullptr;
    o.m_sz = 0;
  }
  return *this;
}

int & IntArray::operator[](size_t ind) {
  if (ind >= m_sz) {
    throw out_of_range("out of range");
  }
  return m_arr[ind];
}

const int & IntArray::operator[](size_t ind) const {
  if (ind >= m_sz) {
    throw out_of_range("out of range");
  }
  return m_arr[ind];
}

bool operator==(const IntArray & lhs, const IntArray & rhs) {
  if (lhs.m_sz != rhs.m_sz) {
    return false;
  }

  for (size_t ii = 0; ii < lhs.m_sz; ++ ii) {
    if (lhs.m_arr[ii] != rhs.m_arr[ii]) {
      return false;
    }
  }

  return true;
}

bool operator!=(const IntArray & lhs, const IntArray & rhs) {
  return !(lhs == rhs);
}
