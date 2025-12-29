// I lektionen om iterative kontrolstrukturer arbejdede vi med to opgaver, 
// som vi nu vil tage op igen med det formål at indføre abstraktion med funktioner.

// I opgave programmeringsopgave 1 side 267 (i Problem Solving and Program Design in C,
// eighth edition) summerede vi alle heltal fra 1 til n, og vi sammenlignede værdien 
// af denne sum med (n + 1)* n / 2. Skriv nu følgende to funktioner:

// En funktion sum_iter med én int parameter n. Funktionen skal addere alle heltal fra 1 til n. 
// Funktionen skal returnere denne sum.
// En funktion sum_formula med én int parameter n som indkapsler beregningen af (n + 1)* n / 2, 
// og som returnerer værdien af dette udtryk.
// I skal kalde disse to funktioner på passende input og sammenligne deres resultater (ligesom i 
// den oprindelige opgave).

// I lektionen om iterative kontrolstrukturer arbejdede vi også med opgave 1 side 181 i bogen. 
// Vi har en befolkning på 9870 personer som vokser med 10% per år. 
// Spørgsmålet var hvor mange år der går inden befolkningstallet er mere end 30000.

//Skriv nu en funktion som generaliserer denne opgave. Mere specifikt:

//En funktion population_projection med tre double parametre: start-befolkningstallet, vækstprocent 
//pr år, og den øvre grænse af befolkningstallet. Funktionen skal returnere det antal år 
//(af typen int) det tager for befolkningen at vokse fra start-befolkningstlalet til 
//mere end slut-befolkningstallet.
//Kald derefter funktionen så den løser opgaven fra side 181 i bogen (med de tre givne tal 9870, 10% og 30000).

#include <stdio.h>

// opgave 1

int sum_iter (int n);
int sum_formula (int n);
int population_projection (double start_befolkningstallet, double vaekstprocent_pr_aar, double oevre_graense_af_befolkningstallet);

int main (void){
//  Opgave 1
    int n = 10;
    int total = sum_iter(n);
    int formel_total = sum_formula(n);
    if(total == formel_total)
    {
        printf("Formlen er korrekt \n");
    }
    else{
        printf("Formlen passer ikke \n");
    }

//  Opgave 2
    int pp = population_projection(9870.0, 1.1, 30000.0);
    printf ("Der gaar %d aar indtil populationen er over 30000 \n", pp);
    return 0;
}

//  Opgave 1
int sum_iter (int n){
    int total = 0, i;
    for(i = 1; i <= n; i++) 
    {
        total = total + i;
    }    
    return total;
}

//  Opgave 1
int sum_formula (int n){
    int formel_total = (n * (n + 1)) / 2;
    return formel_total;
}

//  Opgave 2
int population_projection (double start_befolkningstallet, double vaekstprocent_pr_aar, double oevre_graense_af_befolkningstallet){
    int count_years = 0;

    while (start_befolkningstallet < oevre_graense_af_befolkningstallet) {
        start_befolkningstallet = start_befolkningstallet * vaekstprocent_pr_aar; 
        count_years++;
    }
    printf("AAr %d: befolkning er nu %.0f\n", count_years, start_befolkningstallet);

    return count_years;
}