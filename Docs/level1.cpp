

# include <iostream>
# include <cstdlib>
# include <string>
using namespace std;

//template<int R, int C>

class Matrix{
	double *val;
	double *mulProduct;// 2 Matrix Multipication Space
	int rows;
	int cols;
	bool alloc;// Check if matrix exists - (allocate)
	bool mulAlloc;
public:
	// Initialize matrix
	void initMatrix(const int rowsD,const int colsD){
		rows = rowsD;
		cols = colsD;
		alloc = true;
		mulAlloc = false;
		val=(double *)calloc((rows)*(cols),sizeof(double));
	}

	// Deallocate a matrix
	void delMatrix(){
		if (alloc == true){
			free(val);
			if (mulAlloc == true){
				free(mulProduct);
			}
		}
		else{
			cout << "Matrix not exists! "<<endl;
		}
	}

	//Print Matrix's Dimensions
	void printD(){
		if (alloc == true){
			cout << " Rows => " << rows;
			cout << " Columns => " << cols;
			cout << " Memory => " << val<<endl;
		}else{
			cout << "Matrix Not Exists! "<<endl ;
		}
	}

	// INPUT: Matrix and Number
	// OUTPUT: Matrix
	// Fill all Matrix with a number
	void Number(const double num){
		if (alloc == true){
			for (int  i = 0; i < rows*cols; i++){
				val[i] = num;
			}
		}

	}

	//Fill a Matrix with elements from console
	void getElements(){
		if (alloc == true){
			int counter  = 0;
			for (int i=0; i<rows; i++){
				for (int j=0; j<cols; j++){
					cout << "i: " << i+1 << " j: "<<  j+1<< " " ;
					cin >> val[counter];
					counter++;
				}
			}
		}
	}

	// Print Matrix's Elements
	void elements(){
		if (mulAlloc){
			cout << " MATRIX: " <<endl;
			int counter = 0;
			for (int i = 0;  i < rows; i++){
				for (int j = 0; j < cols; j++){
					cout << mulProduct[counter] << " ";
					counter++;
				}
				cout << endl;
			}
		}
		else if (alloc == true){
			cout << " MATRIX: " <<endl;
			int counter = 0;
			for (int i = 0;  i < rows; i++){
				for (int j = 0; j < cols; j++){
					cout << val[counter] << " ";
					counter++;
				}
				cout << endl;
			}
		}


	}

	//INPUT: a number 
	//OUTPUT: a matrix
	// Multiply a Matrix  with a number 
	void mulNum(double num){
		if(alloc == true){
			for (int i =0; i < rows*cols; i++){
				val[i] = val[i]*num;
			}
		}
	}

	// INPUT: 2 Matrices
	// OUTPUT: 1 Matrix
	// Multiply 2 N-dimensions matrices 
	void mul2D( Matrix a, Matrix b){
		int arows = a.rows;
		int acols = a.cols;
		int brows = b.rows;
		int bcols = b.cols;
		mulAlloc = true; // Defines array is for multiplication product

		rows = a.rows; // for elements() method correctness
		cols = b.cols; // for elements() method correctness

		mulProduct=(double *)calloc((arows*bcols),sizeof(double)); // keep
		if( (a.alloc == true) && (b.alloc==true) ){
			if(acols == brows){
				for(int  ia =0; ia <arows; ia++){
					int l=0;
					for (int bcolumns = 0; bcolumns <bcols; bcolumns++){
						int k=0;
						double sum = 0;
						for (int ja=0; ja<acols; ja++){
							double aval = a.val[ia + k*arows];
							double bval = b.val[ja + l*brows];
							k++;
							sum += aval * bval;
						}
						mulProduct[ia + bcolumns*arows] = sum;
						l++;
					}	
				}
			}else{
				cout << " Matrix Dimensions Don't agree! ";
			}
		}else{
			cout << "Error!"<<endl;
		}

	}
};

class vector {

public:
	int length;
	double *var;
	bool alloc;
	void initVector(int a){
		length = a;
		var = (double *)calloc(a,sizeof(double));
		alloc = true;
	}

	void getElements(){
		for (int i=0; i<length; i++){
			cin >> var[i];
		}
	}

	void elements(){
		if (alloc == true){
			cout << "Vector: " << "[";
		for (int i=0; i<length; i++){
			cout << var[i] <<" " ;
		}
		cout << "]"<<endl;
	}
	}

	void delVector(){
		if (alloc == true){
			free(var);
		}
		else{
			cout << " Vector Not Exists " <<endl;
		}
	}

};
