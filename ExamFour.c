/*
EXAM 4
Written by : Kenny Cheng
Final Written Date : 4/16/17

Purpose: To create a program that allows users to enter a daily record
of their win loss stats. Program will allow user to calculate weekly Kill Death Ratio, view weekly
win loss scores or show scores of specific dates. 


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define pause system("pause");
#define cls system("cls");

typedef struct {
	char name[40];
	int age;
	char sex[8];
} PLAYER;

typedef struct {
	int month;
	int day;
	int year;
} DATE;

typedef struct {
	int kills;
	int deaths;
	DATE gameDate;
} RECORD;

void displayMenu();
PLAYER* createPlayer();
void enterPlayerInfo(PLAYER *player);
void addGameScores(DATE scoreDate[], RECORD winLoss[], int *scoreByDay);
void populateTheDate(DATE gameDate[], int i, int month, int day, int year);
void displayRecordByDate(DATE scoreDate[], int *scoreByDay, RECORD winLoss[], PLAYER *info);
void displayAllRecords(RECORD winLoss[], PLAYER *info, DATE scoreDate[], int *scoreByDay);

main() {

	PLAYER *playerInfo;
	DATE dateOfGames[1000];
	RECORD winLoss[1000] = { 0 };
	int choice, scoreByDay = 0;
	bool done = false;

	while (!done) {

		displayMenu();
		scanf("%i", &choice);

		switch (choice) {
		case 1:
			cls;
			playerInfo = calloc(1, sizeof(PLAYER*));

			if (playerInfo == NULL) {
				printf("Allocation of memory failed.\n");
				exit(-1);
			}

			playerInfo = createPlayer();
			enterPlayerInfo(playerInfo);
			break;
		case 2:
			cls;
			addGameScores(dateOfGames, winLoss, &scoreByDay);
			break;
		case 3:
			cls;
			displayRecordByDate(dateOfGames, &scoreByDay, winLoss, playerInfo);
			pause;
			break;
		case 4:
			cls;
			displayAllRecords(winLoss, playerInfo, dateOfGames, &scoreByDay);
			pause;
			break;
		case 5:
			done = true;
			printf("\n");
			break;
		default:
			printf("Wrong Selection.");
			break;
		}
	};

	free(playerInfo);

} // end of main

PLAYER* createPlayer() {
	PLAYER* result;

	result = malloc(sizeof(PLAYER));

	return result;
} // end createPlayer

void enterPlayerInfo(PLAYER *player) {


	printf("Enter Name: ");
	scanf("%s", player->name);
	printf("Enter Age: ");
	scanf("%d", &player->age);
	printf("Enter Sex (Male or Female): ");
	scanf("%s", player->sex);
	printf("\n");

} // end enterPlayerInfo

void addGameScores(DATE scoreDate[], RECORD winLoss[], int *scoreByDay) {

	int month, day, year;
	int numOfGames;
	int numOfKills = 0, numOfDeaths = 0;

	printf("Which day would you like to enter scores for? (Enter in M D Y format please): ");
	scanf("%d %d %d", &month, &day, &year);

	printf("How many games were played on that date? ");
	scanf("%i", &numOfGames);

	winLoss[*scoreByDay].gameDate, populateTheDate(scoreDate, *scoreByDay, month, day, year);

	for (int i = 0; i < numOfGames; i++) {
		printf("\nNumber of kills: ");
		scanf("%i", &numOfKills);
		printf("Numer of deaths: ");
		scanf("%i", &numOfDeaths);

		winLoss[*scoreByDay].kills += numOfKills;
		winLoss[*scoreByDay].deaths += numOfDeaths;
	}

	(*scoreByDay)++;

} // end addGameScores

void populateTheDate(DATE scoreDate[], int i, int month, int day, int year) {

	scoreDate[i].month = month;
	scoreDate[i].day = day;
	scoreDate[i].year = year;

} // end populateTheDate

void displayRecordByDate(DATE scoreDate[], int *scoreByDay, RECORD winLoss[], PLAYER *info) {

	int month, day, year;
	double kDR;

	printf("Which date would you like to see(Enter in M D Y format with spaces): ");
	scanf("%d %d %d", &month, &day, &year);

	for (int i = 0; i < *scoreByDay; i++) {
		if (scoreDate[i].month == month && scoreDate[i].day == day && scoreDate[i].year == year) {
			printf("\nName: %s\n", info->name);
			printf("Age: %i\n", info->age);
			printf("Sex: %s\n", info->sex);
			printf("Total Number of Kills for the Day: %i\n", winLoss[i].kills);
			printf("Total Number of Deaths for the Day: %i\n", winLoss[i].deaths);

			kDR = ((double)winLoss[i].kills / (double)winLoss[i].deaths);

			printf("\n\nKDR (Kill Death Ratio) for the day is: %.2lf\n", kDR);
		}
	}

} // end recordByDate

void displayAllRecords(RECORD winLoss[], PLAYER *info, DATE scoreDate[], int *scoreByDay) {

	int totalKills = 0, totalDeaths = 0;
	double kDR;

	printf("All recorded win loss records for %s are\n", info->name);

	for (int i = 0; i < *scoreByDay; i++) {
		printf("\t%d / %d / %d\n", scoreDate[i].month, scoreDate[i].day, scoreDate[i].year);
		printf("----------------------\n");
		printf("Total Kills: %d\n", winLoss[i].kills);
		printf("Total Deaths: %d\n", winLoss[i].deaths);
		printf("\n");
	}

	for (int j = 0; j < *scoreByDay; j++) {
		totalKills += winLoss[j].kills;
		totalDeaths += winLoss[j].deaths;
	}

	kDR = ((double)totalKills / (double)totalDeaths);

	printf("Total KDR for the week: %.2lf\n", kDR);

} // end displayAllRecords

void displayMenu() {

	cls;
	printf("\t\t\t\t\t--------------------------\n");
	printf("\t\t\t\t\t        Main Menu         \n");
	printf("\t\t\t\t\t--------------------------\n");
	printf("\t\t\t\t\t1. Submit Player Info\n");
	printf("\t\t\t\t\t2. Enter Game Scores\n");
	printf("\t\t\t\t\t3. Display Scores by Date\n");
	printf("\t\t\t\t\t4. Display All Scores\n");
	printf("\t\t\t\t\t5. Exit Program\n");

} // end displayMenu