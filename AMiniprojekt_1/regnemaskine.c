/* Miniprojekt 1: En regnemaskine på kommandolinjen
Skriv et program der modellerer en simpel regnemaskine. Regnemaskinen holder styr på ét enkelt tal af typen double, som indholder det hidtidigt beregnede resultat. Dette tal kaldes akkumulatoren. Akkumulatores startværdi er 0.0. I en simpel, iterativ dialog med brugeren udføres der forskellige beregninger på akkumulatoren. Disse beregninger kan være styret af unære eller binære operatorer, som i denne opgave alle noteres med netop ét tegn.

Unære operationer (som står foran sin operand, og derfor er prefix) udfører en beregning på akkmulatoren:

      operator akkumulator
Binære operationer udfører en beregning på akkulatoren og en ekstra operand på følgende måde:

      akkumulator operator højre_operand
I begge tilfælde lægges værdien af udtrykket tilbage i akkumulatoren.

Det anbefales at operationen, som regnemaskinen skal udføre, indlæses som en char med scanf. Binære operatorer kræver en (højre-) operand, der indlæses som en double af scanf.

Du skal have en funktion, scan_data, med to output parametre, som returnerer en operator og en mulig højre operand fra en datalinje. Hvis der anvendes en unær operator returneres operanden blot som 0.0.

Du skal også have en funktion, do_next_op, som udfører den påkrævede operation: do_next_op skal have to input parametre (operator og operand) foruden akkumulatoren, som både skal kunne bruges til input og output (og som derfor skal være en pointer). Operanden ignoreres for unære operatorer.

Regnemaskinens samlede dialog skal indkapsles i en funktion, run_calculator, som skal returnere slutværdien af akkumulatoren.

Overvej også at skrive en boolsk funktion, der kan afgøre om en operator (af typen char) er binær.

Her er de gyldige binære operatorer i regnemaskinen:

  +    for addition af akkumulatoren med operanden
  -    for subtraktion af akkumulatoren med operanden
  *    for multiplikation af akkumulatoren med operanden
  /    for division af akkumulatoren med operanden
  ^    for potensopløftning af akkumulatoren med operanden
Og her er de gyldige unære operatorer:

  #    for kvadratroden af akkumulatoren
  %    for at vende fortegnet af akkumulatoren
  !    for at dividere 1 med akkumulatoren
  q    for at afslutte regnemaskinen med slutresultatet
Din regnemaskine skal nægte at tage kvadratroden af et negativt tal, og den skal nægte at dividere med nul. I tilfælde af en sådan ulovlig operation, skal akkumulatoren blot efterlades uændret. Der skal ikke udskrives fejlmeddelelser.

Din regnemaskine skal vise den akkumulerede værdi efter hver operation.

Her er et eksempel på en dialog med regnemaskinen - som dialogen kan se ud når du får skrevet dit program:

Enter operator: +
Enter operand: 5.000000
Result so far is 5.000000.
Enter operator: - 
Enter operand: 6.000000
Result so far is -1.000000.
Enter operator: *
Enter operand: 3.000000
Result so far is -3.000000.
Enter operator: #
Result so far is -3.000000.
Enter operator: %
Result so far is 3.000000.
Enter operator: #
Result so far is 1.732051.
Enter operator: ^
Enter operand: 2.000000
Result so far is 3.000000.
Enter operator: * 
Enter operand: 4.000000
Result so far is 12.000000.
Enter operator: !
Result so far is 0.083333.
Enter operator: q
Final result is: 0.083333
Denne opgave er inspireret af en tilsvarende opgave fra 6. og 7. udgave af lærebogen, som anvendes på kurset.

Som altid skal du lave top-down programmering med trinvis forfinelse. Overvej omhyggeligt de anvendte kontrolstrukturer. Overvej også god brug af operatorerne i C, til at udføre regnemaskinens operationer. Og sidst men ikke mindst, brug gode input- og output parametre i dine funktioner. */

#include <stdio.h>
#include <math.h>

double run_calculator(void);
void do_next_op(char operator, double operand, double *akkumulator);
int er_binaer(char tegn);
void scan_data(char *p_tegn, double *p_tal);

int main(void) {
    // Start maskinen og gem slutresultatet i en variabel
    double slut_resultat = run_calculator();

    // Print det endelige resultat
    printf("Final result is: %lf\n", slut_resultat);

    return 0;
}


double run_calculator() {
    double akkumulator = 0.0; // Her fødes akkumulatoren
    char operator = ' ';      // Startværdi for tegn (ligegyldig) /||| " (= ' ') " er har bare for udseenden det er ikke strengt nødvendigt
    double operand = 0.0;     // Startværdi for tal, det tal vi inputter ind i maskinen bliver gemt i operand.
    
    // 1. Print menuen
    printf("Velkommen til regnemaskinen!\n");
    printf("----------------------------\n");

    // 2. Start løkken
    // Vi kører "for evigt" indtil vi breaker manuelt
    while (1) {
        
        // Hent input fra brugeren
        scan_data(&operator, &operand);

        // Tjek om vi skal stoppe FØR vi regner
        if (operator == 'q') {
            break; // Hop ud af while-løkken med det samme
        }

        // Udfør regnestykket
        do_next_op(operator, operand, &akkumulator);

        // Print resultatet så langt
        printf("Result so far is %lf.\n", akkumulator);
    }

    // Når løkken er færdig (break), returnerer vi tallet til main
    return akkumulator;
}


void do_next_op(char operator, double operand, double *akkumulator) {
    switch (operator) {
        // Binære
        case '+': *akkumulator = *akkumulator + operand; break;
        case '-': *akkumulator = *akkumulator - operand; break;
        case '*': *akkumulator = *akkumulator * operand; break;
        case '/': 
            if (operand != 0.0) *akkumulator = *akkumulator / operand; 
            break;
        case '^': *akkumulator = pow(*akkumulator, operand); break;
            
        // Unære (bruger kun akkumulator)
        case '#': if (*akkumulator >= 0) *akkumulator = sqrt(*akkumulator); break;
        case '%': *akkumulator = -(*akkumulator); break;
        case '!': if (*akkumulator != 0) *akkumulator = 1.0 / *akkumulator; break;
        
        case 'q': break; // Gør intet, loopen i run_calculator stopper
        default: break;
    }
}


int er_binaer(char tegn) {
    if(tegn == '+' || tegn == '-' || tegn == '*' || tegn == '/' || tegn == '^'){
        return 1;
    }else{
        return 0;
    }

}

void scan_data(char *p_tegn, double *p_tal){
    printf("Mulige tegn: + - * / ^ # %% ! q\n");
    printf("----------------------------\n");
    printf("Indsaet tegnet: ");
    scanf(" %c", p_tegn);

    // Nu tjekker vi tegnet.
    // Vi sætter * foran p_tegn, fordi vi vil se på VÆRDIEN på adressen (fx. tegnet '+'), ikke selve adressen.
    if (er_binaer(*p_tegn) == 1) {
        
        // Hvis den er binær (+, -, *), skal vi bruge et tal mere
        printf("Indsaet tallet: ");
        // Vi scanner en double (%lf) ind på adressen p_tal
        scanf("%lf", p_tal);
        
    } else {
        
        // Hvis den er unær (#, !) eller quit (q), skal vi IKKE bruge et tal.
        // Vi skriver 0.0 manuelt ind på adressen.
        *p_tal = 0.0;
    }
}