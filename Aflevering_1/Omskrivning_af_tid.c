#include <stdio.h>

int main(void){
    int          antal_sekunder, sekunder;
    int          antal_minutter, minutter;
    int             antal_timer,    timer;
    int              antal_dage,     dage;
    int              antal_uger,     uger;
    int           timer_minutter_sekunder;

    printf("Indtast antal sekunder: \n");
    scanf("%d", &antal_sekunder);

    sekunder = antal_sekunder % 60;      //for antal sekunder
    antal_minutter = antal_sekunder / 60;
    minutter = antal_minutter % 60;      //for antal minutter
    antal_timer = antal_minutter / 60;
    timer = antal_timer % 24;            //for antal timer
    antal_dage = antal_timer / 24;
    dage = antal_dage % 7;               //for antal dage
    uger = antal_dage / 7;               //for antal uger

    printf("%d uger, %d dage, %d timer, %d minutter, %d sekunder\n", uger, dage, timer, minutter, sekunder);

    return 0;
}


