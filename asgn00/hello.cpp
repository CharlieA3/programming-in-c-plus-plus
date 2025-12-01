#include <iostream>
#include <string>
using namespace std;

int main()
{
  const string error_message = "Invalid input.";

  cout << "Please enter your name:" << endl;

  string name;
  if (getline(cin, name)) {
    cout << "Hello, " << name << "!" << endl;
  } else {
    cout << error_message << endl;
    return -1;
  }

  return 0;
}
