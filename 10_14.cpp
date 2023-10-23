#include <cmath>
#include <iostream>
using namespace std;
const int n = 2;

class Polynom
{
public:
  double a[n + 1];
  double b[n + 1];
  void show()
  {
    for (int i = 0; i < n; ++i)
    {
      cout << "a[" << i << "] = " << a[i] << ",\t";
    }
    for (int i = 0; i < n; i++)
    {
      cout << "b[" << i << "] = " << b[i] << ",\t";
    }
    cout << endl;
  }
  Polynom operator,(int k)
  {
    Polynom res;
    if (k % 2 == 0)
    {
      for (int j = 0; j <= n; ++j)
      {
        res.a[j] = a[j] * pow(j, k);
        res.b[j] = b[j] * pow(j, k);
      }
    }
    else
    {
      for (int j = 0; j <= n; ++j)
      {
        res.a[j] = b[j] * pow(j, k);
        res.b[j] = a[j] * pow(j, k);
      }
    }
    return res;
  }

  double operator()(double x)
  {
    double res = 0;
    for (int i = 0; i <= n; ++i)
    {
      res += a[i] * sinh(i * x) + b[i] * cosh(i * x);
    }
    return res;
  }
};

int main()
{
  Polynom A;
  A.a[0] = 1.0;
  A.b[0] = 8;
  A.a[1] = -6;
  A.b[1] = 9;
  A.a[2] = -10;
  A.b[2] = 6;
  A.show();
  cout << A(1) << endl;
  (A, 1).show();
  cout << (A, 1)(1) << endl;
  (A, 2).show();
  cout << (A, 2)(1) << endl;
  (A, 0).show();
  cout << (A, 0)(1) << endl;

  return 0;
}
