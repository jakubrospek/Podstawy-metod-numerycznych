#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;

double f(double x)
{
       return cos(x)-x;
}

int main(int argc, char* argv[])
{
      double xOld, xNew, xl,xR, Error, Tol;
      int i;
      
      xl = 0.0;
      xR = 1.0;
      Tol = 0.00000001;
      xOld = xl;
      
      i = 0;
      do{
          xNew = (xl*f(xR)-xR*f(xl))/(f(xR)-f(xl));
          Error = fabs((xNew-xOld)/xNew);
          if((f(xl)*f(xNew))<=0.0)
          {
                                  xR=xNew;
          }
          else
          {
              xl=xNew;
          }
          xOld=xNew;
          i++;
          cout << setprecision(8) << "i= " << i << " : xNew= " << xNew << endl;
          } while(Error>Tol);

system("pause");
}
