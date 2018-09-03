#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Here's the 64-bit xorshift pseudorandom number generator.
// The period of this algorithm is 2^64 - 1.

int xorshift64(int x)
{
    int r;
    x = x ^ (x >> 12);
    x = x ^ (x << 25);
    x = x ^ (x >> 27);

    r = x * 2685821657736338717;
    return(r);
}

// Run the generator.

int main()
{
    // Declare utility integer and seed.
    int execute;
    int seed;

    // Retrieve seed value.

    printf("What's the seed?\n");
    scanf("%d", &seed);
    int input = seed;

    // Retrieve utility value.

    printf("Press anything to continue. 0 to stop\n");
    scanf("%d", &execute);

    // Begin generation.

    while(execute != 0)
    {
        input = xorshift64(input);
        printf("Output is: ");
        printf("%d\n", input);
        printf("Continue?\n");
        scanf("%d", &execute);
    }

    // End.
    return(0);
}