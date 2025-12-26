#include <stdio.h>
#include <stdbool.h>

int main(void){
  //// Program gets two hands from inputs from the players ////
  char choice1;
  char choice2;

  printf("Player 1, please input your choice (r/p/s):\n");
  scanf(" %c", &choice1);
  printf("Player 2, please input your choice (r/p/s):\n");
  scanf(" %c", &choice2);

  printf("Rock, Paper, Scissors, SHOOT!\n%c vs %c\n", choice1, choice2);

  //// Program finds out which player wins or if its a tie ////
  bool player1Won = false;
  bool player2Won = false;
  bool playersTie = false;

   switch (choice1) {
    case 'r': switch (choice2) {
      case 'r': playersTie = true; break;
      case 'p': player2Won = true; break;
      case 's': player1Won = true; break;
    }
    case 'p': switch (choice2) {
      case 'r': player1Won = true; break;
      case 'p': playersTie = true; break;
      case 's': player2Won = true; break;
    }
    case 's': switch (choice2) {
      case 'r': player2Won = true; break;
      case 'p': player1Won = true; break;
      case 's': playersTie = true; break;
    }
  } 

  //// Program prints the winner to the terminal, and prints an error if given a faulty input ////
  if (player1Won) {
    printf("Player 1 WINS");
  } else if (player2Won) {
    printf("Player 2 WINS");
  } else if (playersTie) {
    printf("Players TIE!");
  } else {
    printf("Error: Wrong input");
  }

  return 0;
}
