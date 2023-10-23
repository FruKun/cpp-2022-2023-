#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

class hord
{
public:
    static double e;
    double a, b;
    double f(double x)
    {
        return pow(x, 7) - x + 1;
    }
    double func()
    {
        while (fabs(f(b)) > e)
        {
            a = b - ((b - a) * f(b)) / (f(b) - f(a));
            b = a - ((a - b) * f(a)) / (f(a) - f(b));
        }
        return b;
    }
};
double hord::e;

int main()
{
    hord::e = 10e-3;
    hord number;
    number.a = -2;
    number.b = 2;
    cout << "x = " << number.func() << endl;
}