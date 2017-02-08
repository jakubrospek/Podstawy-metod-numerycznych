#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

double funkcja(double x){
return 1/(1+x*x);
}

double pochodna_II(double x){
return (6*x*x - 2) / ((x*x + 1)*(x*x + 1)*(x*x + 1) ) ;
}


int main(){
double const h = 1;
double p_x = 0;
int x_j = 0;


for(double x = -5 ; x <=5 ; x=x+0.1){

		x_j = floor(x);
		p_x = funkcja(x_j) + ( (funkcja(x_j+1) - funkcja(x_j))/h - h*pochodna_II(x_j+1)/6.0 - h*pochodna_II(x_j)/3.0 ) * (x - x_j) + (pochodna_II(x_j)/2.0 * (x - x_j) * (x - x_j) ) + (pochodna_II(x_j+1) - pochodna_II(x_j))/(6*h) * (x - x_j) * (x - x_j) * (x - x_j);
	
    cout <<  "P(" << x << ") = " << setprecision(6) << p_x << "\t True value: " << funkcja(x) << endl;
}

////////////////////////////////////  METOD¼ ELEMINACJI GAUSSA //////////////////////////////////////////////////

/*
    double B[9][9] =  {{4*h, h, 0, 0, 0, 0, 0, 0,  0},
                       { h, 4*h, h, 0, 0, 0, 0, 0, 0},
                       { 0, h, 4*h, h, 0, 0, 0, 0, 0},
                       { 0, 0, h, 4*h, h, 0, 0, 0, 0},
                       { 0, 0, 0, h, 4*h, h, 0, 0, 0},
                       { 0, 0, 0, 0, h, 4*h, h, 0, 0},
                       { 0, 0, 0, 0, 0, h, 4*h, h, 0},
                       { 0, 0, 0, 0, 0, 0, h, 4*h, h},
                       { 0, 0, 0, 0, 0, 0, 0, h, 4*h}};
                   
    double x[9] = {0};
    double p[9] = {funkcja(-4),funkcja(-3),funkcja(-2),funkcja(-1),funkcja(0),funkcja(1),funkcja(2),funkcja(3),funkcja(4)};
    double R[9] = {6*(p[1] - 2*p[0] +  funkcja(-5) )/h,
                   6*(p[2] - 2*p[1] + p[0])/h,
                   6*(p[3] - 2*p[2] + p[1])/h,
                   6*(p[4] - 2*p[3] + p[2])/h,
                   6*(p[5] - 2*p[4] + p[3])/h,
                   6*(p[6] - 2*p[5] + p[4])/h,
                   6*(p[7] - 2*p[6] + p[5])/h,
                   6*(p[8] - 2*p[7] + p[6])/h,
                   6*( funkcja(5)   - 2*p[8] + p[7])/h};

    for(int i = 1; i < 9; i++){
        B[i][i] = B[i][i] - B[i-1][i]*( B[i][i-1] / B[i-1][i-1] );
        R[i] = R[i] - ( B[i-1][i] / B[i-1][i-1] ) * R[i-1];
    }

    x[8] = R[8]/B[8][8];


    for(int j = 1; j < 9 ; j++){
    x[8-j] = ( R[8-j] - B[8-j+1][8-j]*x[8-j+1] )/ B[8-j][8-j];
    }
  
    cout << "P" << 1 << " = " << 0 << endl;

    for( int k = 0; k < 9 ; k++)
         cout << "P" << k+2 << " = " << x[k] << endl;
   
    cout << "P" << 11 << " = " << 0 << endl;
	*/
/////////////////////////////////////

system("pause");
return 0;
}
