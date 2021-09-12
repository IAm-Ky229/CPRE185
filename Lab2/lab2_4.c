/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name:
- 	Section:
-	NetID:
-	Date:
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-							 Implementation
-----------------------------------------------------------------------------*/
int main()
{
    int integerResult;
    double decimalResult;
	
	int a = 6427 + 1725;
	printf("6427 + 1725 = %d\n", a);
	int b = (6971 * 3925) - 95;
	printf("(6971 * 3925) - 95 = %d\n", b);
	double c = 79 + 12 / 5;
	printf("79 + 12 / 5 = %.2f\n", c);
	/*Double did not add the remainder becuse the numbers are integers*/
	double d = 3640.0 / 107.9;
	printf("3640.0 / 107.9 = %.2f\n", d);
	/*Real divided by a real*/
	int e = (22 / 3) * 3;
	printf("(22 / 3) * 3 = %d\n", e);
	/* Remainders are not added because no numbers are real */
	int f = 22 / (3 * 3);
	printf("22 / (3 * 3) = %d\n", f);
	/*Same as above, no remainder value*/
	double g = 22 / (3 * 3);
	printf("22 / (3 * 3) = %lf\n", g);
	/*All numbers are integers, parentheses force multiplication first*/
	double h = 22 / 3 * 3;
	printf("22 / 3 * 3 = %lf\n", h);
	/*Calcualtions left to right, no real numbers*/
	double i = (22.0 / 3) * 3.0;
	printf("(22.0 / 3) * 3.0 = %lf\n", i);
	/*The first calculation yields 7.333, multiplied by 3 the answer is 22.0*/
	int j = 22.0 / (3 * 3.0);
	printf("22.0 / (3 * 3.0) = %d\n", j);
	/*Real numbers, but integer values*/
	double k = 22.0 / 3.0 * 3.0;
	printf("22.0 / 3.0 * 3.0 = %lf\n", k);
	/*Calculations from left to right, essentially 7.333 * 3*/
	double l = (23.567 / (3.14159 * 2)) * (23.567 / (3.14159 * 2)) * 3.14159;
	printf("The area of a circle with radius 23.567 is %.2f.\n", l);
	/*I input the formula for the radius and multiplied it by itself, multiplying the result of r^2 by pi*/
	double m = 14 * .3048;
	printf("14 feet is %.2f meters.\n", m);
	/*Unit conversion, multiplication*/
	double n = (76 - 32) / 1.8;
	printf("76 degrees Fahrenheit is %.2f degrees Centigrade.\n", n);
	/* I input the degrees Fahrenheit into the Centigrade formula*/
    return 0;
}

