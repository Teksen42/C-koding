#include <stdio.h>

#define NAME_LEN 20

struct planet{
    char navn[NAME_LEN + 1];
    double radius;
    double volumen;
    double masse;
};

int main (void) {
    struct planet p;

    printf("Indtast planetens navn\n");
    scanf("%20s", &p.navn);

    printf("Indtast planetens radius\n");
    scanf("%lf", &p.radius);

    printf("Indtast planetens masse \n");
    scanf("%lf", &p.masse),

    p.volumen = (4.0 / 3.0) * 3.14159 * p.radius * p.radius * p.radius;

    printf("Navn: %s\n", p.navn);
    printf("Volumen: %.2f\n", p.volumen);

    return(0);
}


