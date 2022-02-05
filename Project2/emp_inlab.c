//==============================================
// Name: Atif Hammud Ali
// Student Number: 116743196
// Email:  AALI309@myseneca.ca
// Section:        XXX
// Workshop:       5 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
    #define SIZE 2
// Declare Struct Employee
struct employeeStruct
{
    int id;
    int age;
    double salary;
};

/* main program */
int main(void)
{
	int i,option = 0,adding = 0;
	struct employeeStruct emp[SIZE] = {{0}};

	// Declare a struct Employee array "emp" with SIZE elements
	// and initialize all elements to zero


	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d",&option);
		printf("\n");

		switch (option)
		{
		case 0:
		printf("Exiting Employee Data Program. Good Bye!!!\n"); // Exit the program

			break;

		case 1: // Display Employee Data
				// @IN-LAB

			// Use "%6d%9d%11.2lf" formatting in a
			// printf statement to display
			// employee id, age and salary of
			// all  employees using a loop construct

			// The loop construct will be run for SIZE times
			// and will only display Employee data
			// where the EmployeeID is > 0

            printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0; i < SIZE; i++)
			{
				if (emp[i].id > 0)
				{
					printf("%6d%9d%11.2lf", emp[i].id, emp[i].age, emp[i].salary);
					printf("\n");
				}
			}
			printf("\n");
			break;

		case 2:	// Adding Employee
				// @IN-LAB

			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee
			// data accordingly.

			if (adding < SIZE)
			{
				printf("Enter Employee ID: ");
				scanf("%d", &emp[adding].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[adding].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[adding].salary);
				printf("\n");
				adding++;
			}
             else
            {
				printf("ERROR!!! Maximum Number of Employees Reached\n");
				printf("\n");
			}
			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}



//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
