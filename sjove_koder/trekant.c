#include <stdio.h>

int main(void){
  int n;
  int i;
  int j;

  //Indtast n og m
  printf("Indtast et heltal:\n");
  scanf(" %d", &n);

  //Gentager følgende n gange:
  //  Print tal og m stjerner <--
  for(j = 0; j < n; j++){
    printf("%d",j);
    for(i = 0; i < j; i++){
      printf("*");
    }
    printf("\n");
  }

  printf("Anders\n");

  return 0;
}
