//==============================================
// Name: Atif Hammud Ali
// Student Number: 116743196
// Email:          AALI309@myseneca.ca
// Section:       at home
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include <stdio.h>
int main()

{
	
	double amount;
	int allCoins;
	int balance;
	double tax;
	const double gst = 0.13;


	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);
	tax = amount * gst + 0.005;
	printf("GST: %.2lf\n", tax);

	amount = amount + tax;

	printf("Balance owing: $%.2lf\n", amount);

	allCoins = (int)amount;
	amount = (amount - allCoins);
	printf("Loonies required: %d, balance owing $%.2lf\n", allCoins, amount);

	balance = (int)(amount * 100);
	allCoins = (balance / 25);
	balance = (balance % 25);
	printf("Quarters required: %d, balance owing $%.2lf\n", allCoins, (double)balance / 100);

	allCoins = (balance / 10);
	balance = (balance % 10);
	printf("Dimes required: %d, balance owing $%.2lf\n", allCoins, (double)balance / 100);

	allCoins = (balance / 5);
	balance = (balance % 5);
	printf("Nickels required: %d, balance owing $%.2lf\n", allCoins, (double)balance / 100);

	allCoins = (balance / 1);
	balance = (balance % 1);
	printf("Pennies required: %d, balance owing $%.2lf\n", allCoins, (double)balance / 100);



	return 0;
}