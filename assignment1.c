#include <stdio.h>
#include <stdlib.h>

void numEqualsRepeat(int num, int num2);

int main() {

	
	numEqualsRepeat(1, 10);
	numEqualsRepeat(2, 9);
	numEqualsRepeat(3, 8);
	numEqualsRepeat(4, 7);
	numEqualsRepeat(5, 6);
	numEqualsRepeat(6, 5);
	numEqualsRepeat(7, 4);
	numEqualsRepeat(8, 3);
	numEqualsRepeat(9, 2);
	numEqualsRepeat(10, 1);

	system("pause");

	return 0;

}

void numEqualsRepeat(int num, int num2) {

	printf("%d. x equals %d.\n", num, num2);

	return;

}