//////////////////////////////////////////////////////////////////////////
//	Made by: Michael Braddy, Norman Matias, Kenny Cheng		//
//	Made on: Week of 2/4/17						//
//	Made for: Morses and the Horses Assignment / C Programming	//
//////////////////////////////////////////////////////////////////////////

#define CLS system("cls")
#define FLUSH fflush(stdin)
#define PAUSE system("pause")

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dos.h>

//	Prototype Functions Here
int awayTheyGo(int x);
void bankMenu(double morseMoney[]);
double betHorse(int pick, double betAmount);
double bettingWindow(double morseMoney[]);
void currentMoney(double morseMoney[]);
void delay(unsigned int mseconds);
void horsesWon(int winners[], int numOfWinners);
void mainMenu();
void raceTime(double morseMoney[], int winningHorses[], int raceCounter, int pick, double betAmount);
void raceUpdate(int advancementValue, char theRace[][26], int horseRunningNumbers[], int whosTheWinner);
int winnerCheck(char theRace[][26]);
char winnersLetter(int whosTheWinner);
//	End Prototype Functions

void main() {
	srand(time(NULL));
	mainMenu();
}

int awayTheyGo(int x) {	//	Function that actually determines the winner of the Race

	if (x >= 1 && x <= 30) {	//	30% Horse 1
		return 1;
	}
	else if (x >= 31 && x <= 40) {	//	10% Horse 2
		return 2;
	}
	else if (x >= 41 && x <= 48) {	//	8% Horse 3
		return 3;
	}
	else if (x >= 49 && x <= 54) {	//	6% Horse 4
		return 4;
	}
	else if (x >= 55 && x <= 56) {	//	2% Horse 5
		return 5;
	}
	else if (x >= 57 && x <= 60) {	//	4% Horse 6
		return 6;
	}
	else if (x >= 61 && x <= 68) {	//	8% Horse 7
		return 7;
	}
	else if (x >= 69 && x <= 78) {	//	10% Horse 8
		return 8;
	}
	else if (x >= 79 && x <= 100) {	//	22% Horse 9
		return 9;
	}

}

void bankMenu(double morseMoney[]) {	//	Function for visits to the bank

	int bSelection = 0;
	double moneyAmount = 0;

	do {	// Begin Menu Loop

		CLS;

		currentMoney(morseMoney);	//	Wallet and Bank Balance Banner

		printf("What would you like to do? \n");
		printf("\n 1. Make a withdrawal");
		printf("\n 2. Make a Deposit");
		printf("\n 3. Balance Inquiry");
		printf("\n 4. Cancel");

		printf("\n Enter Selection: ");
		scanf_s("%i", &bSelection); FLUSH;

		switch (bSelection) { // Begin switch

		case 1:
			printf("How much would you like to withdraw?\nAmount: ");
			scanf_s("%lf", &moneyAmount);

			if (morseMoney[1] < moneyAmount) {	//	Insufficient Funds
				printf("You don't have enough money!\n");
				PAUSE;
			}
			else {
				morseMoney[1] -= moneyAmount;	//	Transfer From Bank to Wallet
				morseMoney[0] += moneyAmount;
			}

			break;

		case 2:
			printf("How much would you like to deposit?\nAmount: ");
			scanf_s("%lf", &moneyAmount);

			if (morseMoney[0] < moneyAmount) {	//	Insufficient Funds
				printf("You don't have enough money!\n");
				PAUSE;
			}
			else {
				morseMoney[0] -= moneyAmount;	//	Transfer From Wallet to Bank
				morseMoney[1] += moneyAmount;
			}

			break;

		case 3:
			printf("Look at the top of the screen, Dummy.\n\n");	//	Balance inquiry not needed since we're in the digital age and you have phone notifications. Duh.
			break;

		case 4:
			printf("\nReturning to the main menu.\n");
			break;

		default:	//	Error Checking
			printf("Please enter a valid option \n");
			PAUSE;
			break;
		} // End switch

	} while (bSelection != 4);

}

