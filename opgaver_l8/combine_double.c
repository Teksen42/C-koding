#include <stdio.h>

double max(double, double);
double min(double, double);
double plus(double, double);
double minus(double, double);


//5. parameter er en function pointer.

double combine(double a, double b, double c, double d, 
                    double (*combiner)(double, double)){ 
                    
                        return combiner(a, combiner(b, combiner (c, d)));
                    }

int main(void) {
  double result;

   // Regnestykket bliver: 5 - (7 - (8 - 11)) = 5 - (7 - (-3)) = 5 - 10 = -5 
  result = combine(5, 7, 8, 11, &minus);  
  printf("Minus combination result: %f\n", result);

   // plus 5 + (7 + (8 + 11)) = 31
  result = combine(5, 7, 8, 11, &plus); 
  printf("Plus combination result: %f\n", result);


  //mindste tal ved at sammenligne dem parvis bagfra. Den starter med 8 og 11, 7 og 8, 5 og 7.
  result = combine(5, 7, 8, 11, &min); 
  //mindste bliver outputtet
  printf("Min combination result: %f\n", result);

  //største tal det omvendte af den forrige
  result = combine(5, 7, 8, 11, &max); 
  printf("Max combination result: %f\n", result);

  return 0;
}

//Her er funktionerne som for det ovenstående til at virke.
double max (double a, double b){
  return a > b ? a : b; //Hvis a er større end b så retunere den a, hvis nej så b.
}

// Returnerer det mindste af to tal 
double min (double a, double b){
  return a > b ? b : a; //Hvis a er større end b retunere den b, nej så a
}

// Lægger to tal sammen 
double plus(double a, double b){
  return a + b;
}

// Trækker b fra a 
double minus(double a, double b){
  return a - b;
}