#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double f(double x)
{
       return x*x-2.0*x-2.0;
}

double fp(double x)
{
       return 2.0*x-2.0;
}

int main(int argc, char argv[])
{
    double xOld, xNew,xR,xl,Error,Tol;
    double LeftTerm, RightTerm;
    
    Tol = 0.00000001;
    xl = 0.0;
    xR = 3.0;
    xOld = xl;
    
    do
    {
         LeftTerm = (xOld - xl)*fp(xOld)-f(xOld);
         RightTerm = (xOld-xR)*fp(xOld)-f(xOld);
         
         if((LeftTerm*RightTerm)<0.0)
         {
                                     xNew = xOld - (f(xOld)/fp(xOld));
                                     cout << "Newton Raphson xNew " << setprecision(8) << xNew << endl;
         }
         else
         {
             xNew = ((xl+xR)/2.0);
             cout << "Bisection xNew " << setprecision(8) << xNew << endl;
         }
         
         if((f(xNew)*f(xl))<0.0)
         {
                                xR = xNew;
         }
         else
         {
             xl = xNew;
         }
         
         Error = fabs((xNew-xOld)/xNew);
         xOld = xNew;
         }while(Error>Tol);
 system("pause");        
}
