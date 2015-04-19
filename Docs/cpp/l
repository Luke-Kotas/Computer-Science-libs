

# include "level_1.h"
# include "level2.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>


	double vectorNorms::city(Vector a){
		double sum = 0;
		for(int i =0; i != a.lengthV; i++){
			//cout << " a" <<a.varV[i];
			sum += a.varV[i];
		}
		return sum;
	}

	double vectorNorms::euclidian(Vector a){
		double sum = 0;
		for(int i =0; i < a.lengthV; i++){
			//cout << " a" <<a.varV[i];
			sum += pow( a.varV[i],2.0);
		}
		double result = pow(sum,0.5);
		return result;
	}

	double vectorNorms::inf(Vector a){
		double max = a.varV[0];
		for (int i=1; i!=a.lengthV; i++){
			if(a.varV[i] > max){
				max = a.varV[i];
			}
		}
		return max;
	}

