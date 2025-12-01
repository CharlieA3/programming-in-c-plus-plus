#include "DLLDeque.hpp"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  DLLDeque<string> d;
  d.push_front("d");
  d.push_front("c");
  d.push_front("b");
  d.push_front("a");
  d.debug_print();
}
