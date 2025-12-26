#include <stdio.h>
#include <stdlib.h>

enum planeter {merkur, venus, jorden, mars, jupiter, saturn, uranus, neptun};
typedef enum planeter planeter;

planeter planeter_of_char(char c);
void print_planeter(enum planeter p);
int circumference(planeter p);


int main(void){
  circumference (merkur);
  circumference (venus);
  circumference (jorden);
  circumference (mars);
  circumference (jupiter);
  circumference (saturn);
  circumference (uranus);
  circumference (neptun);

 
  printf("Indtast det planet du vil vide omkredsen af. Mulighederne er (merkur, venus, jorden, mars, jupiter, saturn, uranus, neptun) : \n");
  


  return 0;
}

void print_solsystemet(solsystemet s){
  switch (h){
     case merkur:
       printf("15.329km");
       break;
     case venus:
       printf("38.051km");
       break;
     case jorden:
       printf("40.075km");
       break;
     case mars:
       printf("21.344km");
       break;
     case jupiter:
       printf("140.128km");
       break;
     case saturn:
       printf("120.536km");
       break;
     case uranus:
       printf("49.528km");
       break;
     case neptun:
       printf("49.528km");
       break;
     default:
       printf("Forkert valg");
  }
}

planeter planeter_of_char(char c){
  planeter p;
  switch (c){
    case 'm':
      h = merkur;
      break;
    case 'v':
      h = venus;
      break;
    case 'j':
      h = jorden;
      break;
    case 'm':
      h = mars;
      break;
    case 'j':
      h = jupiter;
      break;
    case 's':
      h = saturn;
      break;
    case 'u':
      h = uranus;
      break;
    case 'n':
    default:
      printf("Forkert karakter!\n");
      exit(EXIT_FAILURE);
  }
  return p;
}

