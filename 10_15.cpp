// Написать программу с классом для реализации выражения вида сумма (a[k]/x**k) + сумма (b[k]*x**k)
// Путем перегрузки операторов предусмотреть возможность сложения, вычитания таких выражений, а также умножения и деления на число.
// Результат – объект того же класса, что и исходный.
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
// a[1] = 1,       a[2] = -6,      b[0] = 8,       b[1] = 9,       b[2] = 8
// 252.96
// a[1] = -9,      a[2] = 0,       b[0] = 8,       b[1] = 4,       b[2] = 2
// 76.2
// a[1] = -8,      a[2] = -6,      b[0] = 16,      b[1] = 13,      b[2] = 10
// 329.16
// a[1] = 10,      a[2] = -6,      b[0] = 0,       b[1] = 5,       b[2] = 6
// 176.76
// a[1] = 5,       a[2] = -30,     b[0] = 40,      b[1] = 45,      b[2] = 40
// 1264.8
// a[1] = 0.2,     a[2] = -1.2,    b[0] = 1.6,     b[1] = 1.8,     b[2] = 1.6
// 50.592