#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<iomanip>

using namespace std;

double f(double x)
{
       return cos(x)-x;
}

int main(int argc, char *argv[])
{
    double xl, xr, xn, error, Tol;
    int i;
    xl=0.0;
    xr=1.0;
    Tol=0.00000001;
    i=0;
    do{
        xn=(xr+xl)/2.0;
        if((f(xl)*f(xn))<=0.0)
        {
                              xr=xn;
        }
        else
        {
            xl=xn;
        }
        error=fabs((xr-xl)/xn);
        i++;
        }
        while(error>Tol);
        cout << "Root found at " << setprecision(8) << xn << endl;
        cout << "number of iterations: " << i << endl;
        
        system("pause");
        return 0;
}
