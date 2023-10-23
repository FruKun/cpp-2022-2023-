#include <cmath>
#include <iostream>
using namespace std;
class Complex
{
public:
  double r, phi;

  void show()
  {

    cout << r << "e^(" << phi << "i)" << endl;
  }
};

Complex operator-(Complex x, Complex y)
{
  Complex res;
  res.r = sqrt(x.r * x.r + y.r * y.r - 2 * x.r * y.r * cos(x.phi - y.phi));
  res.phi = atan2(x.r * sin(x.phi) - y.r * sin(y.phi),
                  x.r * cos(x.phi) - y.r * cos(y.phi));
  return res;
}

Complex operator+(Complex x, Complex y)
{
  Complex res;
  res.r = sqrt(x.r * x.r + y.r * y.r + 2 * x.r * y.r * cos(x.phi - y.phi));
  res.phi = atan2(x.r * sin(x.phi) + y.r * sin(y.phi),
                  x.r * cos(x.phi) + y.r * cos(y.phi));
  return res;
}

Complex operator+(Complex x, double y)
{
  Complex res;
  res.r = y;
  return x + res;
}
Complex operator-(Complex x, double y)
{
  Complex res;
  res.r = y;
  return x - res;
}

int main()
{
  Complex A{5, M_PI / 3};
  Complex B{1, M_PI / 6};
  (A + B).show();
  (A - B).show();
  (A + 3).show();
  (A - 3).show();
  return 0;
}
