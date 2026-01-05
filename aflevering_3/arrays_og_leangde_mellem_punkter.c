/*Mange linjestykker
Denne opgave består af tre steps. I de første to skal "bare" udskrives nogle arrays. I det tredje step skal du regne længden af en række linjestykker.
Forklaringen er relativt lang, men dette er mest for at give nogle gode eksempler der kan hjælpe dig på vej.

Step 0 – print_number
Lav en funktion print_numbers med returtype void som har følgende parametre:
* Et array af doubles xs.
* En integer length.

Vi vil antage at length er længden af arrayet xs. Funktionen print_numbers skal printe de doubles som er i arrayet xs. Ét tal per linje. Hvis xs f.eks. er {0,7,3,8,1}, så skal der printes:

0.000000
7.000000
3.000000
8.000000
1.000000

Prøv print_numbers af med følgende main-funktion:

int main(void){
    double xs[] = {0,7,3,8,1};
    double ys[] = {4,0,3,3,5};
    int length = 5;
    printf("xs:\n");
    print_numbers(xs, length);
    printf("\nys:\n");
    print_numbers(ys, length);
    return 0;
}

Du skulle gerne få følgende output:

xs:
0.000000
7.000000
3.000000
8.000000
1.000000

ys:
4.000000
0.000000
3.000000
3.000000
5.000000


Step 1 – print_points
Lav en funktion print_points med returtype void som har følgende parametre:
* Et array af doubles xs.
* Endnu et array af doubles ys.
* En integer length.

Vi vil tænke på xs som et array af x-koordinater og ys som et array af y-koordinater, hvor de to arrays har samme længde, nemlig length.
Idéen er at de to arrays tilsammen repræsenterer en række punkter, nemlig punkterne:

(xs[0], ys[0]),
(xs[1], ys[1]),
(xs[2], ys[2]),
...
(xs[length-1], ys[length-1]).

Det er altså xs der indeholder x-koordinaterne og ys der indeholder y-koordinaterne.

Funktionen print_points skal udskrive punkterne i rækkefølgen vist ovenfor.
Hvis f.eks. xs er arrayet {0,7,3,8,1}, ys er arrayet {4,0,3,3,5} og length er 5 så skal der printes

(0.000000, 4.000000)
(7.000000, 0.000000)
(3.000000, 3.000000)
(8.000000, 3.000000)
(1.000000, 5.000000)

Prøv din funktion af ved hjælp af følgende udvidelse af main-funktionen fra før:

int main(void){
    double xs[] = {0,7,3,8,1};
    double ys[] = {4,0,3,3,5};
    int length = 5;
    printf("xs:\n");
    print_numbers(xs, length);
    printf("\nys:\n");
    print_numbers(ys, length);
    printf("\nPoints:\n");
    print_points(xs, ys, length);
    return 0;
}

Du skulle gerne få følgende output:

xs:
0.000000
7.000000
3.000000
8.000000
1.000000

ys:
4.000000
0.000000
3.000000
3.000000
5.000000

Points:
(0.000000, 4.000000)
(7.000000, 0.000000)
(3.000000, 3.000000)
(8.000000, 3.000000)
(1.000000, 5.000000)


Step 2 – Distancer
Vi kan tænke på rækken af punkter som en figur i et koordinatsystem bestående af linjestykker. Dvs. et linjestykke fra (xs[0], ys[0]) til (xs[1], ys[1]) efterfulgt af et linjestykke fra (xs[1], ys[1]) til (xs[2], ys[2]) efterfulgt af et linjestykke fra (xs[2], ys[2]) til (xs[3], ys[3]) osv. Det sidste linjestykke er fra (xs[length-2], ys[length-2]) til (xs[length-1], ys[length-1]).

I ovenstående eksempel svarer dette til et linjestykke fra (0,4) til (7,0) efterfulgt af et linjestykke fra (7,0) til (3,3) efterfulgt af et linjestykke fra (3,3) til (8,3) efterfulgt af et linjestykke fra (8,3) til (1,5).



Vi vil gerne have udregnet længderne af hver af sådanne linjestykker og gemt dem alle i et array. Vi ønsker at lave en funktion der gør dette. Funktionen skal hedde dists med returtype void og følgende parametre:
* Et array af doubles xs.
* Endnu et array af doubles ys.
* En integer length.
* Endnu et array af doubles ds.

Idéen er at xs igen indeholder x-koordinater, ys igen indeholder y-koordinater og length igen er længden af disse to arrays. Parametret ds er et array som funktionen dists skal sørge for indeholder de nævnte længder af linjestykkerne. Det skal gøres i en løkke efter følgende princip:

Plads 0 i ds skal assignes til afstanden fra (xs[0],ys[0]) til (xs[1],ys[1]).
Plads 1 i ds skal assignes til afstanden fra (xs[1],ys[1]) til (xs[2],ys[2]).
Plads 2 i ds skal assignes til afstanden fra (xs[2],ys[2]) til (xs[3],ys[3]).
...
Plads length - 2 i ds skal assignes til afstanden fra (xs[length - 2],ys[length - 2]) til (xs[length - 1],ys[length - 1]).

Prøv din funktion af ved hjælp af følgende udvidelse af main-funktionen fra før:

int main(void){
    double xs[] = {0,7,3,8,1};
    double ys[] = {4,0,3,3,5};
    int length = 5;
    printf("xs:\n");
    print_numbers(xs, length);
    printf("\nys:\n");
    print_numbers(ys, length);
    printf("\nPoints:\n");
    print_points(xs, ys, length);
    double ds[length-1];
    dists(xs,ys,length,ds);
    printf("\nDists:\n");
    print_numbers(ds,length-1);
    return 0;
}

I dit afleverede program skal du bruge denne main-funktion. Det forventede output er:

xs:
0.000000
7.000000
3.000000
8.000000
1.000000

ys:
4.000000
0.000000
3.000000
3.000000
5.000000

Points:
(0.000000, 4.000000)
(7.000000, 0.000000)
(3.000000, 3.000000)
(8.000000, 3.000000)
(1.000000, 5.000000)

Dists:
8.062258
5.000000
5.000000
7.280110

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void print_numbers(double xs[], int length){
    for(int i = 0; i < length; i++){
        printf("%lf \n", xs[i]);
    }
}

void print_points(double xs[], double ys[], int length){
    for(int i = 0; i < length; i++){
        printf("(%lf, %lf) \n", xs[i], ys[i]);
    }
}

void dists(double xs[], double ys[], int length, double ds[]){
    for(int i = 0; i < length - 1; i++){
        double dx = xs[i+1] - xs[i];
        double dy = ys[i+1] - ys[i];
        ds[i] = sqrt(pow(dx, 2) + pow(dy, 2));
    }
}

int main(void){
    double xs[] = {0,7,3,8,1};
    double ys[] = {4,0,3,3,5};
    int length = 5;
    printf("xs:\n");
    print_numbers(xs, length);
    printf("\nys:\n");
    print_numbers(ys, length);
    printf("\nPoints:\n");
    print_points(xs, ys, length);
    double ds[length-1];
    dists(xs,ys,length,ds);
    printf("\nDists:\n");
    print_numbers(ds,length-1);
    return 0;
}