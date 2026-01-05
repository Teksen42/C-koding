/*Opgave 9.3
Reduktion af et array


Vi har tidligere i undervisningsmaterialet set hvordan vi kan reducere/kombinere en række tal med en 'binær funktion' (en funktion fra to doubles til én double).

I denne opgave skal I skrive en funktion

  double combine_right (double a[], int n,  double (*combiner)(double, double))
        
som kombinerer alle n elementer i a, på samme måde som combine gør det for fire faste tal. Antag at n >= 2. Skriv først en version, combine_right, der kombinerer elementerne fra højre mod venstre. Skriv også gerne en version, combine_left, som kombinerer i den modsatte retning.

Afprøv dit program på tilsvarende måde, som vi gjorde da vi første gange mødte combine funktionen.*/
#include <stdio.h>


double max(double a, double b);
double min(double a, double b);
double plus(double a, double b);
double minus(double a, double b);

double combine_right(double a[], int n,  
                     double (*combiner)(double, double));
double combine_left(double a[], int n, 
                    double (*combiner)(double, double));

int main(void) {
  double result;
  double numbers[] = {5, 7, 8 , 11};
  int n = sizeof(numbers) / sizeof(double);
  
  printf("Combine Right:\n");
  printf("------------------\n");
  result = combine_right(numbers, n, &minus);  
  printf("Minus combination result: %f\n", result);

  result = combine_right(numbers, n, &plus); 
  printf("Plus combination result: %f\n", result);

  result = combine_right(numbers, n, &min); 
  printf("Min combination result: %f\n", result);

  result = combine_right(numbers, n, &max); 
  printf("Max combination result: %f\n", result);
  
  printf("\n");
  
  printf("Combine Left:\n");
  printf("------------------\n");
  result = combine_left(numbers, n, &minus);  
  printf("Minus combination result: %f\n", result);

  result = combine_left(numbers, n, &plus); 
  printf("Plus combination result: %f\n", result);

  result = combine_left(numbers, n, &min); 
  printf("Min combination result: %f\n", result);

  result = combine_left(numbers, n, &max); 
  printf("Max combination result: %f\n", result);


  return 0;
}

double combine_right(double a[], int n,  
                     double (*combiner)(double, double)){
  double result;
  
  for(int i = n-2; i >= 0; --i){
    if (i == n-2)
       result = combiner(a[i], a[i+1]);
    else
       result = combiner(a[i], result);
  }
    
  return result;  
}

double combine_left(double a[], int n, 
                     double (*combiner)(double, double)){
  double result;

  for(int i = 1; i < n; ++i){
    if (i == 1)
       result = combiner(a[i-1], a[i]);
    else
       result = combiner(result, a[i]);
  }

  return result;  
}


//Her er funktionerne som for det ovenstående til at virke.
double max(double a, double b){
  return a > b ? a : b; //Hvis a er større end b så retunere den a, hvis nej så b.
}

// Returnerer det mindste af to tal 
double min(double a, double b){
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
