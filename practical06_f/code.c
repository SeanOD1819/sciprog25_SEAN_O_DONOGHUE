#include <stdio.h>
#include <math.h>

int main(void){

	// step 1: define dimensions
	int n=5, p=3, q=4;

	// step 2: declare arrays
	double C[n][q], A[n][p], B[p][q];

	// step 3: initialise arrays
	for (int i=0;i<n;i++){
		for (int j=0;j<q;j++){
			C[i][j] = 0.0;
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<p;j++){
			A[i][j] = (double)(i+j);
		}
	}
	for (int i=0;i<p;i++){
		for (int j=0;j<q;j++){
			B[i][j] = (double)(i-j);
		}
	}

	// step 4: determine elements of C
	for (int i=0;i<n;i++){ // go along rows of A
		for (int j=0;j<q;j++){ // go along columns of B
			for (int k=0;k<p;k++){
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}

	// step 5: print out arrays
	printf("A = \n");
	for (int i=0;i<n;i++){
		printf("%lf %lf %lf\n", A[i][0], A[i][1], A[i][2]);
	}
	printf("B = \n");
	for (int i=0;i<p;i++){
		printf("%lf %lf %lf %lf\n", B[i][0], B[i][1], B[i][2], B[i][3]);
	}
	printf("C = \n");
	for (int i=0;i<n;i++){
		printf("%lf %lf %lf %lf\n", C[i][0], C[i][1], C[i][2], C[i][3]);
	}

		

	return(0);
}

