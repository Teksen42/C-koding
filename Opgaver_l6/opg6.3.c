/*Dette program handler om seddeludlevering fra en amerikansk pengeautomat, 
hvor der kun anvendes 100, 50, 20 og 10 dollar sedler.

Målet med programmet er at arbejde med både input og outputparametre af en funktion.

Programmet skal som input acceptere et dollar beløb, der er dividerbart med 10. 
Programmet skal beregne antallet af udleverede 100, 50, 20 og 10 dollar sedler svarende til beløbet. 
Der skal udleveres så få sedler som muligt.

Problemet skal løses med en funktion der tager både input og output parametre. 
Beløbet, der skal veksles, skal være en input parameter. Antallet af udleverede 100, 50, 20 og 10 dollar sedler 
skal være output parametre.*/

#include <stdio.h>

#define HUNDRED_DOLLAR  100
#define HALVTREDS_DOLLAR 50
#define TYVE_DOLLAR      20
#define TI_DOLLAR        10

void regne_penge(int total_belob, int *hundred, int *halvtreds, int *tyve, int *ti);

int main(void){
    int total;
    int h100, h50, t20, t10;
    printf("Indtast det belob du vil haeve. Belobet skal vaere helt tal, og dividerbart med 10.\n");
    scanf("%d", &total);
    if (total > 0 && total % 10 == 0)
    {   
        regne_penge(total, &h100, &h50, &t20, &t10);
        printf("Dine penge bliver haevet nu \n");
        printf("Du faar %d hundrede sedler, %d halvtredser sedler, %d tyver sedler og %d tier sedler \n", h100, h50, t20, t10);
    }
    else
    {
        printf("Det er ikke muligt at haeve dit valgte belob.");
    }

    return 0;
}

void regne_penge(int total_belob, int *hundred, int *halvtreds, int *tyve, int *ti){
    *hundred = total_belob / HUNDRED_DOLLAR;
    total_belob = total_belob % HUNDRED_DOLLAR;
    *halvtreds = total_belob / HALVTREDS_DOLLAR;
    total_belob = total_belob % HALVTREDS_DOLLAR;
    *tyve = total_belob / TYVE_DOLLAR;
    total_belob = total_belob % TYVE_DOLLAR;
    *ti = total_belob / TI_DOLLAR;
}