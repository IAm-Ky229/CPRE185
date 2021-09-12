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
#include <math.h>


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
    double a, b, c;
    double filler;
    /* Put your code after this line */
	printf("Enter value for side a:");
	scanf(" %lf", &a);
	printf("Enter value for side b:");
	scanf(" %lf", &b);
	c = (a * a) + (b * b);
    /*  This next line will calculate the square root of whatever value is
        inside the parenthesis and assigns it to the variable filler. */
    filler = sqrt(c);
	printf("Given sidelengths a and b, %lf and %lf, the sidelength of c is %.2f.", a, b, filler);


    return 0;


}

