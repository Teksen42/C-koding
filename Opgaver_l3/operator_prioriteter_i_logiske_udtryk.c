//Opgave 3.2 Operator prioriteter i logiske udtryk
//https://people.cs.aau.dk/%7Enormark/impr-c/control-short-cuit-expr-ex-slide-exercise-1.html

#include <stdio.h>

int main(void){

  int a = 1, b = 2, c = 3;
  double x = 1.0;

  int res1, res2, res3, res4;

  // --- Opgave 1 ---
  // Original: res1 = a > b && c < x;
  // Prioritet: > og < (Niveau 10) regnes FØR && (Niveau 5)
  // 1. (a > b) -> (1 > 2) -> 0 (falsk)
  // 2. (c < x) -> (3 < 1.0) -> 0 (falsk)
  // 3. (0 && 0) -> (falsk OG falsk) -> 0
  res1 = ((a > b) && (c < x)); 

  // --- Opgave 2 ---
  // Original: res2 = a < ! b || ! ! a;
  // Prioritet: ! (Niveau 15) regnes FØR < (Niveau 10), som regnes FØR || (Niveau 4)
  // 1. (! b) -> (! 2) -> 0 (falsk, da 2 er "sand")
  // 2. (! ! a) -> (! (! 1)) -> (! 0) -> 1 (sand)
  // 3. (a < 0) -> (1 < 0) -> 0 (falsk)
  // 4. (0 || 1) -> (falsk ELLER sand) -> 1
  res2 = ((a < (! b)) || (! ! a)); 

  // --- Opgave 3 ---
  // Original: res3 = a + b < ! c + c;
  // Prioritet: ! (Niveau 15) FØR + (Niveau 12) FØR < (Niveau 10)
  // 1. (! c) -> (! 3) -> 0 (falsk)
  // 2. (a + b) -> (1 + 2) -> 3
  // 3. (0 + c) -> (0 + 3) -> 3
  // 4. (3 < 3) -> 0 (falsk, da 3 ikke er mindre end 3)
  res3 = ((a + b) < ((! c) + c));

  // --- Opgave 4 ---
  // Original: res4 = a - x || b * c && b / a;
  // Prioritet: * og / (Niveau 13) FØR - (Niveau 12) FØR && (Niveau 5) FØR || (Niveau 4)
  // 1. C bruger "short-circuit". Den tjekker venstre side af || først:
  //    (a - x) -> (1 - 1.0) -> 0.0 (falsk)
  // 2. Da venstre side var falsk, MÅ den udregne højre side: (b * c && b / a)
  // 3. (b * c) -> (2 * 3) -> 6 (sand)
  // 4. (b / a) -> (2 / 1) -> 2 (sand)
  // 5. (6 && 2) -> (sand OG sand) -> 1 (sand)
  // 6. Hele udtrykket er nu: (0.0 || 1) -> (falsk ELLER sand) -> 1
  res4 = ((a - x) || ((b * c) && (b / a)));

  printf("res1 = %d, res2 = %d, res3 = %d,  res4 = %d \n", 
	 res1, res2, res3, res4);

  return 0;
}