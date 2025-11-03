// include modules that are needed
#include <stdio.h>
#include <stdlib.h>

// declare functions
int *allocatearray(int n);
void fillwithones(int *p, int n);
void printarray(int *p, int n);
void freememory(int *p);

// function to dynamically allocate memory to array of n integers
int *allocatearray(int n){
	// define pointer to array
	int *arr;
	// define size of array based on input n
	arr = (int *) malloc(n * sizeof(int));
	// return array
	return arr;
}

// need pointer to array (p) and variable length of array (n)
void fillwithones(int *p, int n){
	for (int i=0;i<n;i++){
		// loop through elements of the array p is pointing to and make them all 1
		p[i] = 1;
	}
}

// function to print array
void printarray(int *p, int n){
	printf("Array elements: \n");
	for (int i=0;i<n;i++){
		// print element
		printf("%d\n", p[i]);
	}
}

// function to free memory
void freememory(int *p){
	free(p);
}

int main(void){
	int N = 5;
	int *arr = allocatearray(N);
	fillwithones(arr, N);
	printarray(arr, N);
	freememory(arr);
}










