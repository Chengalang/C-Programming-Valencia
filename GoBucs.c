/*
Assignment 4 Entering Team Scores
Written by : Kenny Cheng
Final Written Date : 1/28/17
Purpose : Create a program that can input data for a sports team
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define pause system("pause");
#define GAME 1000
#define SCORE 2
#define flush fflush(stdin)
#define cls system("cls")

int teamScore();
int oppScore();
void displayMenu();
char getChoice();
bool areYouDone();

main() {

	char choice;
	long finalGameResults[GAME][SCORE], wins = 0, loses = 0, gameSize = 0;
	long winningGames[GAME][SCORE];
	int scoreOne, scoreTwo, gameCont;
	bool done = false;

	do {
		choice = getChoice();
		switch (choice) {
			case 'A':
			case 'a':
				/*
				I will be the first to admit that this is sloppy and not easily
				readable. Will spend more time reducing lines of code.
				*/
				for (int i = 0; i < GAME; i++) {
					for (int j = 0; j < SCORE; j++) {
						if (j == 0) {
							scoreOne = finalGameResults[i][j] = teamScore();
						}
						else {
							scoreTwo = finalGameResults[i][j] = oppScore();
						} // end if
					}
						if (scoreOne > scoreTwo) {
							gameSize++;
							for (int i = 0; i < gameSize; i++) {
								for (int j = 0; j < SCORE; j++) {
									winningGames[i][j] = finalGameResults[i][j];
								}
							}
							printf("\nCongrats on the win. Go Bucs!!!\n\n");
							wins++;
						} else {
							gameSize++;
							printf("\nBetter luck next time. Go Bucs!!!\n\n");
							loses++;
						} // end if statement

					printf("Would you like to enter another game?\n1. Yes\n2. No \n");
					scanf("%d", &gameCont);
					if (gameCont == 2) {
						i = 1000;
					}
				} // end for loop

			done = areYouDone();
			break;

		case 'B':
		case 'b':

			printf("\nThe Tampa Bay Buccaneers have won %d games while losing %d games\n", wins, loses);
			pause;
			break;

		case 'C':
		case 'c':

			printf("\n\t\tThe winning result scores are\n\n");
			printf("\t\tTampa Bay\tOpponent\n");
			for (int i = 0; i < wins; i++) {
				printf("\n");
				for (int j = 0; j < SCORE; j++) {
					printf("\t\t%ld", winningGames[i][j]);
				}
			}
			printf("\n\n");
			pause;
			break;

		case 'D':
		case 'd':
			
			printf("\n\t\tThe scores for all games are\n\n");
			printf("\t\tTampa Bay\tOpponent\n");
			for (int i = 0; i < gameSize; i++) {
				printf("\n");
				for (int j = 0; j < SCORE; j++) {
					printf("\t\t%ld", finalGameResults[i][j]);
				}
			}
			printf("\n\n");
			pause;
			break;

		case 'E':
		case 'e':

			done = true;
			break;

		default :

			printf("Invalid choice");
			break;

		} // end switch
	} while (!done); // end while

	pause;

} // end of main

 int teamScore() {
	
	 int teamScore;
	 printf("How many points did the Bucs score? ");
	 scanf("%d", &teamScore);
	 return teamScore;

} // end teamScore

 int oppScore() {
	 
	 int oppScore;
	 printf("How many points did the opponent score? ");
	 scanf("%d", &oppScore);
	 return oppScore;

 } // end oppScore

 void displayMenu() {

	 cls;
	 printf("\t-------------------------------------------");
	 printf("\t\n\t\t\t Main Menu\n");
	 printf("\t-------------------------------------------\n\n");
	 printf("A) Enter Game Results\n");
	 printf("B) Current Team Record\n");
	 printf("C) Displey ALL results from ALL games WON\n");
	 printf("D) Display ALL results\n");
	 printf("E) Exit \n");
	 return;

} // end displayMenu
 // I like how organized this can make the code from the solution to the car sales you posted.
 // This makes it feel more OOP 
 char getChoice() {
	 
	 char result;
	 displayMenu();
	 scanf("%c", &result);
	 flush;
	 return result;

 } // end getChoice

 bool areYouDone() {

	 int result;
	 printf("\nWould you like to return to the main menu?\n1. Yes\n2. No\n");
	 scanf("%i", &result);
	 if (result == 1) {
		 result = false;
	 } else if (result == 2) {
		 printf("\nThank you for updating the system. \nHave a great day\n\n");
		 result = true;
	 }
	 return result;

 } // end areYouDone