/* Assignment 4: Write a code in C that calculates the Monte Carlo calculations of pi */
/* Author: Edison Lin */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    double radius, x, y, distance;
    int i, num_points, in_circle = 0;

    printf("Enter the radius of circle: ");
    scanf("%lf", &radius);

    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    srand(time(NULL));

    for(i = 1; i <= num_points; i++) 
    {
        x = (double)rand() / (double)RAND_MAX * radius; 
        y = (double)rand() / (double)RAND_MAX * radius;
        distance = ((x * x) + ((y - radius) * (y - radius)));

        printf("Point No.%d(x=%lf,y=%lf): ", i, x, y);
        if(distance <= (radius * radius)) 
	{
            printf("IN\n");
            in_circle++;
        } else 
	{
            printf("OUT\n");
        }
    }

    printf("\n/******In Summary******/\n");
    printf("Points within circle areas: %d\n", in_circle);
    printf("Points out of circle areas: %d\n", num_points - in_circle);
    printf("Pi = %lf\n", 4 * (double)in_circle / num_points);

    return 0;
}
