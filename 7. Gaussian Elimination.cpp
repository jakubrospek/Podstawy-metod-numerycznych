#include <iostream>

using namespace std;

int main()
{
	float a[5] = {-1, -1, -1, -1, -1};
	float b[5] = {2, 2, 2, 2, 2};
	float c[5] = {-1, -1, -1, -1, -1};
	float B[5];
	float P[5];
	float x[5] = {0};
	float r[5] = {0, 1, 2, 3, 4};

	B[0] = b[0];
	for(int j = 1; j < 5; j++)
	{
		B[j] = b[j] - ( (a[j]/B[j-1]) * c[j-1] );
	}

	P[0] = r[0];
	for(int j = 1; j < 5; j++)
	{
		P[j] = r[j] - ( (a[j]/B[j-1]) * P[j-1]);
	}

	for(int j = 0; j <= 4; j++)
	{
		x[4] = P[4]/B[4];
		x[4-j] = (P[4-j] - c[4-j] * x[4-j+1]) / B[4-j];
	}

	for(int k = 0; k < 5; k++)
	{
		cout << "x" << k+1 << "=" << x[k] << endl;
	}
	system("pause");
	return 0;
}
