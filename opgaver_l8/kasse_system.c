#include <stdio.h>

int main(void)
{
    double rabater[10];
    double kasse[10];

    for (int i = 0; i < 10; i++) {
        printf("Indtast pris på vare %d: ", i + 1);
        scanf("%lf", &kasse[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("Indtast rabat (0-1) på vare %d: ", i + 1);
        scanf("%lf", &rabater[i]);
    }

    printf("\nPriser uden rabat:\n");
    for (int i = 0; i < 10; i++) {
        printf("Index: %d. Værdi: %.2lf kr\n", i, kasse[i]);
    }

    double samletsum = 0;
    double medrabatpris = 0;
    for (int i = 0; i < 10; i++) {
        samletsum += kasse[i];
        medrabatpris += kasse[i] * (1 - rabater[i]);
    }

    printf("\nDu skal betale: %.2lf kr med rabat\n", medrabatpris);
    printf("Du skal betale: %.2lf kr uden rabat\n", samletsum);

    return 0;
}