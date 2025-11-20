/* approximating arctanh(x) using Maclaurin series */

#include <stdio.h>
#include <math.h>

double artanh1(double *del, double *x);
double artanh2(double *x);

int main(void){

	/* ask user for accuracy delta */
	double delta;
	printf("Please enter the minimum sum contribution in Maclaurin series you want the approximation to be\n");
	scanf("%lf", &delta);

	/* make arrays to store results for both methods */
	double arr_method1[181];
	double arr_method2[181];

	/* initialise x value */
	double x_val;

	for (int i=0;i<181;i++){
		x_val = -0.9 + i*0.01;
		arr_method1[i] = artanh1(&delta, &x_val);
		arr_method2[i] = artanh2(&x_val);
		printf("x = %.2f, abs. diff. = %.10f\n", x_val, fabs(arr_method1[i] - arr_method2[i])); 
	}

	return(0);


}

/* function to implement Maclaurin series */
double artanh1(double *del, double *x){

	/* initialise sum answer */
	double s = 0.0;
	
	/* initialise loop counter */
	int counter = 0;

	/* initialise series term */
	double element = *del+1.0;

	/* loop through terms in sum */
	while (element > *del){

		/* find series increment and add it to sum running total */
		element = pow(*x, 2*counter + 1)/(2*counter + 1);
		s += element;

		/* increase counter */
		counter += 1;
	}

	/* return answer */
	return s;
}

/* function to use analytic formula */
double artanh2(double *x){
	return 0.5*(log(1.0 + *x) - log(1.0 - *x));
}







