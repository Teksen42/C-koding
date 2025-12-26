#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum tal {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
typedef enum tal tal;

tal tal_of_char(char c);
void print_tal(enum tal t);
tal random_tal(void);

int main(void){
  srand(time(NULL));
  char spiller1_input;
 
  //Tag imod input fra spillerne
  printf("Gæt tallet mellem 0 og 10: \n");
  scanf(" %c", &spiller1_input);

  tal spiller1, computer;
  spiller1 = tal_of_char(spiller1_input);
  computer = random_tal();


  //Udskriv tallene
  printf("\nspiller1: ");
  print_tal(spiller1);
  printf("\ncomputer: ");
  print_tal(computer);
  printf("\n");

  //Regn ud om spiller 1 har vundet
  int spiller1_vandt = (spiller1 == computer);

  //Skriv på skærmen hvem der vandt eller om det blev uafgjort
  if(spiller1_vandt){
    printf("Spiller 1 vandt.\n");
  } else {
    printf("Spiller 1 gættet forkert.\n");
  }

  return 0;
}

tal random_tal(void){
  tal t;

  //Lav et tilfældigt tal (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  int r = rand() % 11;
 
  //Konverter det til en hånd
  t = (tal) r;

  return t;
}

void print_tal(tal t){
  switch (t){
     case 0:
       printf("0");
       break;
     case 1:
       printf("1");
       break;
     case 2:
       printf("2");
       break;
     case 3:
       printf("3");
       break;
     case 4:
       printf("4");
       break;
     case 5:
       printf("5");
       break;
     case 6:
       printf("6");
       break;
     case 7:
       printf("7");
       break;
     case 8:
       printf("8");
       break;
     case 9:
       printf("9");
       break;
     case 10:
       printf("10");
       break;
     default:
       printf("Forkert tal udenfra intervallet");
  }
}

tal tal_of_char(char c){
  tal t;
  switch (c){
    case '0':
      t = 0;
      break;
    case '1':
      t = 1;
      break;
    case '2':
      t = 2;
      break;
    case '3':
      t = 3;
      break;
    case '4':
      t = 4;
      break;
    case '5':
      t = 5;
      break;
    case '6':
      t = 6;
      break;
    case '7':
      t = 7;
      break;
    case '8':
      t = 8;
      break;
    case '9':
      t = 9;
      break;
    case '10':
      t = 10;
      break;
    default:
      printf("Forkert Tal!\n");
      exit(EXIT_FAILURE);
  }
  return t;
}

