#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main()
{
  const string prompt_function = "Enter a function name:";
  const string prompt_value = "Enter a value:";
  const string error_message = "Invalid input.";

  string W;
  double X;

  cout << prompt_function << endl;

  if (!(cin >> W) || (W != "sin" && W != "cos"))
  {
    cout << error_message << endl;
    return 255;
  }

  cout << prompt_value << endl;

  if (!(cin >> X))
  {
    cout << error_message << endl;
    return 255;
  }

  if (W == "sin")
  {
    cout << setprecision(3) << sin(X) << endl;
  }
  else if (W == "cos")
  {
    cout << setprecision(3) << cos(X) << endl;
  }

  return 0;
}
