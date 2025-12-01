#include "DLLDeque.hpp"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  DLLDeque<string> d;
  d.push_back("a");
  d.push_back("b");
  d.push_back("c");
  d.push_back("d");

  cout << "for_each:";
  for_each(d.begin(), d.end(), [](string x){ cout << " " << x; });
  cout << endl;
}
