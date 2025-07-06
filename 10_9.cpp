// Написать программу с классом для реализации выражения вида сумма a[i]*exp(-i*x)
// Путем перегрузки операторов предусмотреть возможность сложения,
// вычитания таких выражений,
// а также умножения и деления на число.Результат – объект того же класса, что и исходный.
#include <cmath>
#include <iostream>
using namespace std;
const int n = 2;

class Polynom
{
public:
  double a[n + 1];
  void show()
  {
    for (int i = 0; i <= n; ++i)
    {
      cout << "a[" << i << "] = " << a[i] << ",\t";
    }
    cout << endl;
  }
  double operator()(double x)
  {
    double res = 0;
    for (int i = 0; i <= n; ++i)
    {
      res += a[i] * exp(-i * x);
    }
    return res;
  }
};

Polynom operator+(Polynom x, Polynom y)
{
  Polynom res;
  for (int i = 0; i <= n; ++i)
  {
    res.a[i] = x.a[i] + y.a[i];
  }
  return res;
}

Polynom operator-(Polynom x, Polynom y)
{
  Polynom res;
  for (int i = 0; i <= n; ++i)
  {
    res.a[i] = x.a[i] - y.a[i];
  }
  return res;
}

Polynom operator*(Polynom x, double y)
{
  Polynom res;
  for (int i = 0; i <= n; ++i)
  {
    res.a[i] = x.a[i] * y;
  }
  return res;
}

Polynom operator/(Polynom x, double y)
{
  Polynom res;
  for (int i = 0; i <= n; ++i)
  {
    res.a[i] = x.a[i] / y;
  }
  return res;
}

int main()
{
  Polynom A, B;
  A.a[0] = 1.0;
  A.a[1] = -6;
  A.a[2] = -10;
  B.a[0] = -9;
  B.a[1] = 0;
  B.a[2] = 6;
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
// a[0] = 1,       a[1] = -6,      a[2] = -10,
// 0.959118
// a[0] = -9,      a[1] = 0,       a[2] = 6,
// -8.99973
// a[0] = -8,      a[1] = -6,      a[2] = -4,
// -8.04061
// a[0] = 10,      a[1] = -6,      a[2] = -16,
// 9.95885
// a[0] = 5,       a[1] = -30,     a[2] = -50,
// 4.79559
// a[0] = 0.2,     a[1] = -1.2,    a[2] = -2,
// 0.191824