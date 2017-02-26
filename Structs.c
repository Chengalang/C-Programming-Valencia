#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pause system("pause")

typedef struct {
	int month;
	int day;
	int year;
} DATE;

typedef struct {
	char name[20];
	DATE birthday;
	char gender[7];
	long income;
} PERSON;

void fillInPerson(PERSON[], int*, long, DATE[], int, int, int, char*, char*);
void populateTheDate(DATE[], int, int, int, int);
void displayPeopleList(PERSON[], DATE[], int*);

main() {

	int listSize = 0;
	PERSON peopleList[3];
	DATE birthdayList[3];

	fillInPerson(peopleList, &listSize, 32000, birthdayList, 1, 2, 1978, "Tony", "Male");
	fillInPerson(peopleList, &listSize, 50000, birthdayList, 2, 5, 2001, "Scott", "Male");
	fillInPerson(peopleList, &listSize, 75000, birthdayList, 3, 6, 1990, "Cindy", "Female");

	displayPeopleList(peopleList, birthdayList, &listSize);

	pause;
	return;

} // end main

void displayPeopleList(PERSON peopleList[], DATE birthdayList[], int *pSize) {

	for (int i = 0; i < *pSize; i++) {
		printf("Name: %s\n", peopleList[i].name);
		printf("Birthday: %02i-%02i-%02i\n", birthdayList[i].month, birthdayList[i].day, birthdayList[i].year);
		printf("Gender: %s\n", peopleList[i].gender);
		printf("Annual Salary: $%ld\n\n", peopleList[i].income);
	}

} // displayPeopleList

void fillInPerson(PERSON listSize[], int *pSize, long income, DATE birthdayList[], int month, int day, int year, char *firstName, char *gender) {

	strcpy(listSize[*pSize].name, firstName);
	strcpy(listSize[*pSize].gender, gender);
	listSize[*pSize].birthday, populateTheDate(birthdayList, *pSize, month, day, year);
	listSize[*pSize].income = income;
	(*pSize)++;

} // end fillInProducts

void populateTheDate(DATE birthdayList[], int i, int month, int day, int year) {

	birthdayList[i].month = month;
	birthdayList[i].day = day;
	birthdayList[i].year = year;

} // end populateTheDate