//1. Write a program segment that computes 1 + 2 + 3 + ... + (n - 1) + n, where n is a data value. 
//Follow the loop body with an if statement that compares this value to (n * (n + 1)) / 2 and 
//displays a message that indicates whether the values are the same or different. What message 
//do you think will be displayed?

#include <stdio.h>

int main (void){
    int n = 10, total = 0, i;
    int formel_total = (n * (n + 1)) / 2;
    for(i = 1; i <= n; i++) 
    {
        total = total + i;
    }    
    if(total == formel_total)
    {
        printf("Formlen er korrekt");
    }
    else{
        printf("Formlen passer ikke");
    }
    return 0;
}