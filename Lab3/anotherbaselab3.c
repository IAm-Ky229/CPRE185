/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */


int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double  ax, ay, az;     


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        scanf("%8.3d,%7.4lf,%7.4lf,%7.4lf", &t, &ax, &ay, &az); 

/* CODE SECTION 0 */
        printf("Echoing output: %d, %lf, %lf, %lf\n", t, ax, ay, az);

/* CODE SECTION 1 */
        /*printf("At %d ms, the acceleration's magnitude was: %lf\n", 
            t, mag(ax, ay, az));  */
            
/* CODE SECTION 2 */
        /*printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
        minutes(t), seconds(t), millis(t), mag(ax,ay,az)); */

    }

return 0;
}

/* Put your functions here */


