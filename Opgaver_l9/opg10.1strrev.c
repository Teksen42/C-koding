/*Strengomvending består i at bytte om på tegnene i en tekststreng, således at de første tegn ender med at være de sidste. Eksempelvis er strengomvendingen af "streng" lig med "gnerts".

Programmer funktionen strrev(char *str), som omvender tegnene i parameteren str. Bemærk at parameteren str både tjener som input og output parameter. Vi ønsker altså at bytte om på tegnene i det char array, som str peger på.*/
#include <stdio.h>
#include <string.h>

char *strrev(char *str);

int main(void) {
  //"abcd" + \0 (5 bytes i alt)
  char str[] = "abcd";
  printf("%s\n", strrev(str)); //abcd bliver til dcba


  strcpy(str, "abc"); //ændre arrayet str fra starten til abc, vedhælp af strcpu
  printf("%s\n", strrev(str));  //Vender abc til cba

  strcpy(str, "ab"); //ændre str til ab
  printf("%s\n", strrev(str)); //vender ab til ba

  strcpy(str, "a"); ////ændre str til a
  printf("%s\n", strrev(str));//Vender a til a, løkken står tomt dernede

  strcpy(str, "");//ændre str til \0
  printf("%s\n", strrev(str)); //står som den er da der er intet end \0
  
  return 0;
}

char *strrev(char *str){
  int i = 0,                //i=0 peger på første bogstav i arrayet
      j = strlen(str) - 1;  //Dette peget på det sidste bogstav før \0, det er -1 som gøre så den ikke peger på 0 operatoren
  char temp;                // Midlertidig variabel til at gemme et tegn under byttet


  //Den skal kører så længe første nummer i arrayet er mindre end sidste nummer i arrayet.
  while (i < j){
   
    // bytter om på tegn nummer i og j 
    temp = str[j];    //Gemmer tegnet fra højre side "j" i temp
    str[j] = str[i];  //Flyt tegnet fra venstre side over til højre. Overskriver det sidste
    str[i] = temp;    //Læg det gemte tegn (fra højre) ind på venstre plads. Overskriver det første
    
    //Vi er i midten
    i++; //ryk mod højre
    j--; //ryk mod venstre
    //Vi finder to nye værdier og kører lykken igen, indtil i og j mødes i midten, fx array nummer 3
  }

  return str; 
}