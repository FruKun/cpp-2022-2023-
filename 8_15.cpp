#include <cmath>
#include <iostream>
using namespace std;
int const N = 6;
class derivative
{
public:
  double e = 1e-6;
  double a[N];
  double f(double x)
  {
    double res = 0;
    for (int i = 0; i < N; ++i)
    {
      res += a[i] * cos(i * x);
    }
    return res;
  }
  double checkderF(double x)
  {
    double res = 0;
    for (int i = 0; i < N; ++i)
    {
      res -= a[i] * sin(i * x) * i;
    }
    return res;
  }
  double derF(double x) { return (f(x + e) - f(x - e)) / (2 * e); }
};

int main()
{
  derivative obj;
  for (int i = 0; i < N; ++i)
  {
    obj.a[i] = i;
  }
  double x = 1;
  cout << "Result: " << obj.derF(x) << endl;
  cout << "Check: " << obj.checkderF(x) << endl;
}
