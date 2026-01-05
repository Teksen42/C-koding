/* Compute the sizes of some fundamental types. */

#include <stdio.h>

int main(void)
{
    printf("\n");
    printf("Here are the sizes of some integral types:\n\n");

    printf("        int:%3u bytes\n", (unsigned)sizeof(int));
    printf("   unsigned:%3u bytes\n", (unsigned)sizeof(unsigned));
    printf("       long:%3u bytes\n", (unsigned)sizeof(long));
    printf("unsigned long:%3u bytes\n", (unsigned)sizeof(unsigned long));
    printf("      short:%3u bytes\n", (unsigned)sizeof(short));
    printf("unsigned short:%3u bytes\n", (unsigned)sizeof(unsigned short));
    printf("       char:%3u byte \n", (unsigned)sizeof(char));

    printf("\n");
    return 0;
}