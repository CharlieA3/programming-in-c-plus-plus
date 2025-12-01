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
	
  cout << "for_each:";
  for_each(d.begin(), d.end(), [](int x){ cout << " " << x; });
  cout << endl;
}
