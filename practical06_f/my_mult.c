#include <stdio.h>
#include <math.h>

void matmult(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q]){
        // step 4: determine elements of C
        for (int i=0;i<n;i++){ // go along rows of A
                for (int j=0;j<q;j++){ // go along columns of B
                        for (int k=0;k<p;k++){
                                C[i][j] += A[i][k]*B[k][j];
                        }
                }
        }
}

