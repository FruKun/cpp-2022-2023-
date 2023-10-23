#include <cstdlib>
#include <iostream>
using namespace std;
const int n = 3;

class Vector
{
  double A[n][n], Z[n], F[n];
  void generateMatrix()
  {
    srand(time(0));
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        A[i][j] = rand() % 10;
      }
    }
  }
  double f(int i)
  {
    double res = 0;
    for (int j = 0; j < n; ++j)
    {
      res += A[i][j] * Z[j];
    }
    return res;
  }
  void set()
  {
    generateMatrix();
    for (int i = 0; i < n; ++i)
    {
      F[i] = f(i);
    }
  }

public:
  double *operator()(double z)
  {
    double q = 1;
    for (int i = 0; i < n; ++i)
    {
      Z[i] = q;
      q *= z;
    }
    set();
    return F;
  }
};

int main()
{
  Vector F;
  double x = 5;
  cout << "F(" << x << "):\n";
  for (int i = 0; i < n; i++)
  {
    cout << F(x)[i] << "\n";
  }
  cout << endl;
  return 0;
}
