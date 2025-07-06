// Написать программу для решения уравнения методом касательных(метод Ньютона).
// Для этого создать класс.Функцию, определяющую уравнение, и процедуру поиска корня реализовать в виде методов класса.
// Начальное приближение для корня реализовать в виде поля класса.
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

class newton
{
public:
    static double e;
    double a;
    double f(double x)
    {
        return pow(x, 7) - x + 1;
    }
    double df(double x)
    {
        return 7 * pow(x, 6) - 1;
    }
    double func()
    {
        while (abs(f(a)) > e)
        {
            a = a - f(a) / df(a);
        }
        return a;
    }
};
double newton::e;

int main()
{
    newton::e = 10e-6;
    newton number;
    number.a = 0;
    cout << "x = " << number.func() << endl; // x = -1.11278
}