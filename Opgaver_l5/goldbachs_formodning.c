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

int main (void){
    int start = 8;
    int slut = 2000000;
    int n;

    printf("Starter test af Goldbach for tal mellem %d og %d...\n", start, slut);
    //for(hvor skal den starte; hvad er betingelsen hvornår skal den kører; hvad skal opdateres)
    for(n = start; n <= slut; n+=2)
    {
        // Her kalder vi funktionen med n:
        if (tjek_goldbach(n) == 0) 
        {
        
            // Hvis vi lander her, sagde funktionen 0 (Nej/Falsk).
            printf("Fejl! Tallet %d virker ikke.\n", n);
            return 0;
        }
    

    }
    printf("Test faerdig! Ingen fejl fundet. Teorien holder!\n");
    return 0;
}