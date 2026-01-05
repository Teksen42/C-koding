/*Definer tre forskellige enumeration typer for hhv. forret, hovedret og dessert.

Enumeration typen forret skal indholde værdier for guacamole, tarteletter, lakserulle og græskarsuppe.

Enumeration typen hovedret skal indholde værdier for gyldenkål, hakkebøf, gullash og forloren hare.

Enumeration typen dessert skal indholde værdier for pandekager med is, gulerodskage, choklademousse, og citronfromage.

Undgå dog danske bogstaver i dit C program. Det giver kun besvær!

Skriv en funktion maaltid, som vælger og udskriver én tilfældig ret i hver af de tre kategorier. Læs om "tilfældige tal" i C her.

Kald funktionen maaltid 25 gange i main, med det formål at få genereret et menukort af 25 kombinationer af forret, hovedret og dessert.

Overvej om der skal defineres flere små funktioner, som nedbryder det samlede problem i delproblemer.

Denne opgave er inspireret af en tilsvarende opgave i bogen 'C by Dissection'. Benyttet med tilladelse fra forlaget.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum forret {guacamole, tarteletter, lakserulle, graeskarsuppe};

enum hovedret {gyldenkaal, hakkeboef, gullash, forloren_hare};

enum dessert {pandekager_med_is, gulerodskage, chokolademousse, citronfromage};

typedef enum forret forret;

typedef enum hovedret hovedret;

typedef enum dessert dessert;


void maaltid (void);


int main(void) {
    srand(time(NULL));   // Start random-generatoren

    for (int i = 0; i < 25; i++) {
        printf("Menu %d:\n", i + 1);
        maaltid();
        printf("\n");    // linjeskift mellem menuerne
    }

    return 0;
}



void maaltid (void){
    int tilf_f = rand() % 4;   // 0–3
    forret f = tilf_f;         // gør tallet til enum forret

    switch (f) 
    {
        case guacamole:
            printf("Forret: Guacamole\n");
            break;

        case tarteletter:
            printf("Forret: Tarteletter\n");
            break;

        case lakserulle:
            printf("Forret: Lakserulle\n");
            break;

        case graeskarsuppe:
            printf("Forret: Graeskarsuppe\n");
            break;
    }

    int tilf_h =rand() % 4;
    hovedret h = tilf_h;

    switch (h)
    {
        case gyldenkaal:
            printf("Hovedret: Gyldenkaal\n");
            break;
        
        case hakkeboef:
            printf("Hovedret: Hakkeboef\n");
            break;
        case gullash:
            printf("Hovedret: Gullash\n");
            break;
        case forloren_hare:
            printf("Hovedret: Forloren hare\n");
            break;
    }

    int tilf_d = rand() % 4;
    dessert d = tilf_d;

    switch (d) 
    {
        case pandekager_med_is:
            printf("Dessert: Pandekager med is\n");
            break;
        case gulerodskage:
            printf("Dessert: Gulerodskage\n");
            break;
        case chokolademousse:
            printf("Dessert: Chokolademousse\n");
            break;
        case citronfromage:
            printf("Dessert: Citronfromage\n");
            break;
    }   
}