double betHorse(int pick, double betAmount) {	//	Function that determines the individual payouts of the horses if they are to win.

	switch (pick) {
	case 1:
		betAmount *= 2;
		break;
	case 2:
		betAmount *= 5;
		break;
	case 3:
		betAmount *= 10;
		break;
	case 4:
		betAmount *= 15;
		break;
	case 5:
		betAmount *= 50;
		break;
	case 6:
		betAmount *= 20;
		break;
	case 7:
		betAmount *= 10;
		break;
	case 8:
		betAmount *= 5;
		break;
	case 9:
		betAmount *= 3;
		break;
	default:
		break;
	}

	return betAmount;	//	returns the total winnings
}

double bettingWindow(double morseMoney[]) {	//	Function that allows the bets to be placed on the horses and informs of their odds
	double betAmount = 0;
	printf("Welcome to the track window.\n");
	printf("Pick the winning horse : \n1. American Pharaoh (2 - 1 Odds)\n2. Seabiscuit (5 - 1 Odds)\n3. Black Stalion (10 - 1 Odds)\n4. Dirty Hilary (15 - 1 Odds)\n");
	printf("5. Hundchuck (50 - 1 Odds)\n6. Trigger (20 - 1 Odds)\n7. Epona (10 - 1 Odds)\n8. Roach (5 - 1 Odds)\n9. Buckwheat Grotes (3 - 1 Odds)\n\n\n");
	printf("How much would you like to bet: ");
	scanf_s("%lf", &betAmount);

	if (morseMoney[0] < betAmount) {	//	Error Check for Insufficient funds
		printf("Sorry, you don't have enough money in your wallet.\n");
		return 0;
	}
	else {
		morseMoney[0] -= betAmount;	//	If the bet goes through, deduction from wallet
	}
	return betAmount;	//	returns bet amount to be manipulated in other functions
}

void currentMoney(double morseMoney[]) {	//	Banner across top to show current money

	printf("---------------------------------------------------------------------\n\n");
	printf("\tMoney In Wallet: %.2lf\tMoney In Bank: %.2lf", morseMoney[0], morseMoney[1]);
	printf("\n\n---------------------------------------------------------------------\n\n");

}

