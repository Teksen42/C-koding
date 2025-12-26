#include <stdio.h>
#include <math.h>

int main(void){
  double p1_x;
  double p1_y;
  double p2_x;
  double p2_y;
  double p3_x;
  double p3_y;

  //Brugeren angiver et linjestykke som to punkter i planet.
  printf("Indtast et punkt (x-koordinat mellemrum y-koordinat): \n");
  scanf(" %lf %lf", &p1_x, &p1_y);

  printf("Indtast endnu et punkt (x-koordinat mellemrum y-koordinat): \n");
  scanf(" %lf %lf", &p2_x, &p2_y);

  printf("Indtast endnu et punkt (x-koordinat mellemrum y-koordinat): \n");
  scanf(" %lf %lf", &p3_x, &p3_y);


  //Regn delta x
  double delta_x_1 = p1_x - p2_x;

  //Regn delta y
  double delta_y_1 = p1_y - p2_y;

  //Regn delta x
  double delta_x_2 = p2_x - p3_x;

  //Regn delta y
  double delta_y_2 = p2_y - p3_y;

   //Regn delta x
  double delta_x_3 = p3_x - p1_x;

  //Regn delta y
  double delta_y_3 = p3_y - p1_y;

  double laengde_1 = sqrt(delta_x_1 * delta_x_1 + delta_y_1 * delta_y_1);
  double laengde_2 = sqrt(delta_x_2 * delta_x_2 + delta_y_2 * delta_y_2);
  double leangde_3 = sqrt(delta_x_3 * delta_x_3 + delta_y_3 * delta_y_3);

  //Regn længden
  double laengde = laengde_1 + laengde_2 + leangde_3;

  //Programmet skriver længden ud
  printf("Her er laengden: %lf\n", laengde);


  return 0;
}
