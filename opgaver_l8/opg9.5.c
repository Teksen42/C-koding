/*Opgave 9.5
Dynamisk allokering og qsort


Brug malloc til at allokere plads til 100 doubles. Check at allokeringen blev gennemført, og dealloker dit lager når du er færdig med at bruge det.

Opfat det allokerede lager som et array af 100 doubles, og indskriv 100 tilfældige tal i dit array. Udskriv dem på skærmen.

Brug nu qsort til at sortere dine tal. Udskriv dem igen, så du kan se at dit array rent faktisk er blevet sorteret.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Bruges til at lave tilfældige tal

int compare_doubles(const void *ep1, const void *ep2);

int main (void){
    int antal = 100;
    double *lager = malloc(sizeof(double) * antal);

    if (lager == NULL) {
    printf("Fejl: kunne ikke allokere hukommelse\n");
    return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < antal; i++) {
        // Laver et tilfældigt decimaltal (f.eks. mellem 0.0 og 100.0)
        lager[i] = (double)(rand() % 10000) / 100.0;
    }

    // Udskriv de usorterede tal
    printf("--- USORTERET ---\n");
    for (int i = 0; i < antal; i++) {
        printf("%.2f ", lager[i]);
    }
    printf("\n\n");

    qsort(lager, antal, sizeof(double), compare_doubles);

    printf("--- SORTERET ---\n");
    for (int i = 0; i < antal; i++) {
        printf("%.2f ", lager[i]);
    }
    printf("\n\n");


    free (lager);
    lager = NULL;

    printf("Hukommelse frigivet. Programmet er faerdigt.\n");

    return 0;
}

int compare_doubles(const void *ep1, const void *ep2) {
    const double *val1 = ep1;
    const double *val2 = ep2;

       if (*val1 < *val2) {
        return -1; // Returner et negativt tal
    }
    else if (*val1 > *val2) {
        return 1;  // Returner et positivt tal
    }
    else {
        return 0;  // Returner 0 (de er ens)
    }
}
