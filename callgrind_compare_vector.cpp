#include <iostream>
#include <vector>
using namespace std;

const int iterations = 10000000;

void run_vector_at(vector<int> &access)
{
  access.at(0);
}

void run_vector_brackets(vector<int> &access)
{
  access[0];
}

int main()
{
  vector<int> access_this;

  access_this.push_back(50);

  for (int i = 0; i < iterations; i++)
  {
    run_vector_at(access_this);
    run_vector_brackets(access_this);
  }
}
