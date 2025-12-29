#include <stdio.h>
#include "primes.h"

int tjek_goldbach(int n) {
    for(int i = 3; i <= n/2; i += 2){
    
        if (is_prime(i) && is_prime(n-i))
        {
            return 1; 
        }       
    }
    
    return 0;
}