#include <iostream>
#include <iomanip>
using namespace std;

int
main()
{
  const string error_message = "Invalid input.";

  cout << "Enter the circle's radius:" << endl;

  const double pi = 3.141592653589793;

  double radius;
  if (cin >> radius) {
    if (radius >= 0.0) {
      cout << setprecision(3) << "Diameter: " << 2 * radius << endl;
      cout << setprecision(3) << "Circumference: " << 2 * pi * radius << endl;
      cout << setprecision(3) << "Area: " << pi * radius * radius << endl;
    } else {
      cout << error_message << endl;
      return -1;
    }
  } else {
    cout << error_message << endl;
    return -1;
  }

  return 0;
}
