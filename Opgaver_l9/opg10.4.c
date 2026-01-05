/*Skriv et program med en funktion der finder og returnerer det længste fælles endelse (suffix) af to ord.

Funktionen skal have tre parametre. De to ord (to tekststrenge) skal overføres som input parametre. Den længste fælles endelse skal returneres i en output parameter (også en tekststreng). (Hvordan markerer du forskellen på en input parameter og en output parameter, som begge er tekststrenge?) Overvej hvordan der bliver allokeret plads til tesktstrengen med den fælles endelse (vil du bruge statisk eller dynamisk allokering?).

Eksempelvis er "logi" den længste fælles endelse af ordene "datalogi" og "biologi". Og den længste fælles endelse af "program" og "diagram" er "gram".

Denne opgave svarer til opgave 8 side 533 i 6. udgave af lærebogen*/

#include <stdio.h>
#include <string.h>

// Funktionsprototype
// Bemærk: 'const' markerer input (læs-kun), manglende 'const' markerer output (skrivbar)
void findFaellesEndelse(const char *s1, const char *s2, char *resultat);

int main(void) {
    // Test 1: datalogi og biologi
    char ord1[] = "datalogi";
    char ord2[] = "biologi";
    char output1[50]; // Allokerer plads statisk (på stakken)
    
    findFaellesEndelse(ord1, ord2, output1);
    printf("1. '%s' og '%s' -> Fælles endelse: '%s'\n", ord1, ord2, output1);

    // Test 2: program og diagram
    char ord3[] = "program";
    char ord4[] = "diagram";
    char output2[50];
    
    findFaellesEndelse(ord3, ord4, output2);
    printf("2. '%s' og '%s'  -> Fælles endelse: '%s'\n", ord3, ord4, output2);

    // Test 3: Ingen fælles endelse
    char ord5[] = "bil";
    char ord6[] = "cykel";
    char output3[50];
    
    findFaellesEndelse(ord5, ord6, output3);
    printf("3. '%s' og '%s'    -> Fælles endelse: '%s'\n", ord5, ord6, output3);

    return 0;
}

// Funktionen der løser opgaven
void findFaellesEndelse(const char *s1, const char *s2, char *resultat) {
    // 1. Find længden af begge ord (hvor peger de sidste index?)
    int i = strlen(s1) - 1;
    int j = strlen(s2) - 1;

    // 2. Sammenlign bagfra
    // Vi kører så længe vi ikke er røget ud over starten (>= 0)
    // OG så længe bogstaverne er ens
    while (i >= 0 && j >= 0 && s1[i] == s2[j]) {
        i--;
        j--;
    }

    // Nu peger 'i' på det tegn, hvor ordene IKKE længere matcher (eller -1).
    // Den fælles endelse starter derfor på pladsen lige efter i (i + 1).
    
    // 3. Kopier resultatet
    // &s1[i + 1] er adressen hvor den fælles del starter i det første ord.
    strcpy(resultat, &s1[i + 1]);
}