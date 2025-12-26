#include <stdio.h>

#define NAME_LEN 20

struct planet{
    char navn[NAME_LEN + 1];
    double volume;
    double masse;
};

typedef struct planet planet;

void print_massefylde(planet p);
double regn_massefylde(planet p);

int main(void){
    planet Jorden =
    {"Jorden", 1.08321e12, 5.97e24};

    planet Mars =
    {"Mars", 1.63118e11, 6.39e23};

    print_massefylde(Jorden);
    print_massefylde(Mars);

    return 0;
}

double regn_massefylde(planet p){
    double m;
    m = p.masse/p.volume;
    return m;
}

void print_massefylde(planet p){
    char *n = p.navn; //eller char n[NAME_LEN + 1]; og strcpy(n, p.navn);
    double m;
    m = regn_massefylde(p);
    printf("%s har massefylden %.0lf kg/km3\n\n", n, m);
}
