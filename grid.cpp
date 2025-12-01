#include <iostream>
#include <limits>
#include <vector>
using namespace std;

void displayGrid(const vector<vector<bool>> &grid)
{
  for (const auto &row : grid)
  {
    for (bool cell : row)
    {
      cout << (cell ? 'X' : '.');
    }
    cout << endl;
  }
}

int main()
{
  const string prompt = "Enter row and column:";
  const unsigned int grid_size = 5;

  vector<vector<bool>> grid(grid_size, vector<bool>(grid_size, false));

  while (true)
  {
    int row, col;
    cout << prompt << endl;

    if (cin >> row >> col)
    {
      if (row >= 0 && col >= 0 &&
          static_cast<unsigned int>(row) < grid_size &&
          static_cast<unsigned int>(col) < grid_size)
      {
        grid[row][col] = true;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        continue;
      }
      else
      {
        displayGrid(grid);
        break;
      }
    }
    else
    {
      displayGrid(grid);
      break;
    }
  }

  return 0;
}