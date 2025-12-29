//https://people.cs.aau.dk/~normark/impr-c/more-control-more-iteration-while-slide-exercise-2.html
#include <stdio.h>

int main(void) {
    // 1. Vi opretter variablerne fra opgaven
    int m, n, k;
    int sum = 0; // Vigtigt: Sum skal starte på 0, ellers får du "snavs"

    // Her beder vi brugeren indtaste tallene (f.eks. "5 13 3")
    printf("Indtast m, n og k: ");
    scanf("%d %d %d", &m, &n, &k);

    // 2. Loopet: Går fra m til og med n
    // Hvis m er større end n (f.eks. 10 til 5), kører loopet slet ikke (som opgaven kræver)
    for (int i = m; i <= n; i++) {
        
        // 3. Betingelsen: Går k op i tallet?
        // Vi bruger modulo (%), som tjekker om resten er 0 ved division
        if (i % k == 0) {
            sum = sum + i; // Læg tallet til summen
        }
    }

    // 4. Udskriv resultatet
    printf("Resultatet er: %d\n", sum);

    return 0;
}