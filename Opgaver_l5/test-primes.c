#include <stdio.h>
#include "primes.h"

int main (void)
{
    int n = 100;
    int count = 0;
    int current_number = 2;

    while (n > count)
    {
        if (is_prime(current_number)) 
        {
            count++;
            printf("prime %d: %d\n", count, current_number);
        }
        current_number++;
    }

    return 0;
}