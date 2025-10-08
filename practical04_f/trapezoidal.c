#include <math.h>
#include <stdio.h>

/* converting degrees to radians */
float pi = 3.141592;
float degtorad(float arg){
        return ( (pi*arg)/180.0 );
}

/* define array to hold results of tan(x), outside of main / other functions -> global variable */
float results[13];

/* function to calculate area under the curve */
float calc_area(){
        /* initialise area variable */
        float area = 0.0;
        /* loop through results array + calculate using trapezoidal rule */
        for (int i=0;i<13;i++){
                area += 2*results[i];
        }
        area -= results[0] + results[12];
        area *= pi/(3.0*2.0*12.0);

        /* return answer */
        return area;
}

int main(void) {

        /* initialse variables to be used in loop */
        double x;
        int i;

        /* calculate tan(x) for x = 0, 5, ..., 60 radians and store in results array */
        for (i=0;i<13;i++){
                x = degtorad(5.0*i);
                results[i] = tan(x);
                printf("item %d: %f\n", i,  tan(x));
        }

	/* call trapezoidal rule calculation */
	float answer;

	answer = calc_area();
	printf("area using trapezoidal rule: %f\nalgebraic area: %f\n", answer, log(2));


	return(0);

}




