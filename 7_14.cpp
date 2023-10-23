#include <iostream>

using namespace std;

class Shoots
{
    bool x = false;
    void f(double p, int n){
        
    }
public:
    double p;
    void shoot(int n)
    {
        if (x == true)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
};

int main()
{
    Shoots a;
    a.p = 0.3;
    int n = 10;
    a.shoot(n);
}