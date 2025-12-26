#include <stdio.h>

void add_vektor(int u1, int u2, int v1, int v2, int *w1, int *w2);

int main(void){
    int u1, u2, v1, v2, w1, w2;

    printf("Indtast forste værdi for vektor u:\n");
    scanf("%d", &u1);
    printf("Indtast andet værdi for vektor u:\n");
    scanf("%d", &u2);
    printf("Indtast forste værdi for vektor v:\n");
    scanf("%d", &v1);
    printf("Indtast andet værdi for vektor v:\n");
    scanf("%d", &v2);

    add_vektor(u1,u2,
               v1,v2,
               &w1,&w2);

    printf("Den nye har så værdierne <%d,%d> efter addition", w1,w2);

    return 0;
}


void add_vektor(int u1, int u2, int v1, int v2, int *w1, int *w2) {
    *w1 = u1 + v1;
    *w2 = u2 + v2;
}
