#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double get_pi(int darts);
float rand_float(float min, float max);

int main(void)
{
    int increments[] = {1, 10, 1000, 100000, 1000000, 10000000, 100000000}; // the current one on the midterm latex is with one more zero in element 4 (starting from 1)
    const double MATH_PI = 3.14159265358979323846;
    int darts = 1;
    int decimals = 0;
    int wrong;
    double pred_pi;
    srand(time(0));

    while (decimals <= 5)
    {
        wrong = 0;
        for (int i = 0; i < 100; i++)
        {
            pred_pi = get_pi(darts);
            // printf("pred_pi: %f, pi: %f\n", (pred_pi * pow(10, decimals), (MATH_PI * pow(10, decimals))));
            // printf("pred_pi: %d, pi: %d\n", (int)(pred_pi * pow(10, decimals)), (int)(MATH_PI * pow(10, decimals)));
            if ((int)(pred_pi * pow(10, decimals)) != (int)(MATH_PI * pow(10, decimals)))
            {
                wrong += 1;
            }
            if (wrong > 5)
            {
                darts += increments[decimals];
                // printf("%d\n", darts);
                break;
            }
        }
        if (wrong <= 5)
        {
            printf("Darts: %d || Decimal places: %d || Example PI: %f\n", darts, decimals, pred_pi);
            decimals += 1;
        }
    }

    puts("");

    return 0;
}

double get_pi(int darts)
{
    int hits = 0;

    for (int i = 0; i < darts; i++)
    {
        double x = (double)rand_float(-1, 1);
        double y = (double)rand_float(-1, 1);

        if (x * x + y * y <= 1)
        {
            hits++;
        }
    }

    return 4.0 * (double)hits / (double)darts;
}

float rand_float(float min, float max)
{
    return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}