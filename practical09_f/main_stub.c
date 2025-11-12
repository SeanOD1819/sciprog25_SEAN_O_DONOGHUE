
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Help with 'tokens' from https://www.educative.io/answers/splitting-a-string-using-strtok-in-c
#define MAX_FILE_NAME 100
#include "magic_square_stub.h"
int getlines(char filename[MAX_FILE_NAME]);
int isMagicSquare(int ** square, const int n);

int main(){
	//define our file variable
	FILE *f;
	char filename[MAX_FILE_NAME];
	printf("Enter file name: ");
	scanf("%s", filename);
	// ##! n function which gets the number of lines
	int n = getlines(filename)-1; // reads 4 lines for txt file with 3 x 3 matrix
	// TODO: Open the file
	f = fopen(filename, "r");
	// TODO: Allocating a matrix for storing the magic square
	// as an array of pointers, where each pointer is a row
	int **matrix = malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
 		matrix[i] = malloc(n * sizeof(int));
	}	
	// matrix[0] is a pointer to the first 'row' of n integer pointers
	// TODO:inputting integer data into the matrix;
	int i=0;
	int j=0;
	char line[256];
	while (fgets(line, sizeof(line), f)){
		// printf("Line: %s", line);
		char *token = strtok(line, " ");
		while (token != NULL){
			// printf("%s\n",token);
			if ((i < n) && (j < n)){ // reads 4 lines for txt file with 3 x 3 matrix
				matrix[i][j] = atoi(token);
			}
			token = strtok(NULL, " ");
			j += 1;
		}
		j = 0;
		i += 1;
	}
	/*
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("matrix_ij = %d\n", matrix[i][j]);
		}
	}
	*/
        // test magic squares
        printf("Is matrix in %s magic: %d\n", filename, isMagicSquare(matrix, n));
	// TODO: Freeing each row separately before freeing the array of pointers
	for (int i = 0; i < n; i++) {
    		free(matrix[i]);
	}
	free(matrix);
	// TODO:Close the file
	fclose(f);
	return 0;
}
//##!
int getlines(char filename[MAX_FILE_NAME]) {
	FILE *fp;
	fp = fopen(filename, "r");
	int ch_read;
	int count = 0;
	while( (ch_read = fgetc(fp)) != EOF)
	{		
		if (ch_read == '\n'){
		count++;
		}
	}
	printf("No. lines, %d\n", count);
	fclose(fp);
	return count;
}

