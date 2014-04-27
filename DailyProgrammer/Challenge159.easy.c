//Rock Paper Scissors Lizard Spock
//Part 1
//Get input from the player as being one of the five choices
//Get the computer to randomly choose a move

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int getRandomComputer(void);
int getPlayerChoice(void);
int getWinner(int computerC, int playerC); //R = 1, P = 2, S = 3, L = 4, Spock = 5
void printStats(int playerWins, int computerWins, int ties);

int main(void)
{

  srand(time(0));
  int computerWins = 0, playerWins = 0, ties = 0;
  int playerChoice, computerChoice; //R = 1, P = 2, S = 3, L = 4, Spock = 5
  int winner;
  
  int numberOfGames =-1;
  int control;
  do
  {
    printf("Please enter the number (greater than zero) of games you wish to play: ");
    scanf("%d", &numberOfGames);
    getchar();
  }
  while(numberOfGames <= 0);

  for (control = 0 ; control < numberOfGames ; control++)
  {
    playerChoice = getPlayerChoice();
    computerChoice = getRandomComputer();
    winner = getWinner(computerChoice, playerChoice);

    if(winner == 0)
      computerWins++;
    else if (winner == 1)
      playerWins++;
    else if (winner == -1)
      ties++;
    
  }

  printStats(playerWins, computerWins, ties);

  return 0;
}


int getRandomComputer(void)
{
  int output;
  output = rand()%5;
  output++;
  return output;
}

int getPlayerChoice(void)
{
  char choice[10];
  while(1)
  {
    printf("Please enter your choice for this round.\n");
    printf("The choices are Rock, Paper, Scissors, Lizard and Spock");
    printf("\nChoice:\t");

    fgets(choice, 10, stdin);

  //  printf("%s", choice);

    if (!(strcmp(choice, "Rock\n")))
      return 1;
    else if (!strcmp(choice, "Paper\n"))
      return 2;
    else if (!strcmp(choice, "Scissors\n"))
      return 3;
    else if (!strcmp(choice, "Lizard\n"))
      return 4;
    else if (!strcmp(choice,  "Spock\n"))
      return 5;
    else
      printf("Please enter a valid choice. Note that capitalization maters.");
  }
}

int getWinner(int computerC, int playerC) //R = 1, P = 2, S = 3, L = 4, Spock = 5
{

  //printf("The player chose %d\n", playerC);
 // printf("The computer chose %d\n", computerC);

  if (computerC == playerC)
  {
    printf("This was a tie.\n");
    return -1; //tie
  }
  
  if ((computerC == 1) && (playerC == 3))
  {
    printf("Rock crushes scissors.\n");
    return 0;
  }

  if ((computerC == 1) && (playerC == 4))
  {
    printf("Rock crushes Lizard.\n");
    return 0;
  }

  if ((computerC == 2) && (playerC == 1))
  {
    printf("Paper covers Rock.\n");
    return 0;
  }

  if ((computerC == 2) && (playerC == 5))
  {
    printf("Paper disproves Spock.\n");
    return 0;
  }

  if ((computerC == 3) && (playerC == 2))
  {
    printf("Scissors cuts Paper.\n");
    return 0;
  }

  if ((computerC == 3) && (playerC == 4))
  {
    printf("Scissors decapitates Lizard.\n");
    return 0;
  }

  if ((computerC == 4) && (playerC == 2))
  {
    printf("Lizard eats Paper.\n");
    return 0;
  }

  if ((computerC == 4) && (playerC == 5))
  {
    printf("Lizard poisons Spock.\n");
    return 0;
  }

  if ((computerC == 5) && (playerC == 1))
  {
    printf("Spock vaporizes Rock.\n");
    return 0;
  }

  if ((computerC == 5) && (playerC == 3))
  {
    printf("Spock smashes Scissors.\n");
    return 0;
  }

  if ((computerC == 3) && (playerC == 1))
  {
    printf("Rock crushes scissors.\n");
    return 1;
  }

  if ((computerC == 4) && (playerC == 1))
  {
    printf("Rock crushes Lizard.\n");
    return 1;
  }

  if ((computerC == 1) && (playerC == 2))
  {
    printf("Paper covers Rock.\n");
    return 1;
  }

  if ((computerC == 5) && (playerC == 2))
  {
    printf("Paper disproves Spock.\n");
    return 1;
  }

  if ((computerC == 2) && (playerC == 3))
  {
    printf("Scissors cuts Paper.\n");
    return 1;
  }

  if ((computerC == 4) && (playerC == 3))
  {
    printf("Scissors decapitates Lizard.\n");
    return 1;
  }

  if ((computerC == 2) && (playerC == 4))
  {
    printf("Lizard eats Paper.\n");
    return 1;
  }

  if ((computerC == 5) && (playerC == 4))
  {
    printf("Lizard poisons Spock.\n");
    return 1;
  }

  if ((computerC == 1) && (playerC == 5))
  {
    printf("Spock vaporizes Rock.\n");
    return 1;
  }

  if ((computerC == 3) && (playerC == 5))
  {
    printf("Spock smashes Scissors.\n");
    return 1;
  }
}

void printStats(int playerWins, int computerWins, int ties)
{
  printf("Stats for %d games.\n", (playerWins + computerWins + ties));
  printf("The human player won %d times.\n", playerWins);
  printf("The computer player won %d times.\n", computerWins);
  printf("There were %d ties.\n", ties);
}
