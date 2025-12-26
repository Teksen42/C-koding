#include <stdio.h>

int oploeft(int tal, int potens);

int main(void){

  printf("Tre i fjerde er %d\n", oploeft(3,4));

  return 0;
}

int oploeft(int tal, int potens){
  if(potens == 0){
    return 1;
} else if (potens > 0 && potens % 2 == 0){
    int halv = oploeft(tal, potens / 2);
    return halv * halv;
  } else {
    return tal * oploeft(tal, potens-1);
  }
}

