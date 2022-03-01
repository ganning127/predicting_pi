#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double get_pi(int darts);                   // get a predicted value of pi
double rand_double(double min, double max); // get a random double between min and max

int main(void)
{
    int increments[] = {1, 10, 1000, 100000}; // increments for the number of darts
    const double MATH_PI = 3.14159265358979323846;
    int darts = 1;    // the number of darts thrown
    int decimals = 0; // number of decimals that we want to predict
    int wrong;        // number of wrong predictions
    double pred_pi;   // predicted pi
    srand(time(0));   // seed the random number generator

    while (decimals < 4) // loop until we have reached 3 decimals (inclusive), which means 4 digits
    {
        wrong = 0;                    // reset the number of wrong predictions
        for (int i = 0; i < 100; i++) // loop 100 times in order to test accuracy
        {
            pred_pi = get_pi(darts); // get the predicted pi
            if ((int)(pred_pi * pow(10, decimals)) != (int)(MATH_PI * pow(10, decimals)))
                wrong += 1; // if the prediction is wrong, increment the number of wrong predictions
            if (wrong > 5)
            {
                darts += increments[decimals]; // if the number of wrong predictions is greater than 5, increment the number of darts, because at least 95% accuracy was not reached
                break;                         // break out of the loop and start by resetting the number of wrong predictions
            }
        }
        if (wrong <= 5)
        {
            printf("Darts: %d || Decimal places: %d || Example PI: %f\n", darts, decimals, pred_pi); // print out results when we have less than 5 wrong predictions
            decimals += 1;                                                                           // increment the number of decimals
        }
    }

    puts(""); // print a new line

    return 0;
}

double get_pi(int darts)
{
    int hits = 0;                   // number of hits within the circle
    for (int i = 0; i < darts; i++) // loop through all the darts thrown
    {
        double x = rand_double(-1, 1); // get a random x value
        double y = rand_double(-1, 1); // get a random y value

        if (x * x + y * y <= 1) // equation of a circle
            hits++;             // if the dart is within the circle, increment the number of hits
    }

    return 4.0 * (double)hits / darts; // return the predicted pi
}

double rand_double(double min, double max)
{
    return ((max - min) * ((double)rand() / RAND_MAX)) + min; // return a random double between min and max
}