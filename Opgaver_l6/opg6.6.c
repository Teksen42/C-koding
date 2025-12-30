/*Skriv et C program som konverterer valuta i dollars til euro, kroner, rubler og yen. I kan antage en én dollar er 0.89 euros, 6.66 kroner, 66.43 rubler og 119.9 yen.

I denne opgave skal der indgå en funktion med én input parameter (dollar-beløbet), og fire output parametre (svarende til de fire andre valutaer).

Brug funktionen til at udskrive en omregningstabel til omregning af 1, 2, 3, ... 100 dollars til de fire andre valutaer.

(Denne opgave svarer til programmeringsprojekt 1, side 384 i 7. udgave af lærebogen).*/

#include <stdio.h>

#define EURO_KURS    0.89
#define KRONER_KURS  6.66
#define RUBLER_KURS 66.43
#define YEN_KURS    119.9

void konvetere_valuta(int dollar, double *euro, double *kroner, double *rubler, double *yen);

int main (void){
    double e, k, r, y;
    for(int i=1; i <= 100; i++){
        konvetere_valuta(i, &e, &k, &r, &y);
        printf("%d dollar er det samme som %lf euro, %lf kroner, %lf rubler, %lf yen \n", i, e, k, r, y);
    }
    return 0;
}

void konvetere_valuta(int dollar, double *euro, double *kroner, double *rubler, double *yen){
    *euro = dollar * EURO_KURS;

    *kroner = dollar * KRONER_KURS;

    *rubler = dollar * RUBLER_KURS;
    
    *yen =  dollar * YEN_KURS;

}

