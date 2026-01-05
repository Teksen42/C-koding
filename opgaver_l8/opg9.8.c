/*På siden om tilfældige tal , har vi set en simpel funktion, der simulerer et kast med en terning.

I nogle sammenhænge er der behov for kast med n terninger, hvor n > 1. I det simple tilfælde kan vi naturligvis blot kaste én terning n gange (i en løkke). I andre tilfælde har vi behov for at have adgang til udfaldene af de n terninger samtidigt, i et array, for at kunne vurdere de n kast under ét. Vi vil senere på kurset få brug for netop denne mulighed.

Skriv derfor en funktion roll_multiple_dice, med en heltals parameter n, der kaster n terninger, og som afleverer et array af de n terningekast.

Afleveringen af de n kast kan ske på to måder: gennem en parameter af pointer type eller via funktionens returværdi. Allokering af arrayet kan også varieres: enten allokerer roll_multiple_dice plads, eller også er der allerede allokeret plads, når roll_multiple_dice kaldes. Hvis roll_multiple_dice allokerer plads med dynamisk lagerallokering, i hvert kald, udestår der et efterfølgende arbejde med passende kald af free.

Skriv, ud fra denne analyse, din foretrukning variant af funktionen roll_multiple_dice.

Programmer endvidere, i main, 10 kald af af roll_multiple_dice. Giv indledningsvis brugeren mulighed for at indlæse størrelsen n (antallet af terninger). Udskriv, for hvert kald af roll_multiple_dice, udfaldet af de n terningekast.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Bruges til at lave tilfældige tal

void roll_multiple_dice(int n, int results[]);

int main(void){
    srand(time(NULL));
    int n;
    do{
        printf("Hvor mange terninger vil du kaste?\n");
        scanf("%d", &n);
        if(n < 1){
            printf("Vaedien du indtaster, skal være et positivt hel tal \n");
        }
    }while(n < 1);

    int *kast = malloc(sizeof(int) * n);

    if (kast == NULL) {
        printf("Hukommelsesfejl!\n");
        return 1;
    }

    // Ydre løkke: Kør 10 simulationer
    for (int i = 0; i < 10; i++) {
        printf("Kast %2d: ", i + 1);
        
        // 1. Udfør selve kastet
        roll_multiple_dice(n, kast);
        
        // 2. Indre løkke: Udskriv resultatet af de n terninger
        for (int j = 0; j < n; j++) {
            printf("%d ", kast[j]);
        }
        printf("\n"); // Linjeskift efter hver række af n terninger
    }

    free(kast);
    kast = NULL;

    return 0;
}

void roll_multiple_dice(int n, int results[]) {
    for (int i = 0; i < n; i++) {
        results[i] = rand() % 6 + 1; // Tal fra 1 til 6
    }
}