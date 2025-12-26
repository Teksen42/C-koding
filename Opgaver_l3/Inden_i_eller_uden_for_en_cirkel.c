#include <stdio.h>
#include <math.h>
#include <stdbool.h> // bool

#define Delta 1e-9

int main(void){
    double r, x, y;

printf("Indtast cirklens radius (r) og derefter et punkts koordinater (x y).\n");
printf("Brug formatet [ r x y ]: ");

scanf("%lf %lf %lf", &r, &x, &y);

// Beregner afstanden fra cirklens centrum (0,0) til punktet (x,y).
// Bruger Pythagoras' sætning: afstand = kvadratroden af (x*x + y*y).
// 'sqrt()' funktionen kommer fra math.h.
double afstand = sqrt(x*x + y*y);

// Tjekker "på" (med plads til Delta-fejl)
    // Erklærer en logisk variabel (bool) 'er_paa'.
    // Udtrykket (fabs(afstand - r) < Delta) evalueres.
    // 'fabs()' (fra math.h) giver den absolutte (positive) forskel mellem afstand og radius.
    // Hvis denne forskel er mindre end vores fejlmargin (Delta), er punktet "på",
    // og 'er_paa' sættes til 'true' (sand). Ellers sættes den til 'false' (falsk).
    bool er_paa = (fabs(afstand - r) < Delta);

    // Tjekker "inden i"
    bool er_inden_i = (afstand < r);

    // Tjekker "uden for"
    bool er_uden_for = (afstand > r);


    // Brug af '?:' (betinget udtryk) til at vælge den rigtige tekst
    printf("Punktet er %s cirklen.\n", (er_paa ? "paa" : ((er_inden_i ? "inden i" : "uden for"))));

    //Den tjekker først om den er på cirklen, hvis true så stopper programmet og udskrifter "på". 
    //Hvis på cirkel er falsk, så tjekker den om er_inden_i cirklen om den er sand eller falsk. Hvis den er sand så stopper programmet og udskriver "inden_i"
    //    HVIS 'er_paa' var FALSK, OG 'er_inden_i' var FALSK,
    //    så *må* punktet være "uden for".
        
}