#include<stdio.h>

#define RIGTIG 8

int main(void){
  int gaet;
  int antal_gaet = 0;


  do {
    printf("Gaet et tal mellem 1 og 20:");
    scanf("%d", &gaet);
    if gaet ||
    antal_gaet++;

    if(gaet == RIGTIG){
      printf("Hurra! Rigtigt!\n");
    } else {
      printf("Forkert\n");
    }
  } while(gaet != RIGTIG);

  printf("Spillet er slut!\n");
  printf("Du brugte %d gaet!\n", antal_gaet);

  return 0;
}