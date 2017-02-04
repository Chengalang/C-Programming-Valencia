/*
IOProcessing Assignment
Written by : Kenny Cheng
Final Written Date : 2/4/17
Purpose: Learn how to record data onto outside source other than 
		 Visual Studio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define pause system("pause")
#define flush fflush(stdin)
#define cls system("cls")
#define GRADES 4

void displayMenu();
int getChoice();
bool areYouDone();
double enterGrades();
double avgStudentExamScore(double examScores);
double avgExamScore(double examScores, int numOfStudents);
double avgClass(double examScores, int numOfStudents);

main() {

	FILE* binGradebook;
	FILE* textGradebook;
	int choice, numOfStudents = 0, student, exam;
	bool done = false;;
	double studentGrades[50][GRADES], examGrades;

	printf("How many students took this exam: ");
	scanf("%i", &numOfStudents);
	
	for (int i = 0; i < numOfStudents; i++) {
		printf("Enter student #%i's grades:\n", i + 1);
		for (int j = 0; j < GRADES; j++) {
			studentGrades[i][j] = enterGrades();
			}
		} 
		// end of for loop
	
	// -- Main Program -- 
	do {
			cls;

			textGradebook = fopen("c:\\MyFiles\\textGradebook.txt", "w");
			if (textGradebook == NULL) {
				printf("We failed to open the file");
				exit(-1);
			} // check if file exists

			choice = getChoice();

			switch (choice) {
			case 1:

				examGrades = 0.0;
				printf("Which student would you like to look up? ");
				scanf("%i", &student);
				
				if (student > numOfStudents) {
					printf("That student is not in the system\n");
					break;
				}

				for (int i = 0; i < 4; i++) {
					examGrades += studentGrades[student - 1][i];
				}
				// end for loop
				avgStudentExamScore(examGrades);

				pause;
				break;
			case 2:

				examGrades = 0.0;
				printf("Which exam would you like to look up? ");
				scanf("%i", &exam);

				if (exam > 4) {
					printf("That exam does not exist\n");
					break;
				}

				for (int i = 0; i < numOfStudents; i++) {
						examGrades += studentGrades[i][exam - 1];
				}
				// end for loop

				avgExamScore(examGrades, numOfStudents);

				pause;
				break;
			case 3:

				examGrades = 0.0;
				for (int i = 0; i < numOfStudents; i++) {
					for (int j = 0; j < GRADES; j++) {
						examGrades += studentGrades[i][j];
					}
				}
				// end for loop

				avgClass(examGrades, numOfStudents);
				pause;
				break;
			case 4:
				for (int i = 0; i < numOfStudents; i++) {
					for (int j = 0; j < GRADES; j++) {
						studentGrades[i][j] = 0;
					}
				} // end loop 
				pause;
				break;
			case 5:
				for (int i = 0; i < numOfStudents; i++) {
					fprintf(textGradebook, "\nStudent #%d: ", i + 1);
					for (int j = 0; j < GRADES; j++) {
						fprintf(textGradebook, "\t%.2lf", studentGrades[i][j]);
					}
				}

				fclose(textGradebook);
				// end for loop
				pause;
				break;
			case 6:
				done = true;
				break;
			default:
				printf("Wrong selection");
				break;
			} // end switch


		done = areYouDone();

	} while (!done);

	// Open bin file to save progress
	binGradebook = fopen("c:\\MyFiles\\binGradebook.bin", "wb");

	if (binGradebook == NULL) {
		printf("Problem writing file!\n");
		exit(-1);
	} // check if file is there

	for (int i = 0; i < numOfStudents; i++) {
		for (int j = 0; j < GRADES; j++) {
			fwrite(&studentGrades[i][j], sizeof(double), numOfStudents, binGradebook);
		}
	}
	// end for loop adding to bin file

	fclose(binGradebook);
	// closing both Gradebooks
	pause;
	return;

} // end of main

void displayMenu() {

	cls;
	printf("\t-------------------------------------------");
	printf("\t\n\t\t\t Main Menu\n");
	printf("\t-------------------------------------------\n\n");
	printf("1) Average Student Exam Scores\n");
	printf("2) Average Score by Exam\n");
	printf("3) Class Average\n");
	printf("4) Clear Gradebook\n");
	printf("5) Output Final Grades to TXT\n");
	printf("6) Exit Program\n");
	return;

} // end displayMenu

int getChoice() {

	int result;
	displayMenu();
	scanf("%i", &result);
	flush;
	return result;

} // end getChoice

bool areYouDone() {

	int result;
	printf("\Is there anything else you would like to do?\n1. Yes\n2. No\n");
	scanf("%i", &result);
	if (result == 1) {
		result = false;
	}
	else if (result == 2) {
		printf("\nThank you for updating the system. \nHave a great day\n\n");
		result = true;
	}
	return result;

} // end areYouDone

double enterGrades() {

	double grades;
	printf("Enter Exam Score: ");
	scanf("%lf", &grades);
	return grades;

} // end enterGrades

double avgStudentExamScore(double examScores) {

	double result;
	result = examScores / 4.0;
	printf("Average student score on exams is: %.2lf\n", result);
	return;

} // end avgExamScore

double avgExamScore(double examScores, int numOfStudents) {

	double result;
	result = examScores / numOfStudents;
	printf("Average score for this exam is: %.2lf\n", result);

	return result;

} // end avgExamScore

double avgClass(double examScores, int numOfStudents) {

	double result;
	numOfStudents *= 4;
	result = examScores / numOfStudents;
	printf("Average class exam score is: %.2lf\n", result);
	return result;

} // end avgClass



