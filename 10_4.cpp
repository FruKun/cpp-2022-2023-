// Написать программу с классами для реализации комплексных
// чисел в алгебраической и тригонометрической формах.Путем перегрузки
// операторов предусмотреть возможность возведения комплексного числа
// в алгебраическом представлении в целочисленную степень.Результат – число в тригонометрическом представлении.
#include <cmath>
#include <iostream>
using namespace std;
class ComplexAlg
{
public:
  double Re, Im;

  void show()
  {
    cout << Re;
    if (Im < 0)
    {
      cout << " - " << -Im << "i" << endl;
    }
    else
    {
      cout << " + " << Im << "i" << endl;
    }
  }
};

class ComplexGeom
{
public:
  double r, phi;

  void show() { cout << r << "e^(" << phi << "i)" << endl; }
};

ComplexGeom operator^(ComplexAlg x, int n)
{
  ComplexGeom res;
  res.r = pow(x.Re * x.Re + x.Im * x.Im, n / 2.0);
  res.phi = n * atan2(x.Im, x.Re);
  return res;
}

int main()
{
  ComplexAlg a = {1, 1};
  ComplexGeom b = a ^ 2;
  b.show(); // 2e^(1.5708i)
  return 0;
}
