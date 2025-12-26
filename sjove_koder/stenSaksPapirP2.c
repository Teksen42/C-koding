#include <stdio.h>

int main(void){
    //spillerne indtaster hænderne
    //'r' for rock
    //'p' for paper
    //'s' for scissor
    char haand1;
    char haand2;
    printf("Spiller 1, indtast haand (r,p,s):\n");
    scanf(" %c", &haand1);

    printf("Spiller 2, indtast haand (r,p,s):\n");
    scanf(" %c", &haand2);

    printf("%c %c\n", haand1, haand2);
    //Programmet udregner vinderen
    int spiller1_vandt = 
        ((haand1== 's') && (haand2 == 'p')) ||
        ((haand1== 'p') && (haand2 == 'r')) ||
        ((haand1== 'r') && (haand2 == 's'));

    int spiller2_vandt = 
        ((haand1== 's') && (haand2 == 'r')) ||
        ((haand1== 'p') && (haand2 == 's')) ||
        ((haand1== 'r') && (haand2 == 'p'));

    int uafgjort = (haand1 == haand2);
    //Programmet udskriver om spiller 1 vandt
if(spiller1_vandt){
    printf("Spiller 1 vandt\n");
}

if(spiller2_vandt) {
    printf("Spiller 2 vandt \n");
}

if(uafgjort){
    printf("Det blev uafgjort \n");
}
    return (0);
}