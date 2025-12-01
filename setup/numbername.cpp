#include <iostream>
#include <string>
using namespace std;

int
main()
{
  const string error_message = "Invalid input.";

  const string name1 = "one";
  const string name2 = "two";
  const string name3 = "three";

  int number;
  if (cin >> number) {
    switch(number) {
    case 1:
      cout << name1 << endl;
      break;
    case 2:
      cout << name2 << endl;
      break;
    case 3:
      cout << name3 << endl;
      break;
    default:
      cout << error_message << endl;
      return -1;
    }
  } else {
    cout << error_message << endl;
    return -1;
  }
  
  return 0;
}
