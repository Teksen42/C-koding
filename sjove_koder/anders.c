#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char *udskift(char word[]);
 
int main(void){
    char word[] = "Anders";
    char *str2;
 
    printf("Nu skifter vi o ud med e:\n");
    str2 = udskift(word);
 
    printf("Her er den gamle streng: %s\n", word);
    printf("Her er den nye streng: %s\n", str2);
 
    //husk at frigive det bruge plads
    free(str2);
    return 0;
}
 
 //retunerer en pointer til den forreste character i stengen
char *udskift(char word[]){  
 
    //allokerer dymamisk et array der skal indeholde den nye str. (char*) er typekast, +1 for '\0'
    char *str_ny = (char*) malloc((strlen(word) + 2) * sizeof(char));  
    if(str_ny == NULL){
        printf("Allokering lykkedes ikke\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while(word[i] != '\0'){
       
        str_ny[i] = word[i];
        i++;
    }
    str_ny[i] = '!';
    str_ny[i+1] = '\0';
    return str_ny;
}