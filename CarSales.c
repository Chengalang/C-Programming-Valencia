#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double carSales();
double firstTimeBuyerDisc(double totalSale);
double veteranDisc(double totalSale);
double studentDisc(double totalSale);

 main() {

	int newSale = 0, counter = 0;
	double averageCarSold = 0.0, totalRevenue = 0.0;
	bool done = false;

	do {
		printf("Would you like to enter a new sale?\n1. Yes\n2. No\n\n");
		scanf("%d", &newSale);

		// very sloppy way of 'holding 50,000' car sales, will look up more ways of doing this
		if (newSale == 1 && counter < 50001) {
			totalRevenue += carSales();
			counter++;
			printf("\nTotal cars sold: %d\nTotal revenue collected: %.2lf\nAverge car sold price: %.2lf\n\n", counter, totalRevenue, totalRevenue / counter);
		}
		else {
			printf("Good job on all your sales!\n");
			printf("\nTotal cars sold: %d\nTotal revenue collected: %.2lf\nAverge car sold price: %.2lf\n", counter, totalRevenue, totalRevenue / counter);
			printf("Total revenue marked up: %.2lf\n", totalRevenue += (totalRevenue * 0.05));
			done = true;
		}
	} while (!done);

	system("pause");
	return 0;

} // end of Main

double carSales() {

	int lastDay = 0, discount = 0, carLog = 1;
	double stickerPrice = 0.0, totalSale = 0.0;
	bool done = false;

		printf("\nPlease enter sticker price: ");
		scanf("%lf", &stickerPrice);

		printf("Was the car purchased on the last day of the month\n1. Yes \n2. No \n");
		scanf("%d", &lastDay);

		// Normally I would like to stay away from nested if statements
		if (lastDay == 1) {
			totalSale = stickerPrice - (stickerPrice * 0.05);
			printf("New car total is: %.2lf \n", totalSale);
		}
		else {
			totalSale = stickerPrice;
			printf("No discount applied. Car total is: %.2lf \n", totalSale);
		}

		do{ 
			printf("\nIs the buyer a \n 1. First time buyer \n 2. Veteran \n 3. Student \n 4. No more discounts\n");
			scanf("%d", &discount);

				switch (discount) {
				case 1:
					totalSale = firstTimeBuyerDisc(totalSale);
					break;
				case 2:
					totalSale = veteranDisc(totalSale);
					break;
				case 3:
					totalSale = studentDisc(totalSale);
					break;
				case 4:
					done = true;
					break;
				default:
					printf("Invalid option. Please enter 1 - 4");
					break;
				} // end of Switch

		} while (!done);

		return totalSale;
} // end of carSales

double firstTimeBuyerDisc(double totalSale) {
	totalSale -= 500.0;
	printf("%.2lf\n", totalSale);
	return totalSale;
} // end of firstTimeBuyer

double veteranDisc(double totalSale) {
	totalSale -= (totalSale * 0.01);
	printf("%.2lf\n", totalSale);
	return totalSale;
} // end of veteranDisc

double studentDisc(double totalSale) {
	totalSale -= 1200;
	totalSale -= (totalSale * 0.01);
	printf("%.2lf \n", totalSale);
	return totalSale;
} // end of studentDisc