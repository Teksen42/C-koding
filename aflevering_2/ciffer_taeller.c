/* Ciffer-tæller
Målet med denne opgave er at træne dig i programmering med løkker, herunder at vælge gode iterative kontrolstrukturer til opgaven. Som altid er det også målet at lave et velopstillet program med god indrykning, og med brug af gode variabelnavne.

I denne opgave skal du skrive et program, der kan tælle hvor mange tal (fra 1 til n) der indeholder et bestemt ciffer c. For eksempel er der 19 tal fra 1 til 100 der indeholder cifferet 5. (Vi bruger det almindelige 10-talsystem i denne opgave).

Vi starter med en simplere opgave og bygger os frem mod en komplet løsning. Du skal kun aflevere den færdige version (eller så langt du nåede).

Programmet skal indlæse to heltal n og c. Cifferet c skal være et heltal mellem 0 og 9, og n skal være mindst 1. (Du kan printe en fejlbesked, hvis brugeren indtaster et ugyldigt input).

Som en opvarmning til den egentlige opgave, kan du skrive et program, der tjekker om n slutter på cifret c. (Hint: du kan benytte modulo-operatoren til dette.)

Næste skridt er at omskrive programmet, så det kan tjekke om n indeholder cifret c. Hvilken iterativ kontrolstruktur kan du bruge til at opnå dette? Overvej omhyggeligt hvordan løkken starter, og hvordan den slutter. Tag gerne inspiration fra følgende regne-eksempel, hvor jeg har beskrevet processen for et konkret tal og ciffer.

Indeholder 7264 cifret 2?
     Slutter 7264 på 2?
     Nej
     Divider med 10 (heltalsdivision) = 726
Indeholder 726 cifret 2?
     Slutter 726 på 2?
     Nej
     Divider med 10 (heltalsdivision) = 72
Indeholder 72 cifret 2?
     Slutter 72 på 2?
     Ja
     Derfor indeholder 7264 cifret 2.

Som det sidste skridt skal du nu udvide programmet, så det tæller hvor mange af tallene fra 1 til n, der indeholder cifferet c. Hvilken iterativ kontrolstruktur egner sig godt til dette?

Udskriv resultatet med printf: for eksempel hvis input er 100 5, så er output 19.

Tak til Morten Konggaard Schou for denne opgavetekst.*/

#include <stdio.h>

int main (void){
    int n, c;
    int count = 0;
    
    do{
        printf("Indtast c vaerdien, den skal vaere et helt tal mellem 0 og 9 \n");
        scanf("%d", &c);
        if(c < 0 || c > 9){
            printf("Ugyldigt vaerdi indtastet, proiv igen\n");
        }
    }while(c < 0 || c > 9);

    do{
        printf("Indtast n vaerdien, den skal vaere et helt tal, som er mindst 1 \n");
        scanf("%d", &n);
        if(n < 1){
            printf("Ugyldigt vaerdi indtastet, proiv igen\n");
        }
    }while(n < 1);
    // YDRE LØKKE: Gennemgår hvert enkelt tal fra 1 op til n (vores søgefelt)
    for(int i = 1; i <= n; i++) {
        // KOPIERING: Vi gemmer 'i' i 'temp'. 
        // Vi må ikke ændre direkte på 'i', for den styrer hvor langt vi er nået i for-løkken.
        int temp = i;

        // INDRE LØKKE: Undersøger cifrene i det aktuelle tal (temp)
        // Kører så længe der er cifre tilbage (temp er større end 0)
        while(temp > 0){
            // TJEK: Bruger modulo (%) til at se om det SIDSTE ciffer matcher c, da det sidste cifre vil tælle som rest efter %10
            if (temp % 10 == c){
                count++; // Vi fandt et match! Tæl det samlede resultat op.
                break;  // STOP: Vi har fundet cifret i dette tal.
            }
            // SKRÆL: Fjerner det sidste ciffer ved heltalsdivision, så vi kan tjekke det næste.
            // Uden denne linje ville løkken køre uendeligt.
            temp = temp / 10;
        }
    }

    // RESULTAT: Udskriver hvor mange tal vi fandt i alt.
    printf("%d\n", count);    

    return 0;
}