//==============================================
// Name:  Atif Hammud Ali
// Student Number: 116743196
// Email:  AALI309@myseneca.ca
// Section:        XXX
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:


#include <stdio.h>
int main()

{
    int days,day;
    int temphi[10];
    int templo[10];
    printf ("---=== IPC Temperature Calculator V2.0 ===---\n");



    printf("Please enter the number of days, between 3 and 10, inclusive: ");
    scanf("%d",&days);
    printf("\n");
    while (days<3 || days>10)
    {
        printf("invalid entry, please enter a number between 3 and 10, inclusive:");
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
    printf("Day Hi Low\n");
    printf("\n");

    for (day=0;day<days;day++)
    {
        printf("%d   %d   %d\n",day+1,temphi[day],templo[day]);
    }

    return 0;
}
