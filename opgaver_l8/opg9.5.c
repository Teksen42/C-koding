#include <stdio.h>   // printf
#include <stdlib.h>  // malloc, free, rand, srand, qsort
#include <time.h>    // time (bruges til at "seede" rand)

int compare_doubles(const void *ep1, const void *ep2); // Prototype på compare-funktionen til qsort

int main(void) {
    int antal = 100; // Antal elementer i vores array

    // Allokerer dynamisk hukommelse til 100 doubles
    // malloc returnerer en pointer til det allokerede område (eller NULL ved fejl)
    double *lager = malloc(sizeof(double) * antal);

    // Tjekker om malloc lykkedes
    if (lager == NULL) {
        printf("Fejl: kunne ikke allokere hukommelse\n");
        return 1; // Afslut med fejlkode
    }

    // "Seeder" (initialiserer) tilfældighedsgeneratoren med nuværende tid
    // Så får du forskellige tal hver gang programmet køres
    srand(time(NULL));

    // Fylder arrayet med tilfældige decimaltal
    for (int i = 0; i < antal; i++) {
        // rand() giver et heltal.
        // rand() % 10000 giver tal fra 0..9999
        // divideret med 100.0 giver 0.00..99.99 som double
        lager[i] = (double)(rand() % 10000) / 100.0;
    }

    // Udskriv de usorterede tal
    printf("--- USORTERET ---\n");
    for (int i = 0; i < antal; i++) {
        printf("%.2f ", lager[i]); // %.2f viser tallet med 2 decimaler
    }
    printf("\n\n");

    // qsort sorterer "in-place" (direkte i arrayet)
    // Parametre:
    // 1) pointer til starten af arrayet
    // 2) antal elementer
    // 3) størrelse på hvert element (sizeof(double))
    // 4) compare-funktion der sammenligner to elementer
    qsort(lager, antal, sizeof(double), compare_doubles);

    // Udskriv de sorterede tal
    printf("--- SORTERET ---\n");
    for (int i = 0; i < antal; i++) {
        printf("%.2f ", lager[i]);
    }
    printf("\n\n");

    // Frigiver den dynamisk allokerede hukommelse
    free(lager);

    // God praksis: sæt pointeren til NULL efter free, så man ikke kommer til at bruge den bagefter
    lager = NULL;

    printf("Hukommelse frigivet. Programmet er faerdigt.\n");

    return 0; // Succes
}

// Compare-funktion til qsort.
// qsort sender to "void *" ind (peger på elementer i arrayet).
// Vi caster dem til (const double *) så vi kan sammenligne værdierne.
int compare_doubles(const void *ep1, const void *ep2) {
    
    const double *val1 = (const double *)ep1; // Peger på første double
    const double *val2 = (const double *)ep2; // Peger på anden double
    // Returnér:
    // - negativ hvis *val1 < *val2
    // - positiv hvis *val1 > *val2
    // - 0 hvis de er ens
    if (*val1 < *val2) {
        return -1;
    } else if (*val1 > *val2) {
        return 1;
    } else {
        return 0;
    }
}
