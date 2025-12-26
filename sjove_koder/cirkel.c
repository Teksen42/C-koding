#include <stdio.h>
#define PI 3.14159

double omkreds(double r);
void udskriv_omkreds(double omkr);
double areal(double r);
void udskriv_areal(double arl);

int main(void){

    double radius, omkr, arl; 
    char a_o;


    printf("Vil du helst have areal eller omkreds\n");
    printf("skriv o for omkreds og a for areal\n");
    scanf(" %c", &a_o);

    if (a_o == 'o' || a_o == 'O') {
        printf("Indtast radius for at beregne omkreds\n");
        scanf("%lf", &radius);
        omkr = omkreds(radius);

        udskriv_omkreds(omkr);
    } else if (a_o == 'a' || a_o == 'A') {
        printf("Indtast radius for at beregne areal\n");
        scanf("%lf", &radius);
        arl = areal(radius);

        udskriv_areal(arl);
    } else {
        printf("Du tastede ikke o eller a, prøv igen\n");
    }
    
    
    return 0;
}

double areal(double r){
    double areal = PI*r*r;
    return areal;

}

double omkreds(double r){
        double o = 2 * PI * r;
        return o;
}

void udskriv_omkreds(double omkr){
    printf("Her er omkredsen: %lf.\n", omkr);

}
void udskriv_areal(double arl){
    printf("Her er Arealt: %lf.\n", arl);
}