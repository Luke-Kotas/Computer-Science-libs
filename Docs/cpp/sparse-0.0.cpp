

# include <iostream>
# include <vector>
# include "level_1.h"
using namespace std;



void compression(){

	const int size = 3;
	double A[size][size] = {{0,1,0}, {0,0,0}, {0,0,6}}; // example matrix
	//int size = sizeof(A)/sizeof(A[0][0]); // general formula for array size.



	int counter = 0;
	for ( int i = 0; i<size;i++){
		for ( int j=0; j<size; j++){
			cout << A[i][j];
			if ( A[i][j] != 0 ){
				counter  += 1;
			}
		}
	}


	double DD  = counter / (size*size);
	double SD  = 1 - DD;

	Matrix B;
	B.initMatrix(counter,1);
	Matrix RB; // Non-zero element row position
	RB.initMatrix(counter,1); 
	Matrix CB; // Non-zero element column position
	CB.initMatrix(counter,1);

	 counter = 0;
	for ( int i = 0; i<size;i++){
		for ( int j=0; j<size; j++){
			cout << A[i][j];
			if ( A[i][j] != 0 ){
				RB.getElements(counter,1,i);
				CB.getElements(counter,1,j);
				B.getElements(counter,1,A[i][j]);
				counter  += 1;
			}
		}
	}
	
	cout << " RB" ;
	RB.elements();
	cout << " CB" ;
	CB.elements();
	cout << " B";
	B.elements();

	RB.delMatrix();
	CB.delMatrix();
	B.delMatrix();
}
