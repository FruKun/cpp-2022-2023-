// Написать программу для вычисления матричного синуса
// Необходимо создать специальный класс с соответствующим методом
#include <cmath>
#include <iostream>
using namespace std;
const int M = 3;
double fact(double x)
{
  if (x <= 1)
    return 1;
  return fact(x - 1) * x;
}
class Matrix
{
public:
  double a[M][M];
  Matrix sum(Matrix m)
  {
    Matrix res;
    for (int i = 0; i < M; i++)
      for (int j = 0; j < M; j++)
        res.a[i][j] = a[i][j] + m.a[i][j];
    return res;
  }
  Matrix div(int num)
  {
    Matrix res;
    for (int i = 0; i < M; i++)
      for (int j = 0; j < M; j++)
        res.a[i][j] = a[i][j] / num;
    return res;
  }
  Matrix mult(Matrix m)
  {
    Matrix res = m;
    for (int i = 0; i < M; i++)
      for (int j = 0; j < M; j++)
      {
        res.a[i][j] = 0.;
        for (int k = 0; k < M; k++)
          res.a[i][j] += a[i][k] * m.a[k][j];
      }
    return res;
  }
  void show()
  {
    for (int i = 0; i < M; i++)
    {
      for (int j = 0; j < M - 1; j++)
      {
        cout << a[i][j] << ", ";
      }
      cout << a[i][M - 1] << "\n";
    }
    cout << "\n";
  }

  Matrix sinm(Matrix obj)
  {
    Matrix res = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
    int N = 100;
    for (int k = 1; k < N; k++)
    {
      Matrix q = obj;
      for (int i = 1; i < 2 * k + 1; i++)
        q = q.mult(obj);
      q = q.div(fact(2 * k + 1) * pow(-1, k));
      res = res.sum(q);
    }
    res = res.sum(obj);
    return res;
  }
};

int main()
{
  Matrix a{{{M_PI / 123, 0, 0}, {0, M_PI / 123, 0}, {0, 0, M_PI / 123}}};
  a.sinm(a).show();
  cout << sin(M_PI / 123) << endl;
  return 0;
}
// 0.0255386, 0, 0
// 0, 0.0255386, 0
// 0, 0, 0.0255386

// 0.0255386