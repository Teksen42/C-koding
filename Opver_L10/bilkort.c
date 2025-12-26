#include <stdio.h>
#include <string.h>

#define NAME_LEN 20


struct bilkort {
  char navn[NAME_LEN + 1];
  int topfart;
  int hestekraft;
  int acc;
  int ccm;
};
typedef struct bilkort bilkort;

void print_bil(bilkort b);
bilkort hurtigst(bilkort b1, bilkort b2);

int main(void){
  bilkort lotus =
    {"Lotus", 200, 110, 8, 1973};
  bilkort mercedes =
    {"Mercedes", 215, 160, 9, 4520};
  
  printf("\n\nFoerste bil:\n");
  print_bil(lotus);
  printf("\n\nAnden bil:\n");
  print_bil(mercedes);

  printf("\n\nDen hurtigste var:\n");
  bilkort h = hurtigst(lotus, mercedes);
  print_bil(h);
  
  return 0;
} 

bilkort hurtigst(bilkort b1, bilkort b2){
  bilkort h;
  if(b1.topfart > b2.topfart){
    h = b1;
  } else {
    h = b2;
  }
  return h;
}

void print_bil(bilkort b){
  //Vi hiver felterne ud af b
  
  char name[NAME_LEN + 1];
  strcpy(name, b.navn);
  int tf = b.topfart;
  int hk = b.hestekraft;
  int a = b.acc;
  int c = b.ccm;

  //Vi printer
  printf("Name: %s\n", name);
  printf("Topfart: %d\n", tf);
  printf("Hestekrafter: %d\n", hk);
  printf("Acceleration: %d\n", a);
  printf("ccm: %d\n", c);
}
