#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PAUSE system("pause")
#define CLS system("cls")
#define FLUSH fflush(stdin)
#define ROW 35
#define COL 70

void printPuzzle();
char enterWords();

main() {

	srand(time(NULL));

	printPuzzle();
	enterWords();

	PAUSE;
	return;

} // end of main 

void printPuzzle() {

	char randomLetter;
	FILE* wordPuzzle;
	long allTheLetters[ROW][COL];

	wordPuzzle = fopen("c:\\MyFiles\\wordPuzzle.txt", "w");
	if (wordPuzzle == NULL) {
		printf("We failed to open the file");
		exit(-1);
	} // check if file exists

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			allTheLetters[i][j] = 'A' + (rand() % 26);
			randomLetter = allTheLetters[i][j];
			printf("%c", randomLetter);
			fprintf(wordPuzzle, "%c", randomLetter);
		}
		printf("\n");
		fprintf(wordPuzzle, "\n");
	} // end of for loop

	fclose(wordPuzzle);

	return;

} // end of printPuzzle

  /*
  ====================================
		   UNDER CONSTRUCTION
  ====================================
  */

char enterWords() {
	
	const char *enterWords[18], word;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			printf("Enter a word: ");
			scanf("%c", &word);
			printf("%c", word);
			//enterWords[i] = word;
		}
		//printf("%s", enterWords[i]);
	}

} // end of enterWords