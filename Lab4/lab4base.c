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
	return sqrt((x * x) + (y * y) + (z * z));
}

int close_to(double tolerance, double point, double value) {
	if ((value - tolerance) <= point && (value + tolerance) >= point) {
	return 1;
}
	else {
		return 0;
	}
}

char CalcOrientation(double gx, double gy, double gz, char prevOrientation) {


		if (close_to(.15, mag(gx, gy, gz), gy) && prevOrientation != 'T') {
			prevOrientation = 'T';
			printf("TOP\n");
			return prevOrientation;
		}

		else if (close_to(.15, -mag(gx, gy, gz), gy) && prevOrientation != 'B') {
			prevOrientation = 'B';
			printf("BOTTOM\n");
			return prevOrientation;
		}

		else if (close_to(.15, mag(gx, gy, gz), gx) && prevOrientation != 'L') {
			prevOrientation = 'L';
			printf("LEFT\n");	
			return prevOrientation;
		}

		else if (close_to(.15, -mag(gx, gy, gz), gx) && prevOrientation != 'R') {
			prevOrientation = 'R';
			printf("RIGHT\n");
			return prevOrientation;
		}

		else if (close_to(.15, mag(gx, gy, gz), gz) && prevOrientation != 'F') {
			prevOrientation = 'F';
			printf("FRONT\n");
			return prevOrientation;
		}

		else if (close_to(.15, -mag(gx, gy, gz), gz) && prevOrientation != 'O') {
			prevOrientation = 'O';
			printf("BACK\n");
			return prevOrientation;
		}
	}
/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/
int main(void) {
    int t, b1, b2, b3, b4;
    double ax, ay, az, gx, gy, gz;
	double ds4Position;
	char prevOrientation;

    while (1) {
		scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4);
		

		if (b1 == 1) {
			break;
		}
			ds4Position = CalcOrientation(gx, gy, gz, prevOrientation);
			ds4Position = prevOrientation;
    }

    return 0;
}

/* Put your functions here */

//gy corresponds to top bottom orientation, top is positive, bottom is negative
//gx corresponds to right left orientation, right is negative, left is positive
//gz corresponds to forward backward orientation, back is negative, forward positive
//ax, ay, and az are used to find directional magnitude
//b1, b2, b3, and b4 are just buttons (b1 is triangle)
//t is time in milliseconds
