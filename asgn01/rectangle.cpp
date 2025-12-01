#include <iostream>
#include <string>
using namespace std;

int main()
{
  const string prompt_width = "Enter width:";
  const string prompt_height = "Enter height:";
  const string error_message = "Invalid input.";

  int W;
  int H;
  cout << prompt_width << endl;

  if (!(cin >> W) || W <= 0 || W >= 21)
  {
    cout << error_message << endl;
    return 255;
  }

  cout << prompt_height << endl;

  if (!(cin >> H) || H <= 0 || H >= 21)
  {
    cout << error_message << endl;
    return 255;
  }

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cout << "X";
    }
    cout << "\n";
  }
  return 0;
}
