//==============================================
// Name:  Atif Hammud Ali
// Student Number: 116743196
// Email:  AALI309@myseneca.ca
// Section:        XXX
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
// program that will display temperature,the highest and lowest temperature and which days

#include <stdio.h>
int main()

{   double ave;
    int totalhigh = 0,totallow = 0,avedays,i;
    int lowestday,highestday,highest,lowest;
    int days,day;
    int temphi[10];
    int templo[10];
    printf ("---=== IPC Temperature Calculator V2.0 ===---\n");



    printf("Please enter the number of days, between 3 and 10, inclusive: ");
    scanf("%d",&days);
    printf("\n");
    while (days<3 || days>10)
    {
        printf("invalid entry, please enter a number between 3 and 10, inclusive: ");
        scanf("%d",&days);
        printf("\n");
    }
    for (day=0; day < days; day++)
    {
    printf("Day %d - High: ",day+1);
    scanf("%d", &temphi[day]);
    printf("Day %d - Low: ",day+1);
    scanf("%d",&templo[day]);
    }
    printf("\n");
    printf("Day  Hi  Low\n");
    printf("\n");

    for (day=0;day<days;day++) // for loop
    {
        printf("%d   %d   %d\n",day+1,temphi[day],templo[day]);

    }


    for (day = 0; day < days ; day++) //for loop
    {
        if (temphi[day] > highest)
           {
               highest = temphi[day];
               highestday = day +1;
           }
        if (templo[day] < lowest)
           {
               lowest = templo[day];
               lowestday = day +1;
           }
    }

    printf("\nThe highest temperature was %d, on day %d", highest,highestday);
    printf("\nThe lowest temperature was %d, on day %d",lowest,lowestday);



	do
	{
	    printf("\n\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ",days);
	    scanf("%d", &avedays);

	    while (avedays == 0 || avedays > days)
	    {
	        printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ",days);
		    scanf("%d", &avedays);
	    }

	    for (i= 0; i < avedays; i++)
	    {
	totalhigh +=temphi[i];
	totallow +=templo[i];
	    }
	ave = ((double)totalhigh + (double)totallow)/(2*avedays);

		printf("\nThe average temperature up to day %d is: %.2lf\n", avedays, ave);
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ",days);
		scanf("%d", &avedays);
		//totallow = 0; totalhigh = 0; ave = 0;
	}

 while (avedays >= 0);
  printf("\nGoodbye!");


return 0;
