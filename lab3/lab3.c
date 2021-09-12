/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

double mag(double x, double y, double z) {
	double magFunction;

	magFunction = sqrt((x * x) + (y * y) + (z * z));

	return magFunction;
}

int minutes(int m) {
	int minutesVal;
	minutesVal = m / 60000;
	return minutesVal;
}

int seconds(int s) {
	int secondsVal;
	secondsVal = (s / 1000) % 60;
	return secondsVal;
}

int millis(int milli) {
	int millisValue;
	millisValue = milli % 1000;
	return millisValue;
}

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double  ax, ay, az;     

	


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az); 

        printf("Echoing output: %8.3d, %7.4lf, %7.4lf, %7.4lf\n", t / 1000, ax, ay, az);


        printf("At %d ms, the acceleration's magnitude was: %lf\n", 
            t, mag(ax, ay, az));
            
        printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
        minutes(t), seconds(t), millis(t), mag(ax,ay,az));

    }

return 0;
}




