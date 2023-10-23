#include <iostream>
using namespace std;
class Vector
{
public:
  double x, y, z;
  double Mul(Vector a, Vector b)
  {
    // a.x | a.y | a.z
    // b.x | b.y | b.z
    //   x |   y |   z
    return a.x * b.y * z + b.x * y * a.z + a.y * b.z * x - (a.z * b.y * x + b.z * y * a.x + b.x * a.y * z);
  }
};

int main()
{
  Vector a{3, 0, 0};
  Vector b{0, 9, 0};
  Vector c{0, 0, 2};
  cout << a.Mul(b, c) << endl;
}
