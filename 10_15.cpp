#include <cmath>
#include <iostream>
using namespace std;
const int n = 2;

class Polynom
{
public:
  double a[n];
  double b[n + 1];
  void show()
  {
    for (int i = 0; i < n; ++i)
    {
      cout << "a[" << i + 1 << "] = " << a[i] << ",\t";
    }
    for (int i = 0; i < n; i++)
    {
      cout << "b[" << i << "] = " << b[i] << ",\t";
    }
    cout << "b[" << n << "] = " << b[n];
    cout << endl;
  }
  double operator()(double x)
  {
    double res = 0;
    for (int i = 0; i < n; ++i)
    {
      res += a[i] / pow(x, i + 1);
    }
    for (int i = 0; i <= n; ++i)
    {
      res += b[i] * pow(x, i);
    }
    return res;
  }
};

Polynom operator+(Polynom x, Polynom y)
{
  Polynom res;
  for (int i = 0; i < n; ++i)
  {
    res.a[i] = x.a[i] + y.a[i];
  }
  for (int i = 0; i <= n; ++i)
  {
    res.b[i] = x.b[i] + y.b[i];
  }
  return res;
}

Polynom operator-(Polynom x, Polynom y)
{
  Polynom res;
  for (int i = 0; i < n; ++i)
  {
    res.a[i] = x.a[i] - y.a[i];
  }
  for (int i = 0; i <= n; ++i)
  {
    res.b[i] = x.b[i] - y.b[i];
  }
  return res;
}

Polynom operator*(Polynom x, double y)
{
  Polynom res;
  for (int i = 0; i < n; ++i)
  {
    res.a[i] = x.a[i] * y;
  }
  for (int i = 0; i <= n; ++i)
  {
    res.b[i] = x.b[i] * y;
  }
  return res;
}

Polynom operator/(Polynom x, double y)
{
  Polynom res;
  for (int i = 0; i < n; ++i)
  {
    res.a[i] = x.a[i] / y;
  }
  for (int i = 0; i <= n; ++i)
  {
    res.b[i] = x.b[i] / y;
  }
  return res;
}

int main()
{
  Polynom A, B;
  A.a[0] = 1.0;
  A.b[0] = 8;
  A.a[1] = -6;
  A.b[1] = 9;
  A.b[2] = 8.0;
  B.a[0] = -9;
  B.b[0] = 8;
  B.a[1] = 0;
  B.b[1] = 4;
  B.b[2] = 2;
  A.show();
  cout << A(5) << endl;
  B.show();
  cout << B(5) << endl;
  (A + B).show();
  cout << (A + B)(5) << endl;
  (A - B).show();
  cout << (A - B)(5) << endl;
  (A * 5).show();
  cout << (A * 5)(5) << endl;
  (A / 5).show();
  cout << (A / 5)(5) << endl;
  return 0;
}
