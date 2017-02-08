#include <iostream>                         // HERMITE
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double x)
{
	return exp(x);
}
double fp(double x)
{
	return exp(x);
}
int main(int argc, char *argv[])
{
	double xT[4];
	double x, h;
	double p, l_jn, l_jnPrime;
	double h_jn, h_jnBar;
	int n;

	//Initial values

	n = 4;
	xT[0] = -1.0;
	xT[1] = 0.5;
	xT[2] = 1.5;
	xT[3] = 2.0;

	h = 0.1;

	//Hermite
	x = -5.0;
	do // loop over from x = -5 to x = 5
	{
		p = 0.0;
		for(int j = 0; j < n; j++) //Loop to calculate sum over j
		{
			l_jn = 1.0;
			l_jnPrime = 0.0;

			for(int i = 0; i < n; i++) // Loop to calculates productr and sum over i
			{
				if(i != j)
				{
					l_jn = l_jn * ((x - xT[i])/(xT[j]-xT[i])); //calculate l_jn
					l_jnPrime = l_jnPrime + (1.0 / (xT[j] - xT[i])); //calculate l_jnPrime
				}
			}
			h_jn = (1.0 - (2.0*(x - xT[j])*l_jnPrime)) * (l_jn*l_jn);
			h_jnBar = (x - xT[j]) * (l_jn*l_jn);

			p = p + (h_jn*f(xT[j]) + h_jnBar*fp(xT[j])); //Calculate p
		}

		cout << "x= " << x << " ; p(x)= " << p << endl;
		x = x + h;
	}
	while(x <= 5.0);

	system("pause");
	return 0;
}
