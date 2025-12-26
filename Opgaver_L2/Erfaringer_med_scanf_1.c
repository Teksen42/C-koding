#include <stdio.h>

int main(void) {

  int c1, c2, c3, c4,   scanRes;

  printf("Enter input on the following line\n");
//Fordi der ikke er mellemrum mellem %c%c%c%c så får man ikke det rigtige resultat når man siger a b c d. Så tror programmet at a er først mellemrum andet b som tredje osv. Hvis der stod %c %c %c %c, så ville det virke.
  scanRes = scanf("%c%c%c%c", &c1, &c2, &c3, &c4);

  printf("c1 = %c, c2 = %c, c3 = %c, c4 = %c\n", c1, c2, c3, c4);
  printf("scanRes = %d\n", scanRes);

  return 0;
}