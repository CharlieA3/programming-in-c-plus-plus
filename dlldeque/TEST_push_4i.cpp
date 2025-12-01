#include "DLLDeque.hpp"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  DLLDeque<int> d;
  d.push_front(40);
  d.push_front(30);
  d.push_front(20);
  d.push_front(10);
  d.debug_print();
}
