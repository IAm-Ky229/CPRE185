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


/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/



int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	char Orientation


	while (1) {
		scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4);

		/* printf for observing values scanned in from ds4rd.exe, be sure to comment or remove in final program */


		//gy corresponds to top bottom orientation, top is positive, bottom is negative
		//gx corresponds to right left orientation, right is negative, left is positive
		//gz corresponds to forward backward orientation, back is negative, forward positive
		//ax, ay, and az are used to find magnitude
		//b1, b2, b3, and b4 are just buttons
		//t is time in milliseconds

		}

	orientation(gx, gy, gz);


        printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az));

		
    

    return 0;
}

/* Put your functions here */

double mag(double x, double y, double z) {
	double magFunction;

	magFunction = sqrt((x * x) + (y * y) + (z * z));

	return magFunction;
}

int close_to(double tolerance, double point, double value) {
	if (value - tolerance) <= point && (value + tolerance) => point) {
	return 1;
}
	else {
		return 0;
	}

char orientation(double gx, double gy, double gz) {


	if (close_to(.1, mag(gx, gy, gz == 1), gy) && != 'T') {
		printf("TOP");
		return 'T';
	}
	else if (close_to(.1, -mag(gx, gy, gz == 1), gy) && != 'B') {
		printf("BOTTOM");
		return 'B';
	}

	else if (close_to(.1, mag(gx, gy, gz == 1), gx) && != 'L') {
		printf("LEFT");
		return 'L';
	}
	else if (close_to(.1, -mag(gx, gy, gz == 1), gx) && != 'R') {
		printf("RIGHT");
		return 'R';
	}

	else if (close_to(.1, mag(gx, gy, gz == 1), gz) && != 'F') {
		printf("FRONT");
		return 'F';
	}
	else if (close_to(.1, -mag(gx, gy, gz == 1), gz) && != 'O') {
		printf("BACK");
		return 'O';
	}

	return 0;
}