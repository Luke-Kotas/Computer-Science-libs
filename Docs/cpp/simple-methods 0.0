
# include "simple_methods.h"
# include "level_1.h"
# include <math.h>
# include <cmath>
# include <iomanip>
# include <cstdlib>
# include <iostream>


using namespace std;


// Monte Carlo method: approximation of pi
// Pre: n is the number generated points
// Post: returns an approximation of pi using
//		 n random points
double  monteCarlo::approx_pi(int n){
	int nin = 0;
	double randmax = double(RAND_MAX);
	for (int i=0; i<n; ++i){
		double x = rand()/randmax;
		double y = rand()/randmax;
		if ( x*x + y*y <1.0) nin = nin +1;
	}
	return (4.0*nin/n);
}

// Newton - Raphson Method 
double  square_root(double a){
	
	double epsilon = 0.001;
	double x = 1.0; // Initial Guess
	cout << " Newton Raphson Method: ";
	while(((double)fabs(x*x -a)) >= epsilon) {
		x = 0.5*(x + a/x);
		cout << x << endl;
	}
		return x;
}

// Trapezoid integration method
double trapezoid(double a,double b,int n){
	
	
	double h = (b - a)/n;
	double s = 0;
	for(int i = 1; i<n; ++i) s = s + f(a + i*h);
	return (f(a) + f(b) + 2*s)*h/2;

}

// Inline function 
double f(const double a){
	return sin(a);
}

// Lagrange Interpolation Method
double  Lagrange(const int N,double x0){
	// Declare and initialize two arrays to hold the coordinates of the initial data points
	//const int M = 4; // array length must be CONSTANT, otherwise ERROR.	
	Vector x;
	x.initVector(N);
	cout << " x: " << endl;
	x.getElements();
	Vector y;
	cout << " y: " << endl;
	y.initVector(N);
	y.getElements();


	 // Generate the points
	double mul = 1.0;
	double sum = 0.0;
	for(int i=0; i< N; i++){
		for (int j=0; j<i; j++){
			mul *= (x0 - x.varV[j])/(x.varV[i]-x.varV[j]);
		}
		for (int j=i+1; j<N; j++){
			mul *= (x0 - x.varV[j])/(x.varV[i]-x.varV[j]);
		}
		sum += y.varV[i]*mul;
		mul = 1.0;
	}
	return sum;
}
