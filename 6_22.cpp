#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

struct complex
{
    double Re, Im;
};

void show(complex z)
{
    if (z.Im >= 0)
    {
        cout << z.Re << "+i" << z.Im << endl;
    }
    else
    {
        cout << z.Re << "-i" << -z.Im << endl;
    }
}

void F(double a, int k)
{
    complex z;
    z.Re = log(a + sqrt(a * a + 1));
    z.Im = 2 * M_PI * k;
    show(z);
    z.Re = log(sqrt(a * a + 1) - a);
    z.Im = M_PI * (1 + 2 * k);
    show(z);
}

int main()
{
    double a = 1;
    int k=1;
    F(a, k);
    return 0;
}