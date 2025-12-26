#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159

struct planet{
    char navn[30];
    double radius;
    double volumen;
    double masse;
};
typedef struct planet planet;

planet indlaes_planet(void);
void print_planet(planet p);

void gem_planeter_i_fil(FILE *f, planet b);

void gem_alle_planeter_i_fil(FILE *f, planet pa[], int length);

int main(void){
  planet p1 = {"Earth", 12756/2, 1.08e12, 5.97e24};
  planet p2 = {"Mars", 6792/2, 1.63e11, 6.42e23};
  planet pa[2] = {p1, p2};

    print_planet(p1);
    print_planet(p2);

  FILE *f = fopen("planeter.txt", "w");
  if(f == NULL){
    printf("Filen kunne ikke aabnes\n");
    exit(EXIT_FAILURE);
  }

  gem_alle_planeter_i_fil(f, pa, 2);

  fclose(f);

  return 0;
}

void gem_alle_planeter_i_fil(FILE *f, planet pa[], int length){
    for(int i = 0; i < length; i++){
        gem_planeter_i_fil(f, pa[i]);
    }
}

void gem_planeter_i_fil(FILE *f, planet p){
  //Skriv felter ind i f
  fprintf(f, "%s %lf %lf\n", p.navn, p.radius, p.masse);
}

planet indlaes_planet(void){
    planet min_planet;

    printf("Her: %lf\n", 4.0/3.0);

    printf("Indtast et navn: \n");
    scanf("%s", min_planet.navn);
    printf("Indtast radius: \n");
    scanf("%lf", &(min_planet.radius));
    printf("Indtast masse: \n");
    scanf("%lf", &(min_planet.masse));
    min_planet.volumen =(4.0/3.0)*PI*pow(min_planet.radius,3);

    return min_planet;
}

void print_planet(planet p){
    printf("Navn: %s\n", p.navn);
    printf("Radius: %lf\n", p.radius);    
    printf("Volumen: %lf\n", p.volumen);
    printf("Masse: %lf\n\n", p.masse);
}
