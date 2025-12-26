#include <stdio.h>

#define NAME_LEN 20

struct stamtrae {
  char tophund[NAME_LEN + 1];
  struct stamtrae *mor;
  struct stamtrae *far;
};

typedef struct stamtrae stamtrae;

void print_trae(stamtrae t, int indent);

int main(void){
  stamtrae daisy = {"Daisy", NULL, NULL};
  stamtrae rollo = {"Rollo", NULL, NULL};
  stamtrae molly = {"Molly", &daisy, &rollo};
  stamtrae king = {"King", NULL, NULL};
  stamtrae stella = {"Stella", &molly, &king};

  print_trae(stella,0);

  return 0;
}

void print_trae(stamtrae t, int indent){
  //print mellem til indrykning
  for(int i = 0; i < indent; i++){
    printf(" ");
  }

  printf("%s\n", t.tophund);
  if(t.mor != NULL){
    print_trae(*(t.mor), indent + 1);
  }
  if(t.far != NULL){
    print_trae(*(t.far), indent + 1);
  }
}
