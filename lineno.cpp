#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
  string input;
  int line_num = 1;

  while (true)
  {
    if (!getline(cin, input))
    {
      if (cin.eof())
      {
        break;
      }
      else if (cin.bad())
      {
        cerr << "Error with stream." << endl;
        return 255;
      }
      else if (cin.fail())
      {
        cerr << "Error with input." << endl;
        return 255;
      }
    }

    cout << setw(3) << line_num << ": " << input << endl;

    line_num += 1;
  }
}
