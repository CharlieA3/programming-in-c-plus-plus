#include <iostream>
#include <string>
using namespace std;

int main()
{
  const string prompt_fizz = "Enter the fizz number:";
  const string prompt_buzz = "Enter the buzz number:";
  const string error_message = "Invalid input.";

  int fizz_num;
  int buzz_num;

  cout << prompt_fizz << endl;
  if (!(cin >> fizz_num) || fizz_num <= 0)
  {
    cout << error_message << endl;
    return 255;
  }

  cout << prompt_buzz << endl;
  if (!(cin >> buzz_num) || buzz_num <= 0)
  {
    cout << error_message << endl;
    return 255;
  }

  for (int i = 1; i < 21; i++)
  {
    if (i % fizz_num == 0 && i % buzz_num == 0)
    {
      cout << "FizzBuzz" << endl;
    }
    else if (i % fizz_num == 0)
    {
      cout << "Fizz" << endl;
    }
    else if (i % buzz_num == 0)
    {
      cout << "Buzz" << endl;
    }
    else
    {
      cout << i << endl;
    }
  }
  return 0;
}
