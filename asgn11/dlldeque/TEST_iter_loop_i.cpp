#include "DLLDeque.hpp"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  DLLDeque<int> d;
  d.push_back(10);
  d.push_back(10);
  d.push_back(20);
  d.push_back(20);
  d.push_back(30);
  d.push_back(30);
  d.push_back(40);
  d.push_back(40);

  cout << "loop:";
  for (auto it = d.begin(); it != d.end(); ++ it) {
    cout << " " << *it;
  }
  cout << endl;
}
