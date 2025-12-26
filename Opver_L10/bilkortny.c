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
bilkort input_kort(void);

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

  printf("\nIndtast nyt bilkort:\n");
  bilkort b = input_kort();
  print_bil(b);
  
  return 0;
} 

bilkort input_kort(void){
  //Brugeren intaster navn, topfart, hestkrafter, osv osv.
  char n[NAME_LEN + 1];
  printf("Indtast navn: ");
  scanf("%s", n);

  int tf;
  printf("Indtast topfart: ");
  scanf("%d", &tf);

  int hk;
  printf("Indtast hestekrafter: ");
  scanf("%d", &hk);

  int a;
  printf("Indtast acceleration: ");
  scanf("%d", &a);

  int c;
  printf("Indtast ccm: ");
  scanf("%d", &c);

  //Oprettet bilkort
  bilkort b;

  //lægge navn, topfarts, osv ind i kort.
  strcpy(b.navn, n);
  b.topfart = tf;
  b.hestekraft = hk;
  b.acc = a;
  b.ccm = c;
  
  return b;
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
