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

  cout << "find: " << ((find(d.begin(), d.end(), "a") == d.end()) ? "not found" : "found") << endl;
  cout << "find: " << ((find(d.begin(), d.end(), "b") == d.end()) ? "not found" : "found") << endl;
  cout << "find: " << ((find(d.begin(), d.end(), "e") == d.end()) ? "not found" : "found") << endl;
}
