#include <stdio.h>
#include <math.h>

double mag(double x, double y, double z) {
	return sqrt((x * x) + (y * y) + (z * z));
}

int close_to(double tolerance, double point, double value) {
	if (fabs(point - value) < tolerance) {
	return 1;
	}
else {
		return 0;
	}
}


int main() {
	
	double gx, gy, gz;
	int t;
	int timeCount = 0;

	
	printf("Kylus Pettit-Ehler\n");
	printf("kylusp@iastate.edu\n");
	
	
	scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
	
	printf("Ok, I'm now receiving data.\n");
	printf("I'm waiting");
	
	
		while ( close_to(0.1, 1.0, mag(gx, gy, gz))) {
		scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
		timeCount = timeCount + 1;
			
				if (timeCount == 10) {
				printf(".");
				timeCount = 0;
		}
		
		fflush(stdout);
			
	}
	
	int dropTime = t;


	printf("\nAahh! I'm Falling");
	
	while ( mag(gx, gy, gz) < 1.5) {
		scanf("%d, %lf, %lf, %lf", &t, &gx, &gy, &gz);
		timeCount = timeCount + 1;
			
				if (timeCount == 10) {
				printf("!");
				timeCount = 0;
			}
		
		fflush(stdout);
	}
		

printf("\n");		
		
double distanceFallen;
double timeFallen;

timeFallen = (t - dropTime) / 1000.0;

distanceFallen = 0.5 * 9.8 * (timeFallen * timeFallen);


printf("Ouch! After %4.3lf seconds, I fell %4.3lf meters.", timeFallen, distanceFallen);

return 0;
}