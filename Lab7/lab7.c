// 185 Lab 7
#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items) {
int i;
double bufferTotal;
	for (i = 0; i < num_items; i++) {
	bufferTotal = bufferTotal + buffer[i];
	}

return bufferTotal / num_items;
}

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double *max, double *min) {
	int i;

	*max = array[0];
	*min = array[0];

	for (i = 0; i < num_items; i++) {
		if (array[i] > *max) {
			*max = array[i];
		}
		if (array[i] < *min) {
			*min = array[i];
		}
	}
}

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item) {
int i;

	for (i = (length-1); i > 0; i--) {
	buffer[i] = buffer[i-1];
	}

buffer[0] = new_item;

}

int main(int argc, char* argv[]) {

	double gx, gy, gz;
	int button_T, button_S, button_X, button_C;
	double max, min;


	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	/* DO NOT CHANGE THIS PART OF THE CODE */


	int lengthofavg = 0;
	if (argc > 1) {
		sscanf(argv[1], "%d", &lengthofavg);
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg > MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}

	do
	{

		scanf("%lf, %lf, %lf, %d, %d, %d, %d", &gx, &gy, &gz, &button_T, &button_C, &button_X, &button_S);

		updatebuffer(x, lengthofavg, gx);
	
		updatebuffer(y, lengthofavg, gy);
		
		updatebuffer(z, lengthofavg, gz);
		
		printf("X VAL: %1.3lf  Y VAL: %1.3lf  Z VAL: %1.3lf  ", gx, gy, gz);
		
		printf("AVG X: %1.3lf  ", avg(x, lengthofavg));
		
		maxmin(x, lengthofavg, &max, &min);
	printf("MAX X: %1.3lf  MIN X: %1.3lf  ", max, min);
		
		printf("AVG Y: %1.3lf  ", avg(y, lengthofavg));
		
		maxmin(y, lengthofavg, &max, &min);
	printf("MAX Z: %1.3lf  MIN Z: %1.3lf  ", max, min);
		
		printf("AVG Z: %1.3lf  ", avg(z, lengthofavg));
		
		maxmin(z, lengthofavg, &max, &min);
	printf("MAX Z: %1.3lf  MIN Z: %1.3lf", max, min);

	printf("\n");
			
	} while (button_S == 0);
}


