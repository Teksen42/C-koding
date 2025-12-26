#include <stdio.h>
#include <stdlib.h>

enum hand {rock, paper, scissors};
typedef enum hand hand;

hand hand_of_char(char c);
void print_hand(enum hand h);

int main(void){
  char spiller1_input, spiller2_input;
 
  //Tag imod input fra spillerne
  printf("Spiller 1 indtast din haand (r/p/s): \n");
  scanf(" %c", &spiller1_input);

  printf("Spiller 2 indtast din haand (r/p/s): \n");
  scanf(" %c", &spiller2_input);

  hand spiller1, spiller2;
  spiller1 = hand_of_char(spiller1_input);
  spiller2 = hand_of_char(spiller2_input);


  //Udskriv hænderne
  printf("\nspiller1: ");
  print_hand(spiller1);
  printf("\nspiller2: ");
  print_hand(spiller2);
  printf("\n");

  //Regn ud om spiller 1 har vundet
  int spiller1_vandt = (spiller1 == scissors && spiller2 == paper) ||
                       (spiller1 == paper && spiller2 == rock) ||
                       (spiller1 == rock && spiller2 == scissors);

  int uafgjort = (spiller1 == spiller2);

  //Skriv på skærmen hvem der vandt eller om det blev uafgjort
  if(spiller1_vandt){
    printf("Spiller 1 vandt.\n");
  } else if(uafgjort){
    printf("Det blev uafgjort.\n");
  } else {
    printf("Spiller 2 vandt.\n");
  }

  return 0;
}

void print_hand(hand h){
  switch (h){
     case rock:
       printf("rock");
       break;
     case paper:
       printf("paper");
       break;
     case scissors:
       printf("scissors");
       break;
     default:
       printf("Forkert hand");
  }
}

hand hand_of_char(char c){
  hand h;
  switch (c){
    case 'r':
      h = rock;
      break;
    case 'p':
      h = paper;
      break;
    case 's':
      h = scissors;
      break;
    default:
      printf("Forkert karakter!\n");
      exit(EXIT_FAILURE);
  }
  return h;
}

