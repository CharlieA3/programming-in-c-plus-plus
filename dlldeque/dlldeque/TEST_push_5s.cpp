#include "DLLDeque.hpp"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  DLLDeque<string> d;
  d.push_back("c");
  d.push_front("b");
  d.push_back("d");
  d.push_front("a");
  d.debug_print();
}
