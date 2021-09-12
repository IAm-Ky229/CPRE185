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

    integerResult = 77.0 / 5;
    printf("The value of 77/5 is %d, using integer math\n", integerResult);
		/*%d must be used when the evaulated value is an integer*/

    integerResult = 2 + 3;
    printf("The value of 2+3 is %d\n", integerResult);
		/* The value that is assigned to %d is missing*/
	
    decimalResult = 1.0 / 22.0;
    printf("The value 1.0/22.0 is %lf\n", decimalResult);
		/*%d cannot be used for a decimal result*/

    return 0;
}

