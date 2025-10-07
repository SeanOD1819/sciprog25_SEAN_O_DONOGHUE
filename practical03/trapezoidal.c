#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void) {

	/* initliase answer to trapezoidal sum */
	double sum = 0.0;

	/* define limits */
	double a = 0.0;
	double b = 3.141592653589793/3.0;

	/* printf("a = f, b = f, tan(a) = f, tan(b) = f \n", a, b, tan(a), tan(b)); */

	/* limit contributions to the sum */
	sum += tan(a) + tan(b);

	/* loop through the points */
	int N = 12;
	double x_i;
	for (int i=1;i<N;i++){
		/* define x_i point */
		x_i = a + (b-a)*((float)i/(float)N);
		/* printf("x_i: f \n", x_i); */
		/* add x_i contribution to sum */
		sum += 2*tan(x_i);
	}
	/* multiply sum by the prefactor */
	sum *= (b-a)/(2.0*(float)N);

	/* analytuical answer */
	double ana_ans = log(2);

	/* output results + compare to analytical result */
	printf("Calculated using trapezoidal rule: %f, Analytical answer: %f\n", sum, ana_ans);




}
				
