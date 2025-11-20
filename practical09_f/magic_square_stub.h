
#include <stdio.h>
// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value
//
int isMagicSquare(int ** square, const int n) {
	// Eliminate the case where 'n' is negative
	if(n < 0) {
	return 0;
	}
	// M is the sum of every row, column,
	// and the main and secondary diagonals
	int M = (n * (n*n + 1))/2;
	int i, j;
	// TODO: Checking that every row and column add up to M
	int rowSum_i = 0;
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			rowSum_i += square[i][j];
		}
		if (rowSum_i != M){
			return 0;
		}
		rowSum_i = 0;
	}
	int colSum_j = 0;
	for (j=0;j<n;j++){
		for (i=0;i<n;i++){
			colSum_j += square[i][j];
		}
		if (colSum_j != M){
			return 0;
		}
		colSum_j = 0;
	}
	// TODO: Checking that the main and secondary
	// diagonals each add up to M
	int mainSum = 0;
	for (i=0;i<n;i++){
		mainSum += square[i][i];
	}
	if (mainSum != M){
		return 0;
	}
	int secSum = 0;
	for (j=0;j<n;j++){
		secSum += square[j][n-j-1];
	}
	if (secSum != M){
		return 0;
	}
	// If passed all checks, it is a magic square
	return 1;
}

