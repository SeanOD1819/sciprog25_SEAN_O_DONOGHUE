#include <stdio.h>


// iterative function
int gcd_iter(int a, int b);
int gcd_iter(int a, int b){
	int temp;
	while (b != 0){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

// recursive function
int gcd_rec(int a, int b);
int gcd_rec(int a, int b){
	if (b == 0){
		return a;
	}
	else{
		int t = a%b;
		return gcd_rec(b, t);
	}
}

int main(void){
	// user input
	int A;
	int B;
	printf("Enter 2 integers which you want to find the gcd of, with the first needing to be larger than the second:\n");
	scanf("%d", &A);
	scanf("%d", &B);

	printf("By iterative function: gcd(%d, %d) = %d\n", A, B, gcd_iter(A,B));
	printf("By recursive function: gcd(%d, %d) = %d\n", A, B, gcd_rec(A,B));
}


