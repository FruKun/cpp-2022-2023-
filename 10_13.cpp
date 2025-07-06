// Написать программу с классом для реализации выражения вида сумма (a[k]*sh(k*x) +b[k]*ch(k*x))
// Путем перегрузки операторов
// предусмотреть возможность сложения, вычитания таких выражений, а также умножения и деления на число. Результат – объект того же класса, что
// и исходный.
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
    for (int i = 0; i <= n; ++i)
    {
      cout << "a[" << i << "] = " << a[i] << ", b[" << i << "] = " << b[i] << ",\t";
    }
    cout << endl;
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

Polynom operator+(Polynom x, Polynom y)
{
  Polynom res;
  for (int i = 0; i <= n; ++i)
  {
    res.a[i] = x.a[i] + y.a[i];
    res.b[i] = x.b[i] + y.b[i];
  }
  return res;
}

Polynom operator-(Polynom x, Polynom y)
{
  Polynom res;
  for (int i = 0; i <= n; ++i)
  {
    res.a[i] = x.a[i] - y.a[i];
    res.b[i] = x.b[i] - y.b[i];
  }
  return res;
}

Polynom operator*(Polynom x, double y)
{
  Polynom res;
  for (int i = 0; i <= n; ++i)
  {
    res.a[i] = x.a[i] * y;
    res.b[i] = x.b[i] * y;
  }
  return res;
}

Polynom operator/(Polynom x, double y)
{
  Polynom res;
  for (int i = 0; i <= n; ++i)
  {
    res.a[i] = x.a[i] / y;
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
  A.a[2] = -10;
  B.b[2] = 7;
  B.a[0] = -9;
  B.b[0] = 8;
  B.a[1] = 0;
  B.b[1] = 4;
  B.a[2] = 6;
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
// a[0] = 1, b[0] = 8,     a[1] = -6, b[1] = 9,    a[2] = -10, b[2] = -1.86968e-174,
// -109902
// a[0] = -9, b[0] = 8,    a[1] = 0, b[1] = 4,     a[2] = 6, b[2] = 2,
// 88410.7
// a[0] = -8, b[0] = 16,   a[1] = -6, b[1] = 13,   a[2] = -4, b[2] = 2,
// -21491
// a[0] = 10, b[0] = 0,    a[1] = -6, b[1] = 5,    a[2] = -16, b[2] = -2,
// -198312
// a[0] = 5, b[0] = 40,    a[1] = -30, b[1] = 45,  a[2] = -50, b[2] = -9.34839e-174,
// -549508
// a[0] = 0.2, b[0] = 1.6, a[1] = -1.2, b[1] = 1.8,        a[2] = -2, b[2] = -3.73936e-175,
// -21980.3