void delay(unsigned int mseconds) {	//	Function that allows the delay of program executions, without this the horse race ends too quickly and it's annoying to watch.
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

void horsesWon(int winners[], int numOfWinners) {	//	Function that displays the winners of previous races
	CLS;
	printf("\nHere are the list of winners\n");

	for (int i = 0; i < numOfWinners; i++) {
		printf("Race # %i: Horse # %d won race\n", i + 1, winners[i]);
	}
	// end for loop

} // end winners

void mainMenu() {

	int mSelection = 0;	//	Menu choice
	double morseMoney[2] = { 0 , 300 };	//	Element 0 is Wallet, Element 1 is Bank
	int *winningHorses[1000] = { 0 }, winnerCount = 0, pick;	//	Stores the horses that win, is a race counter, is the horse betted on
	double betAmount = 0;
	int errorCheck;	//	Just a true false switch

	do {	// Begin Menu Loop

		CLS;

		currentMoney(morseMoney);	//	Banner Display

		printf("What would you like to do? \n");
		printf("\n 1. Go to the Bank");
		printf("\n 2. Place a bet");
		printf("\n 3. Go to the track");
		printf("\n 4. View Past Winners");
		printf("\n 5. Go Home");

		printf("\n Enter Selection: ");
		scanf_s("%i", &mSelection); FLUSH;

		switch (mSelection) { // Begin switch

		case 1:

			bankMenu(morseMoney);	//	To the Bank

			break;

		case 2:

			if (betAmount != 0) {	//	Prevents multiple bets since you can only bet on one winner
				printf("\nYou Already Have a Standing Bet! Go to the Track.\n\n");
				break;
			}
			CLS;
			pick = 10;	//	Defaults to out of limits to indicate if no bet was placed
			currentMoney(morseMoney);	//	Banner
			betAmount = bettingWindow(morseMoney);	//	Sets bet amount
			if (betAmount == 0) {	//	error check for if bet isn't placed
				pick = 10;
				break;
			}
			errorCheck = 0;	//	Error check initialization for not picking a horse
			do {
				printf("Which horse would you like to bet on: ");
				scanf_s("%i", &pick);
				if (pick < 1 || pick > 9) {
					printf("\nPlease Select a Valid Option.\n");
				}
				else {
					errorCheck = 1;	//	allows loop exit
				}
			} while (errorCheck == 0);
			break;

		case 3:
			winnerCount++;	//	keeps track of number of winners (or times race executed)
			raceTime(morseMoney, winningHorses, winnerCount, pick, betAmount);	//	The actual race
			betAmount = 0;	//	resets bet
			break;

		case 4:
			if (winnerCount == 0) {		//	Just an error check
				printf("There have been no races yet today.\n");
				break;
			}
			else {
				horsesWon(winningHorses, winnerCount);	//	displays winners
				break;
			}

		case 5:
			printf("The Track is Closing for the Day.\n\n");
			break;

		default:	//	Error Checking
			printf("Please enter a valid option \n");
			break;
		} // End switch

		PAUSE;

	} while (mSelection != 5);

}	//	End Menu Function

void raceTime(double morseMoney[], int winningHorses[], int raceCounter, int pick, double betAmount) {

	int didSomeoneWin = 0, advancement = 0;
	int horseRunningNumbers[9] = { 0 };
	int x, whosTheWinner;

	char theRace[9][26] = { ' ' };
	theRace[0][0] = 'A';	//	American Pharoah # 1
	theRace[1][0] = 'S';	//	Seabiscuit # 2
	theRace[2][0] = 'B';	//	Black Stalion # 3
	theRace[3][0] = 'D';	//	Dirty Hilary # 4
	theRace[4][0] = 'H';	//	Hundchuck # 5
	theRace[5][0] = 'T';	//	Trigger	# 6
	theRace[6][0] = 'E';	//	Epona # 7
	theRace[7][0] = 'R';	//	Roach # 8
	theRace[8][0] = 'b';	//	Buckwheat Grotes # 9

	for (int i = 0; i < 9; i++) {	//	Shows a finish line
		theRace[i][25] = '|';
	}


	x = rand() % 100 + 1;
	whosTheWinner = awayTheyGo(x);	//	Generates a random winner within the fixed odds percentage 

	do {
		CLS;
		currentMoney(morseMoney);	//	Banner

		for (int i = 0; i < 9; i++) {		//	Displays the "track" two dimensional Array
			for (int j = 0; j < 26; j++) {
				printf("%c ", theRace[i][j]);
				FLUSH;
			}
			printf("\n");
		}

		x = rand() % 9 + 1;	//	Just random advancement to make it look like a race
		advancement = x;
		delay(100);	//	Delays for readability
		raceUpdate(advancement, theRace, &horseRunningNumbers, whosTheWinner);	//	Actual action of altering the 2d array

		didSomeoneWin = winnerCheck(theRace);	//	Determines if the array has displayed someone winning
		winningHorses[raceCounter - 1] = whosTheWinner;	//	records the winner of the race

	} while (didSomeoneWin != 1);

	if (pick == whosTheWinner) {	//	Payout for winner
		morseMoney[0] += betHorse(pick, betAmount);
		printf("\nYou won!\n");
		printf("You now have %.2lf in your wallet\n\n", morseMoney[0]);
	}
	else if (pick <= 9) {	//	Message for Loser
		printf("\nSorry, Not a winner.\n");
	}

}

void raceUpdate(int advancementValue, char theRace[][26], int horseArray[], int whosTheWinner) {

	if (theRace[0][22] == 'A' || theRace[1][22] == 'S' || theRace[2][22] == 'B' || theRace[3][22] == 'D' || theRace[4][22] == 'H' || theRace[5][22] == 'T' ||
		theRace[6][22] == 'E' || theRace[7][22] == 'R' || theRace[8][22] == 'b') {	//	Rushes the winner to the victory line if Any letter is closing in, for the appearance of a close race
		horseArray[whosTheWinner - 1]++;
		theRace[whosTheWinner - 1][horseArray[whosTheWinner - 1] - 1] = '.';
		theRace[whosTheWinner - 1][horseArray[whosTheWinner - 1]] = winnersLetter(whosTheWinner);
	}
	else {	//	If their value is hit, it replaces prior element with a foot stamp '.' and advances the horse by one
		if (advancementValue == 1) {
			horseArray[0]++;
			theRace[0][(horseArray[0] - 1)] = '.';
			theRace[0][(horseArray[0])] = 'A';
		}
		else if (advancementValue == 2) {
			horseArray[1]++;
			theRace[1][(horseArray[1] - 1)] = '.';
			theRace[1][(horseArray[1])] = 'S';
		}
		else if (advancementValue == 3) {
			horseArray[2]++;
			theRace[2][(horseArray[2] - 1)] = '.';
			theRace[2][(horseArray[2])] = 'B';
		}
		else if (advancementValue == 4) {
			horseArray[3]++;
			theRace[3][(horseArray[3] - 1)] = '.';
			theRace[3][(horseArray[3])] = 'D';
		}
		else if (advancementValue == 5) {
			horseArray[4]++;
			theRace[4][(horseArray[4] - 1)] = '.';
			theRace[4][(horseArray[4])] = 'H';
		}
		else if (advancementValue == 6) {
			horseArray[5]++;
			theRace[5][(horseArray[5] - 1)] = '.';
			theRace[5][(horseArray[5])] = 'T';
		}
		else if (advancementValue == 7) {
			horseArray[6]++;
			theRace[6][(horseArray[6] - 1)] = '.';
			theRace[6][(horseArray[6])] = 'E';
		}
		else if (advancementValue == 8) {
			horseArray[7]++;
			theRace[7][(horseArray[7] - 1)] = '.';
			theRace[7][(horseArray[7])] = 'R';
		}
		else if (advancementValue == 9) {
			horseArray[8]++;
			theRace[8][(horseArray[8] - 1)] = '.';
			theRace[8][(horseArray[8])] = 'b';
		}
	}
}

int winnerCheck(char theRace[][26]) {	//	Checks for a horse reaching the finish line to break out of the race loop

	if (theRace[0][26] == 'A') {
		return 1;
	}
	else if (theRace[1][26] == 'S') {
		return 1;
	}
	else if (theRace[2][26] == 'B') {
		return 1;
	}
	else if (theRace[3][26] == 'D') {
		return 1;
	}
	else if (theRace[4][26] == 'H') {
		return 1;
	}
	else if (theRace[5][26] == 'T') {
		return 1;
	}
	else if (theRace[6][26] == 'E') {
		return 1;
	}
	else if (theRace[7][26] == 'R') {
		return 1;
	}
	else if (theRace[8][26] == 'b') {
		return 1;
	}
	else {
		return 0;
	}

}

char winnersLetter(int whosTheWinner) {

	//	Returns the letter of the winning horse for rushing the winner into the finish line

	if (whosTheWinner == 1) {
		return 'A';
	}
	else if (whosTheWinner == 2) {
		return 'S';
	}
	else if (whosTheWinner == 3) {
		return 'B';
	}
	else if (whosTheWinner == 4) {
		return 'D';
	}
	else if (whosTheWinner == 5) {
		return 'H';
	}
	else if (whosTheWinner == 6) {
		return 'T';
	}
	else if (whosTheWinner == 7) {
		return 'E';
	}
	else if (whosTheWinner == 8) {
		return 'R';
	}
	else if (whosTheWinner == 9) {
		return 'b';
	}
}