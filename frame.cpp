#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string text;
  size_t max_line_size = 0;

  vector<string> lines;
  vector<int> size_of_line;
  size_t num_of_spaces_needed;

  while (getline(cin, text))
  {
    if (text.size() > max_line_size)
    {
      max_line_size = text.size();
    }
    size_of_line.push_back(text.size());
    lines.push_back(text);
  }

  // border on top
  for (size_t j = 0; j < max_line_size + 4; j++)
  {
    cout << "*";
  }
  cout << endl;

  for (size_t i = 0; i < lines.size(); i++)
  {
    num_of_spaces_needed = max_line_size - size_of_line[i];

    cout << "* " << lines[i];
    for (size_t j = 0; j < num_of_spaces_needed; j++)
    {
      cout << " ";
    }
    cout << " *" << endl;
  }

  // border on bottom
  for (size_t j = 0; j < max_line_size + 4; j++)
  {
    cout << "*";
  }
  cout << endl;

  return 0;
}
