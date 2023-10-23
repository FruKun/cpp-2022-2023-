#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
double fact(double a){
        if (a<0) return 0;
        if (a==0) return 1;
        return a*fact(a-1);
    }
class Cosh
{
    public:
    static int N;
    double x;
 
    double func(){
        double s;
        for (int i = 0; i<=N; i++){
            s+=pow(x,2*i)/fact(2*i);
        }
        return s;
    } 
};
int Cosh::N;
 
int main()
{
    Cosh::N=100;
    Cosh a;
    a.x = 5;
    cout << a.func() << endl;
    cout << cosh(a.x) << endl;
}