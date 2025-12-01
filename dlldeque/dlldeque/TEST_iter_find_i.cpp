#include "DLLDeque.hpp"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  DLLDeque<int> d;
  d.push_back(10);
  d.push_back(20);
  d.push_back(30);
  d.push_back(40);

  cout << "find: " << ((find(d.begin(), d.end(), 10) == d.end()) ? "not found" : "found") << endl;
  cout << "find: " << ((find(d.begin(), d.end(), 20) == d.end()) ? "not found" : "found") << endl;
  cout << "find: " << ((find(d.begin(), d.end(), 50) == d.end()) ? "not found" : "found") << endl;
}
