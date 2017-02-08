#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double f(double x)
{
       //return cos(x)-x;                                                                            //  pierwsza czêœæ
       return (6435.0*pow(x,8)-12012.0*pow(x,6)+6930.0*pow(x,4)-1260.0*pow(x,2)+35.0)/128.0;        // druga czêœæ
}

double fp(double x)
{
       //return (-1.0*sin(x)-1.0);                                                                 //  pierwsza czêœæ
       return (6435.0*8.0*pow(x,7)-12012.0*6.0*pow(x,5)+6930.0*4.0*pow(x,3)-1260.0*2.0*x)/128.0; // druga czêœæ
}

int main(int argc, char *argv[])
{
    
    double xNew, xO1d,Tol,Error;
    int i;
    cout << "enter x0: " << endl;
    cin >> xO1d;
    Tol = 0.00000001;
    i = 0;
    do
    {
        xNew = xO1d-(f(xO1d)/fp(xO1d));
        Error = fabs((xNew-xO1d)/(xNew));
        i++;
        xO1d=xNew;
    }
    
    while(Error>Tol);
    
    cout << "Root found at " << setprecision(8) << xNew << endl;
    
    system("pause");
    return 0;
}
