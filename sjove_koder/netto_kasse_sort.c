#include <stdio.h>
#include <stdlib.h>

int double_compare(const void *p1, const void *p2);
double *indlaes_varer(int antal_varer);

int main(void){
  int antal_varer;
  double *kasse;
  int length;
  int n;

  printf("Indtast antal varer: \n");
  scanf("%d", &antal_varer);

  kasse = indlaes_varer(antal_varer);

  //Priser printes
  printf("\n\nHer er priserne:\n");
  for(int i = 0; i < antal_varer; i++){
    printf("Index: %d. Vaerdi: %.2lf\n", i, kasse[i]);
  }

  //Kassen bliver sorteret
  qsort(kasse, antal_varer, sizeof(double), double_compare);

  //Priser printes
  printf("\n\nHer er priserne sorteret:\n");
  for(int i = 0; i < antal_varer; i++){
  printf("Index: %d. Vaerdi: %.2lf\n", i, kasse[i]);
  }

  //Samlet sum 
  double samlet_sum = 0;
  for(int i = 0; i < antal_varer; i++){
    samlet_sum += kasse[i];
  }

  free(kasse);

  printf("Du skal betale: %lf\n", samlet_sum);

  return 0;
}

double *indlaes_varer(int antal_varer){
  double *kasse = (double *) malloc(antal_varer * sizeof(double));
  if(kasse == NULL){
    printf("Det lykkedes ikke at allokere lageret.");
    exit(EXIT_FAILURE);
  }

  for(int i = 0; i < antal_varer; i++){
    double pris;
    printf("Indtast pris: ");
    scanf("%lf", &pris);
    kasse[i] = pris;
  }

  return kasse;
}

int double_compare(const void *p1, const void *p2){
  double *dp1;
  double *dp2;
  dp1 = (double *) p1;
  dp2 = (double *) p2;
  double d1 = *dp1;
  double d2 = *dp2;

  if(d1 < d2){
    return -1;
  } else if (d1 > d2) {
    return 1;
  } else {
    return 0;
  }
}