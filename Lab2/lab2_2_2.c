/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name:Kylus Gerald Pettit-Ehler
- 	Section:J
-	NetID:kylusp@iastate.edu
-	Date:September 4, 2018
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

    /* Put your code after this line */
	int x, y, z;
	printf("Enter a width: ");
	scanf("%d", &x);
	printf("Enter a height: ");
	scanf("%d", &y);
	printf("Enter a depth: ");
	scanf("%d", &z);
	printf("A %d by %d by %d prism's volume is %d", x, y, z, x*y*z);

    return 0;

}
