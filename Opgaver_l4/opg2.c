//There are 9,870 people in a town whose population increases by 10% each
//year. Write a loop that displays the annual population and determines how
//many years (count_years) it will take for the population to surpass 30,000.
#include <stdio.h>
 
int main(void){
    double people = 9870;
    int count_years = 0;
 
    while (people < 30000){
    people = people*1.1; //vokse med 10 procent er det samme som 1.1
    count_years++;
    printf("AAr %d: befolkning er nu %.0f\n", count_years, people);
}
    printf ("Der gaar %d aar indtil populationen er over 30000 \n", count_years);
 
    return(0);
}