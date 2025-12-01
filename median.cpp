#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main()
{
  const string error_message = "Invalid input.";

  double read_in;

  vector<double> numbers;

  while (cin >> read_in)
  {
    // if (cin.fail())
    // {
    //   cout << error_message << endl;
    //   cin.clear();
    //   break;
    // }

    numbers.push_back(read_in);
  }

  if (numbers.size() == 0)
  {
    cout << error_message << endl;
    return 0;
  }

  if (numbers.size() % 2 == 0)
  {
    cout << fixed << setprecision(2) << (numbers[(numbers.size() / 2) - 1] + numbers[numbers.size() / 2]) / 2 << endl;
  }
  else
  {
    cout << fixed << setprecision(2) << numbers[numbers.size() / 2] << endl;
  }

  return 0;
}
