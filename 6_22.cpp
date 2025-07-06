// Написать программу для решения уравнения вида sh(x)=a.
// Использовать структуры.Предусмотреть все возможные ситуации.
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

struct complex
{
    double Re, Im;
};

void show(complex z)
{
    if (z.Im >= 0)
    {
        std::cout << z.Re << "+i" << z.Im << std::endl;
    }
    else
    {
        std::cout << z.Re << "-i" << -z.Im << std::endl;
    }
}

void F(double a, int k)
{
    // x = ln(a+sqrt(a^2+1))+PI*k*i, k in R
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
    // sh(x) = a
    double a = 1;
    int k = 1;
    F(a, k);
    return 0;
}

// 0.881374+i6.28319
// - 0.881374 + i9.42478