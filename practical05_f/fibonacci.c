/* Code to display Fibonacci series up to user given number n */

#include <stdio.h>
#include <math.h>
#include <string.h>

void recursion(int *a, int *b);

int main(void){

	/* user enters value n */
	int n;
	printf("Enter integer value n up to which the Fibonacci series will be calculated to:\n");
	scanf("%d", &n);

	/* printf("n = %d", n); */

	/* initialise Fibonacci sequence */
	int x = 0;
	int y = 1;

	printf("F_0 = %d\n", x);
	printf("F_1 = %d\n", y);

	/* loop that calculates next term using recursion(,) and prints the result */
	for (int i=0;i<n-1;i++){
		recursion(&x, &y);
		printf("F_%d = %d\n", (i+2), y);
	}

	return(0);

}

/* function to perform recursive step in Fibonacci sequence */
void recursion(int *a, int *b){

	int new;

	/* calculate next term by accessing r values of a and b using their pointers */
	new = *a + *b;

	/* update the sequence, change a to b and b to new */
	*a = *b;
	*b = new;
}

