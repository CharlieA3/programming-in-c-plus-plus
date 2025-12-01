#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string input;

  vector<string> lines;

  while (getline(cin, input))
  {
    lines.push_back(input);
  }

  for (int i = lines.size() - 1; i >= 0; i--)
  {
    for (int j = lines[i].size() - 1; j >= 0; j--)
    {
      cout << lines[i][j];
    }
    cout << endl;
  }

  return 0;
}
