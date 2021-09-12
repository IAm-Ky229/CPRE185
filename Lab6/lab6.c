// 185 lab6.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of DS4 data, and returns
//  True when the square button is pressed
//  False Otherwise
//This function is the ONLY place scanf is allowed to be used
//POST: it modifies its arguments to return values read from the input line.
int read_line(double* g_x, double* g_y, double* g_z, int* Button_T, int* Button_X, int* Button_S, int* Button_C) {
	scanf("%lf, %lf, %lf, %d, %d, %d, %d, %d", g_x, g_y, g_z, Button_T, Button_X, Button_S, Button_C);
	if (*Button_C == 0) {
		return 1;
	}
	if (*Button_C == 1) {
		return 0;
	}
}

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the DS4 in radians
// if x_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag) {
	if (x_mag < -1) {
		x_mag = -1;
	}
	if (x_mag > 1) {
		x_mag = 1;
	}
	return asin(x_mag) * -1.0;
}

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the DS4 in radians
// if y_mag outside of -1 to 1, treat it as if it were -1 or 1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag) {

		if (y_mag < -1) {
			y_mag = -1;
		}
		if (y_mag > 1) {
			y_mag = 1;
		}

		return asin(y_mag);
}


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad) {
	return rad * (78 / PI);
}

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use) {
	int i;

		for (i = 0; i < num; i++) {
			printf("%c", use);
		}
}
	

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number) {
	if (number < 0) {
		print_chars(39 + number, ' ');
		print_chars(fabs(number), 'l');
	}
	if (number > 0) {
		print_chars(39, ' ');
		print_chars(number, 'r');
	}
	if (number == 0) {
		print_chars(39, ' ');
		print_chars(1, '0');
	}
	print_chars(1, '\n');
}


int main()
{
	double x, y, z;                             // magnitude values of x, y, and z
	int b_Triangle, b_X, b_Square, b_Circle;    // variables to hold the button statuses
	double roll_rad, pitch_rad;                 // value of the roll measured in radians
	int scaled_value;                           // value of the roll adjusted to fit screen display

	//insert any beginning needed code here

	int getValues;
	int toggle = 0;
	do
	{

		// Get line of input

		getValues = read_line(&x, &y, &z, &b_Triangle, &b_X, &b_Square, &b_Circle);

		// calculate roll and pitch.  Use the buttons to set the condition for roll and pitch
		// switch between roll and pitch(triangle button)

		if (b_Triangle == toggle) {
			toggle = 0;
		}
		else if (b_Triangle == 1) {
			toggle = 1;
		}

		// Scale your output value


		if (toggle == 0) {
			roll_rad = roll(x);
			scaled_value = scaleRadsForScreen(roll_rad);
		}
		else if (toggle == 1) {
			pitch_rad = pitch(z);
			scaled_value = scaleRadsForScreen(pitch_rad);
		}

		// Output your graph line
	
		graph_line(scaled_value);

		fflush(stdout);

	} 
	while (getValues == 1);
	// Modify to stop when the square button is pressed
	return 0;
}