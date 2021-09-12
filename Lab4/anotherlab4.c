/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
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

double mag(double x, double y, double z) {
	double theMag;

		theMag = sqrt((x * x) + (y * y) + (z * z));
	printf("%lf\n", theMag);
	return 0;
}

double OrientFunction(double gx, double gy, double gz) {

double actualMag;

actualMag = mag(gx, gy, gz);

}

/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	double magValues;

    while (1) {
		scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4);

			magValues = OrientFunction(gx, gy, gz);
    }

    return 0;
}

/* Put your functions here */
