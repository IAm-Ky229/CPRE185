// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
// Updated for Esplora 2013 TeamRursch185
// Updated for DualShock 4 2016 Rursch


// Headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <time.h>

// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLS for the screen height and width (set by system)
// MAXIMUMS
#define NUMCOLS 100
#define NUMROWS 72

// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '


// 2D character array which the maze is mapped into
char MAZE[NUMROWS][NUMCOLS];


// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty);

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void);

// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

// PRE: -1.0 < x_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the roll function written in previous labs.  
float calc_roll(float x_mag);

// Main - Run with './ds4rd.exe -t -g -b' piped into STDIN
int main(int argc, char* argv[])
{
	if (argc <2) { printf("You forgot the difficulty\n"); return 1;}
	int difficulty = atoi(argv[1]); // get difficulty from first command line arg
	// setup screen    
	initscr();
	refresh();

	// Generate and draw the maze, with initial avatar

	srand(time(NULL));
	generate_maze(difficulty);
	draw_maze();

	// Read gyroscope data to get ready for using moving averages.   
	int time, button_T, button_C, button_X, button_S;
	double gx, gy, gz;
	int y = 0;
	int timeI = 0;
	int x = NUMCOLS / 2;
	// Event loop

	do
	{
		// Read data, update average
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &time, &gx, &gy, &gz, &button_T, &button_C, &button_X, &button_S);
	
		// Is it time to move?  if so, then move avatar
		
		double move = calc_roll(gx);
		
		draw_character(x, y, AVATAR);
		
		//Selected time interval
		if (time - timeI > 500) {

			//Should I move right? Should I move left? Should I move at all?
			if (move < -.15) {
				if ((MAZE[y][x - 1] == EMPTY_SPACE) && (!(x < 1))) {
					x--;
					draw_character(x, y, AVATAR);
					draw_character(x + 1, y, EMPTY_SPACE);
				}
			}
			else if (move > .15) {
				if ((MAZE[y][x + 1] == EMPTY_SPACE) && (!(x > 98))) {
					x++;
					draw_character(x, y, AVATAR);
					draw_character(x - 1, y, EMPTY_SPACE);
				}
			}

			//Is it ok to move down?
			if (MAZE[y+1][x] == EMPTY_SPACE) {
				y++;
			draw_character(x, y, AVATAR);
			
			draw_character(x, y - 1, EMPTY_SPACE);

		}
		timeI = time;
		}

			
		
	} while(!(y == 71)); // Has the user navigated through all of the rows? 

	// Print the win message
	endwin();
	
	printf("YOU WIN!\n");
	return 0;
}



// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//
//    >>>>DO NOT CHANGE THIS FUNCTION.<<<<
void draw_character(int x, int y, char use)
{
	mvaddch(y,x,use);    
	refresh();
}

void generate_maze(int difficulty) {
	int i, j;
	for (i = 0; i < NUMROWS; i++) {
		for (j = 0; j < NUMCOLS; j++) {
			int probability = rand() % 100;
			if (probability < difficulty) {
				MAZE[i][j] = WALL;
			}
			else {
				MAZE[i][j] = EMPTY_SPACE;
			}
		}
	}
}

void draw_maze(void) {
	int i, j;
	for (i = 0; i < NUMROWS; i++) {
		for (j = 0; j < NUMCOLS; j++) {
			draw_character(j, i, MAZE[i][j]);
		}
	
	}
}

float calc_roll(float x_mag) {
	if (x_mag < -1) {
		x_mag = -1;
	}
	if (x_mag > 1) {
		x_mag = 1;
	}
	return asin(x_mag) * -1.0;
}
