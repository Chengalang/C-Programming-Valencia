#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*

Kenny Cheng
1/18/17

This program is designed to allow users to take 3 integers and calculate basic math problems

The spec said to write a 'short program' and I did so but I wanted to experiment some more and add 
a little extra functionality to the program.
*/

int threeRandIntegers();
int threeUserIntegers(int i);
int getSum(int numOne, int numTwo, int numThree);
int getProduct(int numOne, int numTwo, int numThree);
double getAverage(double numOne, double numTwo, double numThree);
int getLowest(int numOne, int numTwo, int numThree);

main() {

	int myThreeInts[3], selectionStart, selectionContinue;
	char selectionSwitch;
	bool done = false;

	printf("\n\tWelcome to Math made easy\n\n");

	printf("Here you will need to provide 3 integers.\n\nWould you like them randomly generated?\n1. Yes\n2. No (enter yourself)\n");
	scanf("%d", &selectionStart);
	/*
	Extra if statement and function for lazy users who don't want to think of their own three ints
	*/
	if (selectionStart == 1) {

		printf("\nYour three RANDOM numbers are: ");
		for (int i = 0; i < 3; i++) {
			myThreeInts[i] = threeRandIntegers();
			printf("%d ", myThreeInts[i]);
		}

	} else {

		for (int i = 0; i < 3; i++) {
			myThreeInts[i] = threeUserIntegers(i);
		}

		printf("Your three INPUT numbers are: ");
		for (int i = 0; i < 3; i++) {
			printf("%d ", myThreeInts[i]);
		}

	} // end if

	/*
	added the do while statement for two purposes
	1) testing the program easier for the different switch statements
	2) to give the program a better flow. It would be cumbersome to have a user turn on and off a calculator everytime
	   they wanted to do a new problem
	*/
	do {

		printf("\n\nWhat would you like to do with those three numbers?\nA. Sum\nB. Product\nC. Average\nD. Lowest Value\nE. Finished\n");
		scanf("%c", &selectionSwitch);

		selectionSwitch = getchar();

		switch (selectionSwitch) {
		case 'A':
		case 'a':
			getSum(myThreeInts[0], myThreeInts[1], myThreeInts[2]);
			printf("Would you like to try another function?\n1. Yes\n2. No\n");
			scanf("%d", &selectionContinue);
			
			if (selectionContinue == 1) {
				printf("Good choice! Keep practicing those math skills!");
			} else {
				printf("Come back later and practice some more\n");
				done = true;
			}
			break;
		case 'B':
		case 'b':
			getProduct(myThreeInts[0], myThreeInts[1], myThreeInts[2]);
			printf("Would you like to try another function?\n1. Yes\n2. No\n");
			scanf("%d", &selectionContinue);

			if (selectionContinue == 1) {
				printf("Good choice! Keep practicing those math skills!");
			}
			else {
				printf("Come back later and practice some more\n");
				done = true;
			}
			break;
		case 'C':
		case 'c':
			getAverage(myThreeInts[0], myThreeInts[1], myThreeInts[2]);
			printf("Would you like to try another function?\n1. Yes\n2. No\n");
			scanf("%d", &selectionContinue);

			if (selectionContinue == 1) {
				printf("Good choice! Keep practicing those math skills!");
			}
			else {
				printf("Come back later and practice some more\n");
				done = true;
			}
			break;
		case 'D':
		case 'd':
			getLowest(myThreeInts[0], myThreeInts[1], myThreeInts[2]);
			printf("Would you like to try another function?\n1. Yes\n2. No\n");
			scanf("%d", &selectionContinue);

			if (selectionContinue == 1) {
				printf("Good choice! Keep practicing those math skills!");
			}
			else {
				printf("Come back later and practice some more\n");
				done = true;
			}
			break;
		case 'E':
		case 'e':
			printf("Come back later and practice some more\n");
			done = true;
			break;
		default:
			printf("\n%c is not an option, try again", selectionSwitch);
			break;
		} // end switch

	} while (!done); // end of do while loop

	system("pause");
	return 0;
} // end of main

int threeRandIntegers() {

	/*
	This was not apart of the spec but I wanted to add this feature because I thought it would be simple
	and added an extra layer to the project but upon trying I noticed it was not as easy as I thought.
	I didn't want to give up on the idea so I kept trying it and this was the best result I came with using the fewest lines of code.
	*/

	int result;

	result = (rand() % 100) + 1;

	return result;

	// I ended up overthinking the process until I realized it was just this simple.

} // end of threeRandomsIntegers

int threeUserIntegers(int i) {

	int result;

	if (i == 0) {
		printf("\nEnter your %dst number: ", i + 1);
		scanf("%d", &result);
	}
	else if (i == 1) {
		printf("Enter your %dnd number: ", i + 1);
		scanf("%d", &result);
	}
	else {
		printf("Enter your %drd number: ", i + 1);
		scanf("%d", &result);
	}

	return result;

} // end of threeUserIntegers

int getSum(int numOne, int numTwo, int numThree) {

	int result;

	result = numOne + numTwo + numThree;
	printf("\nThe sum of your three numbesr are: %d\n\n", result);

	return result;

} // end getSum

int getProduct(int numOne, int numTwo, int numThree) {

	int result;

	result = numOne * numTwo * numThree;
	printf("\nThe product of your three numbers are: %d\n\n", result);

	return result;

} // end getProduct

double getAverage(double numOne, double numTwo, double numThree) {

	double result;

	result = (numOne + numTwo + numThree) / 3;
	printf("\nThe average of your three numbesr is: %.2lf\n\n", result);

	return result;

} // end getAverage

int getLowest(int numOne, int numTwo, int numThree) {

	if (numOne < numTwo && numOne < numThree) {
		printf("\n%d is the lowest number\n\n", numOne);
	} else if (numTwo < numOne && numTwo < numThree) {
		printf("\n%d is the lowest number\n\n", numTwo);
	} else {
		printf("\n%d is the lowest number\n\n", numThree);
	}

} // end getLowest