#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Generate random numbers using C's rand().

float random_gen()
{
    float random_number;
    random_number = ((float)rand())/RAND_MAX;
    return(random_number);
}

// Calculate the value of the integral.

float monte_carlo_sampling(int iterations)
{

    // Declare parameters.

    float x,y,z;
    float inside, outside;
    int rand_num;

    // Set seed.

    srand((float) time(NULL));

    // Perform Monte Carlo sampling.

    for (int i=0; i<iterations; i++)
    {
        x = random_gen();
        y = random_gen();
        z = random_gen();

        if (pow(x,2) + pow(y,2) + pow(z,2) <= 1)
        {
        inside++;
        }

        else
        {
            outside++;
        }
    }
    return(inside/iterations);
}

// Run the approximation. 

int main()
{
    int iterations;
    printf("How many iterations?\n");
    scanf("%d", &iterations);
    float approximate_area = 8 * monte_carlo_sampling(iterations);
    printf("The approximate area is %f\n", approximate_area);
}