#include <stdio.h>

// ------------------------------------------------------------------
// 1. VÆRKTØJERNE (De funktioner, vi sender rundt)
// ------------------------------------------------------------------

// Opgavens krav: En funktion der halverer
double half(double x) {
    return x / 2.0;
}

// Hjælpefunktion til del 2: Lægger 1 til
double plus_one(double x) {
    return x + 1.0;
}

// ------------------------------------------------------------------
// 2. SELVE OPGAVEN (Funktionerne der styrer arbejdet)
// ------------------------------------------------------------------

// DEL 1: multi_apply
// f: Pointer til en funktion (den "plads" hvor vi sætter 'half' ind)
// n: Antal gentagelser
// s: Startværdien
double multi_apply(double (*f)(double), int n, double s) {
    double current_val = s; // Vi starter med s (f.eks. 16.0)

    for (int i = 0; i < n; i++) {
        // Vi kalder den funktion, f peger på.
        // Resultatet gemmes oven i current_val, så det er klar til næste runde.
        current_val = f(current_val);
    }
    
    return current_val;
}

// DEL 2: multi_apply_2
// f og g: To forskellige funktioner
double multi_apply_2(double (*f)(double), double (*g)(double), int n, double s) {
    double current_val = s;

    for (int i = 0; i < n; i++) {
        // Matematikken siger f(g(s)), så vi starter indefra:
        
        // 1. Kør g på tallet
        current_val = g(current_val);
        
        // 2. Kør f på resultatet fra g
        current_val = f(current_val);
    }

    return current_val;
}

// ------------------------------------------------------------------
// 3. MAIN (Her kobler vi tingene sammen)
// ------------------------------------------------------------------
int main() {
    // TEST 1: half, 4 gange, start med 16.0
    // Her sender vi adressen på 'half' op til 'multi_apply'
    double res1 = multi_apply(half, 4, 16.0);
    
    printf("Opgave 6.4 Del 1: Resultat = %.2f (Forventet: 1.00)\n", res1);

    // TEST 2: f=half, g=plus_one, 1 gang, start med 5.0
    // plus_one(5.0) -> 6.0.
    // half(6.0)     -> 3.0.
    double res2 = multi_apply_2(half, plus_one, 1, 5.0);
    
    printf("Opgave 6.4 Del 2: Resultat = %.2f (Forventet: 3.00)\n", res2);

    return 0;
}