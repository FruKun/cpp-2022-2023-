// Написать программу для вычисления ряда sin(x)/x
// Необходимо создать специальный класс с соответствующим методом.
// Аргумент x и верхняя граница ряда определяются как поля класса.
// Рассмотреть случай, когда поле, определяющее границу ряда, является статическим.
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
double fact(double a)
{
    if (a < 0)
        return 0;
    if (a == 0)
        return 1;
    return a * fact(a - 1);
}
class Sin_x
{
public:
    static int N;
    double x;

    double func()
    {
        double s;
        for (int i = 0; i <= N; i++)
        {
            s += (pow(-1, i) * pow(x, 2 * i)) / fact(2 * i + 1);
        }
        return s;
    }
};
int Sin_x::N;

int main()
{
    Sin_x::N = 100;
    Sin_x a;
    a.x = 5;
    cout << a.func() << endl;       // -0.191785
    cout << sin(a.x) / a.x << endl; // -0.191785
}