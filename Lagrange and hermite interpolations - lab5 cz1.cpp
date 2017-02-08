#include<iostream>                          // LAGRANGE
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;

double f(double x)
{
       return exp(x);
}



int main(int argc, char *argv[])
{
    double xT[4];
    double x,h;
    double p,l_jn;
    int n;
    
    n = 4;
    xT[0]=-1.0;
    xT[1]=0.5;
    xT[2]=1.5;
    xT[3]=2.0;
    h=0.1;
    
    x=-5.0;
    do
    {
           p=0.0;
           for(int j=0; j<n; j++)
           {
                   l_jn=1.0;
                   for(int i=0; i<n; i++)
                   {
                           if(i!=j) l_jn=l_jn*((x-xT[i])/(xT[j]-xT[i]));
                   }
                   p=p+l_jn*f(xT[j]);
           }
           
           cout << "x= " << x << " : p(x)= " << p <<endl;
           x=x+h;
           } while(x<=5.0);
           system("pause");
                           }
