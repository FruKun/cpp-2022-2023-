// Создать класс с перегруженным методом для решения уравнения методом половинного деления либо методом хорд
// (например, в зависимости от наличия или типа переданных аргументов).
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

class overload
{
public:
    static double e;
    double a, b;
    double f(double x)
    {
        return pow(x, 7) - x + 1;
    }

    void func(double c)
    {

        if (f(a) * f(b) > 0)
        {
            cout << "error/n";
        }
        while (b - a > e)
        {
            c = (a + b) / 2;
            if (f(b) * f(c) < 0)
                a = c;
            else
                b = c;
        }
        cout << " mtd plvn del: x = " << c << endl;
    }
    void func()
    {
        while (fabs(f(b)) > e)
        {
            a = b - ((b - a) * f(b)) / (f(b) - f(a));
            b = a - ((a - b) * f(a)) / (f(a) - f(b));
        }
        cout << " mtd hord: x = " << b << endl;
    }
};
double overload::e;

int main()
{
    overload::e = 10e-6;
    overload number;
    number.a = -2;
    number.b = 2;
    number.func(0);
    number.func();
}
// mtd plvn del: x = -1.11277
// mtd hord : x = -1.11278