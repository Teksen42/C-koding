/*Skriv et program som oversætter udvalgte engelske navneord fra ental til flertal. Følgende regler skal overholdes:

Hvis et navneord ender i et "y" fjernes "y" og der tilføjes "ies".
Hvis et navneord ender i et "s", "ch" eller "sh" tilføjes et "es".
I alle andre tilfælde tilføjes et "s" til navneordet.
Udskriv hvert navneord i både ental og flertal.

Som altid skal du designe en funktion med et passende navn, og med parametre (input og evt. output). Og som altid laver vi top-down programmering ved trinvis forfinelse. Ønsker du at bruge returværdien af funktionen til noget?

Afprøv dit program på følgende engelske navneord:

chair dairy boss circus fly dog church clue dish
Alloker plads til disse i en passende array af tekststrenge.

Denne opgave svarer til opgave 5 side 532 i 6. udgave af lærebogen

Hints: Måske er funktionen strrchr fra string.h nyttig i denne opgave. Den søger efter et tegn fra bagenden af strengen. Husk også at du blot kan tilgå tegn i en tekststreng med array subscripting operatoren: str[i]. Du kan teste om et tegn i din streng svarer til et bestemt tegn: str[i] == 'y'.

*/

#include <stdio.h>
#include <string.h>

void lav_flertal(char *ental_ord, char *flertal_ord);

int main(void){
    char *navneord_ental[] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};
    for(int i = 0; i < 9; i++){
        //en tom tekststreng er klar til resultatet
        char flertal[50];

        //funktionen bliver kaldt
        //Den nuværende ord bliver sendt (navneord_ental[i]) og vores tomme buffer (flertal), til funktionen
        lav_flertal(navneord_ental[i], flertal);

        //Nu bliver resultatet udskrevet
        printf("%s -> %s\n", navneord_ental[i], flertal);
    }
    return 0;
}


void lav_flertal(char *ental_ord, char *flertal_ord){
strcpy(flertal_ord, ental_ord);
    
    // TRIN 2: Find længden af ordet, så vi kan finde sidste bogstav
    int len = strlen(flertal_ord);
    
    // Vi finder det sidste tegn (len - 1)
    // Vi finder også det næstsidste tegn (len - 2) hvis ordet er langt nok
    char sidste = flertal_ord[len - 1];
    char naestSidste = (len > 1) ? flertal_ord[len - 2] : 0;

    // TRIN 3: Tjek reglerne
    
    // REGEL 1: Ender på 'y' (f.eks. fly -> flies)
    if (sidste == 'y') {
        flertal_ord[len - 1] = '\0'; // Slet 'y' ved at afkorte strengen
        strcat(flertal_ord, "ies");  // Tilføj "ies"
    }
    
    // REGEL 2: Ender på 's', 'ch' eller 'sh' (f.eks. boss -> bosses, dish -> dishes)
    // Vi tjekker om det ender på 's'. 
    // ELLER om det ender på 'h' OG bogstavet før var 'c' eller 's'.
    else if (sidste == 's' || (sidste == 'h' && (naestSidste == 'c' || naestSidste == 's'))) {
        strcat(flertal_ord, "es");   // Tilføj "es"
    }
    
    // REGEL 3: Alle andre (f.eks. dog -> dogs)
    else {
        strcat(flertal_ord, "s");    // Tilføj bare "s"
    }
}