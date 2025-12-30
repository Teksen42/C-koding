/* Vi har på et tidligt tidspunkt i kurset skrevet et program, som omregner et antal sekunder til timer, 
minutter og sekunder efter de sædvanlige principper.

Skriv nu en funktion, hours_minutes_seconds, som tager antal af sekunder som en input parameter, 
og som returnerer de tre outputs (timer, minutter og sekunder) som output parametre (pointere, call-by-reference).*/

#include <stdio.h>

#define SEKUNDER_PR_MINUT 60
#define MINUTTER_PR_TIME  60

// Dette fortæller compileren: "Der findes en funktion med dette navn og disse typer, som kommer længere nede".
// Dette gør, at main() kender funktionen, selvom selve koden til den står i bunden.
void hours_minutes_seconds(int total_sekunder, int *timer, int *minutter, int *sekunder);


int main(void) {
    // Input variabel
    int total;
    // Output variabler (vores "beholdere" til resultatet)
    // De starter uden værdi, men vi sender deres adresser ned til funktionen, så den kan fylde dem op.
    int t, m, s;

    // 1. Bed brugeren om input
    printf("Indtast antal sekunder: ");
    
    // 2. Læs tallet fra tastaturet
    // VIGTIGT: Vi bruger '&' foran total, fordi scanf skal bruge ADRESSEN i hukommelsen
    // for at kunne lægge det indtastede tal ned i variablen.
    scanf("%d", &total);

    // 3. Kald funktionen (Call by Value & Call by Reference)
    // - 'total' sendes som værdi (Kopi). Funktionen kan ikke ændre 'total' her i main.
    // - '&t', '&m', '&s' sendes som adresser (Pointere). Funktionen får "nøglen" til disse variabler,
    //   så den kan gå direkte ind i main's hukommelse og ændre værdien af t, m og s.
    hours_minutes_seconds(total, &t, &m, &s);

    // 4. Print resultatet
    // Nu har funktionen kørt, og den har lagt resultaterne i t, m og s via pointerne.
    printf("%d sekunder svarer til: %d timer, %d minutter og %d sekunder\n", total, t, m, s);

    return 0;
}

// -----------------------------------------------------------------------------
// FUNKTIONSDEFINITION
// -----------------------------------------------------------------------------
// Input:  total_sekunder (int) -> Modtager en KOPI af værdien fra main (Call by Value).
// Output: *timer, *minutter, *sekunder -> Modtager ADRESSERNE fra main (Call by Reference).
//         Stjernen (*) i parameterlisten betyder: "Dette er en pointer (en adresse)".
void hours_minutes_seconds(int total_sekunder, int *timer, int *minutter, int *sekunder) {
    // TRIN 1: Find de overskydende sekunder
    // Vi bruger * foran 'sekunder' for at dereferere pointeren.
    // Det betyder: "Gå hen på adressen, som pointeren peger på (s i main), og gem resultatet der".
    // Modulo (%) giver resten ved division. Fx 3725 % 60 = 5.
    *sekunder = total_sekunder % SEKUNDER_PR_MINUT;

    // TRIN 2: Reducer totalen til minutter
    // Her ændrer vi kun på den lokale kopi 'total_sekunder'. Det påvirker IKKE 'total' oppe i main.
    // Heltalsdivision smider decimalerne væk. Fx 3725 / 60 = 62.
    total_sekunder = total_sekunder / SEKUNDER_PR_MINUT;
    
    // TRIN 3: Find de overskydende minutter
    // Igen bruger vi * for at skrive værdien direkte ned i variablen 'm' oppe i main.
    // Fx 62 % 60 = 2.
    *minutter = total_sekunder % MINUTTER_PR_TIME;
    
    // TRIN 4: Find timer
    // Resten af minutterne divideres med 60 for at finde timer.
    // Vi skriver resultatet til adressen for 't' i main.
    // Fx 62 / 60 = 1.
    *timer = total_sekunder / MINUTTER_PR_TIME;
}