#include <iostream>
using namespace std;

int main()
{
  double sum = 0;
  int num;

  // this basically says if what is entered is not a integer, fail (new lines and numbers are ok)
  while (cin >> num)
  {
    sum += num;
  }

  cout << sum << endl;
  return 0;
}
