#include "DLLDeque.hpp"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  DLLDeque<string> d;
  d.push_back("a");
  d.debug_print();
}
