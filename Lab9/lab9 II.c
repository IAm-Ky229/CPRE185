// Lab 9 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 0   // set to 0 to disable debug output
#define MAXONEROW 5

// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s);

void draw_character(int y, int x, char use);

void rowPlace(int index, int *row, int *column);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount, rowCount, extra;
	int i, j;
	int index = 0;
	wordCount = readWords(wordlist, argv[1]);
	rowCount = wordCount / 5;
	extra = wordCount % 5;
	int totalRows = (rowCount + extra);
	int row, column;
	if (DEBUG) {
		// add code to print the words to the screen here for part 1
	}

	// most of your code for part 2 goes here. Don't forget to include the ncurses library
	initscr();
	for (i = 0; i < wordCount; i++) {
		rowPlace(i, &row, &column);
		mvprintw(row, column, "%s", wordlist[i]);
		refresh();
		if (i > wordCount) {
			break;
		}

	}

	int x = 15;
	int y = 0;
	draw_character(y, x, '*');

	int k, num = 0;
	int time, b1, b2, b3, b4, j1_PRESS, j2_PRESS, j1_x, j1_y, j2_x, j2_y;
	int NA1, NA2, NA3, NA4, NA5, NA6;
	int timePrev = 0;
	int printWord = 0;
	int stringLengths[80];
	char *userString = malloc(sizeof(char) * 10);
	char *userSentence = malloc(sizeof(char) * 80);


	while (1) {
		scanf(" %d, %d,%d,%d,%d, %d,%d,%d,%d,%d,%d,%d,%d, %d, %d, %d, %d", &time, &b1, &b2, &b3, &b4, &j1_PRESS, &j2_PRESS, &NA1, &NA2, &NA3, &NA4, &NA5, &NA6, &j1_x, &j1_y, &j2_x, &j2_y);


		if ((time - timePrev) >= 150) {

			refresh();
			if ((j1_x < -60) && (!(x - 15 <= 0))) {
				draw_character(y, x, ' ');
				x = x - 15;
				draw_character(y, x, '*');
				printWord--;
			}
			if ((j1_x > 60) && (!(x + 15 > 75))) {
				draw_character(y, x, ' ');
				x = x + 15;
				draw_character(y, x, '*');
				printWord++;
			}
			if ((j1_y < -60) && (!(y - 1 < 0))) {
				draw_character(y, x, ' ');
				y = y - 1;
				draw_character(y, x, '*');
				printWord = printWord - 5;
			}
			if ((j1_y > 60) && (!(y + 1 >= totalRows))) {
				draw_character(y, x, ' ');
				y = y + 1;
				draw_character(y, x, '*');
				printWord = printWord + 5;
			}

			if (b1) {
				if (strlen(userSentence) < 80) {
					strcpy(userString, " ");
					strcat(userString, wordlist[printWord]);
					stringLengths[num] = strlen(userString);
					strcat(userSentence, userString);
					mvprintw(17, 5, "%s", userSentence);
					num++;
				}
				
			}

			if (b4) {
				if(strlen(userSentence) < 80) {
				strcpy(userString, wordlist[printWord]);
				stringLengths[num] = strlen(userString);
				strcat(userSentence, userString);
				mvprintw(17, 5, "%s", userSentence);
				num++;
				}
			}
	
			
			if (b3) {
				
					int length;
					length = strlen(userSentence);
					if (!(length == 0)) {
					for (k = length; k > length - stringLengths[num - 1]; k--) {
						userSentence[k] = ' ';
						mvprintw(17, k + 4, " ");
					}
					userSentence[k] = '\0';
					num--;
				}
				
				

			}
			if (j2_PRESS) {
				int n = 0;
				for(n = 0; n < 80; n++) {
					userSentence[n] = ' ';
					mvprintw(17, n + 5, " ");
				}
				userSentence[0] = '\0';
				num = 0;
			}

			timePrev = time;
		}

	}
	endwin();
}
int readWords(char* wl[MAXWORDS], char* filename) {
	char word[WORDLEN];
	int count = 0;
	FILE* f;
	f = fopen(filename, "r");


	while (fscanf(f, "%s", word) == 1) {
		trimws(word);
		wl[count] = (char*)malloc(sizeof(char)*(strlen(word) + 1));
		strcpy(wl[count], word);
		count++;
	}
	fclose(f);
	return count;
}

void trimws(char* s) {
	int index = 0;
	while ((s[index] != ' ') && (s[index] != '\0')) {
		index++;
	}
	s[index] = '\0';
}

void draw_character(int y, int x, char use) {
	mvaddch(y, x, use);
	refresh();
}

void rowPlace(int index, int *row, int *column) {
	
	*row = index / 5;

	*column = (((index % 5) * (WORDLEN + 4)) + 1);
}
