// include modules that are needed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// factorial function
double factorial(int n);
// approximation of e function declaration
double *approx_e(int n);
// getting approximation of e^x
double exp_x(double x, double *p, int n);

// function to get factorial
double factorial(int n){
	double ans = 1.0;
	if (n > 1){
		for (int i=1;i<=n;i++){
			ans = ans*i;
		}
	}
	return ans;
}	

// function to approximate e, basically defines coefficients of x
double *approx_e(int n){
        // define pointer to array
        double *arr;
        // define size of array based on input n
        arr = (double *) malloc(n * sizeof(double));
	// create values of the array
	for (int i=0;i<n;i++){
		arr[i] = 1.0/factorial(i);
	}
        // return array
        return arr;
}

// function to evaluate approximation of exp(x)
double exp_x(double x, double *p, int n){
	double ans;
	for (int i=0;i<n;i++){
		ans += p[i]*pow(x,i);
	}
	return ans;
}

int main(void){
	// ask user for order of Taylor expansion
	// printf("%lf\n", factorial(5));
	int n;
	printf("Enter integer value n which will be the order of the Taylor expansion:\n");
	scanf("%d", &n);
        double *my_arr = approx_e(n);

	// print e approximation to this order
	printf("%dth order approximation of e = %lf\n\n", n, exp_x(1.0, my_arr, n));

	// 1st to 15th orders:
	for (int i=1;i<16;i++){
		double *my_arr = approx_e(i);
		printf("%dth order approximation of e = %.16lf\n", i, exp_x(1.0, my_arr, i));
	}	
	
	return(0);
}







