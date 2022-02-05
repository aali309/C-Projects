/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   
   1) Atif Hammud Ali          Aali309@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS

#include "file_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

void getAgeGroup(int age, char *ageGrp) {
   if (age >= 16 && age <= 20){
   strcpy(ageGrp, "Junior");
   }
   else if (age >= 21 && age <= 34){
   strcpy(ageGrp, "Adult");
   }
   if (age >= 35) {
   strcpy(ageGrp, "Senior");
   }
}

void getTime(float start, char *time) {
   char hr[5], min[5];
   int t = (int)round(start*60);
   int h = t/60;
   int m = t%60;
   sprintf(hr, "%d", h);
   if (m >= 0 && m <= 9) {
      strcpy(min, "0");
      char temp[2];
      sprintf(temp, "%d", m);
      strcat(min, temp);
   }
   else
      sprintf(min, "%d", m);
   strcat(hr, ":");
   strcat(hr, min);
   strcpy(time, hr);
}

void getCategory(char race, char *category) {
   if (race == 'S'){
   strcpy(category, "50 km");
   }
   else if (race == 'M'){
   strcpy(category, "75 km");
   }
   else{
   strcpy(category, "100 km");
   }
}

void getWithdraw(int withdraw, char *with) {
   if (withdraw == 0){
   strcpy(with, "No");
   }
   else{
   strcpy(with, "Yes");
   }
}

void copyInfo(struct RiderInfo *r1, struct RiderInfo *r2) {
   r1->age = r2->age;
   r1->finishTime = r2->finishTime;
   r1->mountainTime = r2->mountainTime;
   strcpy(r1->name, r2->name);
   r1->raceLength = r2->raceLength;
   r1->startTime = r2->startTime;
   r1->withdrawn = r2->withdrawn;
}

void sortElements(struct RiderInfo *r, int len) {
	for (int i = 0; i < len - 1; i++) {
      for (int j = 0; j < len - i - 1; j++) {
         if (r[j + 1].finishTime < r[j].finishTime) {
            struct RiderInfo temp;
            copyInfo(&temp, &r[j]);
            copyInfo(&r[j], &r[j + 1]);
            copyInfo(&r[j + 1], &temp);
         }
      }
   }
}





int main(void)
{
   FILE *fp;
   struct RiderInfo *info = (struct RiderInfo*)malloc(sizeof(struct RiderInfo));
   int c = 0, loop = 1;

	// TODO: Code the necessary logic for your solution below
	//
	// NOTE: Use modularity whenever possible in your design
	//
	// HINTS:
	// 1) You will need to load the file data and store
	//    it to a data structure array 
	//    (MUST USE: provided "readFileRecord" function)
   fp = fopen("data.txt", "r");
   while (!feof(fp)) {
      readFileRecord(fp, &info[c++]);
      info = (struct RiderInfo*)realloc(info, sizeof(struct RiderInfo) * (c+1));
   }
      printf("\n******************** Seneca Cycling Race Results ********************\n");

   while(loop) {
      int option;
      char input;
      float rider1, rider2, rider3;
      struct RiderInfo r1, r2, r3;

    
      // 2) Create a menu system to provide the user with the reporting options
      printf("What would you like to do?\n");
      printf("0 – Exit\n");
      printf("1 – Print top 3 riders in a category\n");
      printf("2 – Print all riders in a category\n");
      printf("3 – Print last 3 riders in a category\n");
      printf("4 – Print winners in all categories\n");
      printf(": ");
      scanf("%d", &option);

      
   
   

      // 3) Generate the user-selected report
      switch (option) {
         case 0:
         {
            printf("\nKeep on Riding!\n");
            loop = 0;
            break;
         }

         case 1:
         {
            printf("\nWhich category (S, M, L): ");
            while(getchar() != '\n');
            input = getchar();
            
            if (input == 's'){
             input = 'S';
            }
            else if (input == 'm'){
             input = 'M';
            }
            else if (input == 'l'){
             input = 'L';
            }
            if (input!='S'&&input!='M'&&input!='L')
            {
            	printf("\nERROR!!! Invalid entry.\n");
            	break;            
            }
            

            rider1 = 1.0f * INT_MAX, rider2 = 1.0f * INT_MAX,rider3 =  1.0f * INT_MAX;

            for (int i = 0; i < c; i++) {
               if (!info[i].withdrawn && info[i].raceLength == input) {
                  if (info[i].finishTime < rider1) {
                     rider3 = rider2;
                     rider2 = rider1; 
                     rider1 = info[i].finishTime;
                     r3 = r2;
                     r2 = r1;
                     r1 = info[i];
                  }
                  else if (info[i].finishTime < rider2) {
                     rider3 = rider2;
                     rider2 = info[i].finishTime;
                     r3 = r2;
                     r2 = info[i];
                  }
                  else if (info[i].finishTime < rider3) {
                     rider3 = info[i].finishTime;
                     r3 = info[i];
                  }
               }
            }
            
            printf("\nRider\t\t\t\t\t\t\t       Age Group Time\n");
            for (int i = 0; i < 39; i++) printf("- ");
            printf("\n");

            if (rider1 == INT_MAX) {
               printf("NOT AWARDED\n");
            }
            else {
               char age[10], time[10];
               getAgeGroup(r1.age, age);
               getTime(r1.finishTime - r1.startTime, time);
               printf("%-40s\t\t\t %-8s%-8s\n", r1.name, age, time);
            }
            
            if (rider2 == INT_MAX) {
               printf("NOT AWARDED\n");
            }
            else {
               char age[10], time[10];
               getAgeGroup(r2.age, age); 
               getTime(r2.finishTime - r2.startTime, time);
               printf("%-40s\t\t\t %-8s%-8s\n", r2.name, age, time);
            }            
            
            if (rider3 == INT_MAX) {
               printf("NOT AWARDED\n");
            }
            else {
               char age[10], time[10];
               getAgeGroup(r3.age, age); 
               getTime(r3.finishTime - r3.startTime, time);
               printf("%-40s\t\t\t %-8s%-8s\n", r3.name, age, time);
            }
             break;
         }

         case 2:
         {
            printf("\nWhich category (S, M, L): ");
            while(getchar() != '\n');
            input = getchar();
            if (input == 's'){
             input = 'S';
            }
            else if (input == 'm'){
             input = 'M';
            }
            else if (input == 'l'){
             input = 'L';
            }
            if (input!='S'&&input!='M'&&input!='L')
            {
            	printf("\nERROR!!! Invalid entry.\n");
            	break;            
            }
            

            struct RiderInfo *arr = (struct RiderInfo *)malloc(sizeof(struct RiderInfo));
            int len = 0;

            for (int i = 0; i < c; i++) {
               if (info[i].raceLength == input) {
                  copyInfo(&arr[len++], &info[i]);
                  arr = (struct RiderInfo *)realloc(arr, sizeof(struct RiderInfo) * (len + 1));
               }
            }

            sortElements(arr, len);

            printf("\nRider\t\t\t\t\t\t\t\t       Age Group Time Withdrawn\n");
            for (int i = 0; i < 48; i++) printf("- ");
            printf("\n");
  
            for (int i = 0; i < len; i++) {
               char age[10], time[10], withdraw[10];
               getAgeGroup(arr[i].age, age); 
               getWithdraw(arr[i].withdrawn, withdraw);
               if (strcmp(withdraw, "Yes") == 0) 
                  strcpy(time, "N/A");
               else{
                  getTime(arr[i].finishTime - arr[i].startTime, time);
                  printf("%-40s \t\t\t\t%-8s %-6s      %s\n", arr[i].name, age, time, withdraw);
               }
            }

            for (int i = 0; i < len; i++) {
               char age[10], time[10], withdraw[10];
               getAgeGroup(arr[i].age, age); 
               getWithdraw(arr[i].withdrawn, withdraw);
               if (strcmp(withdraw, "Yes") == 0) {
                  strcpy(time, "N/A");
                  printf("%-40s \t\t\t\t%-8s  %-6s    %s\n", arr[i].name, age, time, withdraw);
               }
               
            }

            break;
         }

         case 3:
         {
            printf("\nWhich category (S, M, L): ");
            while(getchar() != '\n');
            input = getchar();
            if (input == 's'){
             input = 'S';
            }
            else if (input == 'm'){
             input = 'M';
            }
            else if (input == 'l') {
             input = 'L';
            }
            if (input!='S'&&input!='M'&&input!='L')
            {
            	printf("\nERROR!!! Invalid entry.\n");
            	break;            
            }
            

            rider1 = 0.0f, rider2 = 0.0f, rider3 = 0.0f;

            for (int i = 0; i < c; i++) {
               if (!info[i].withdrawn && info[i].raceLength == input) {
                  if (info[i].finishTime > rider1) {
                     rider3 = rider2;
                     rider2 = rider1; 
                     rider1 = info[i].finishTime;
                     r3 = r2;
                     r2 = r1;
                     r1 = info[i];
                  }

                  else if (info[i].finishTime > rider2) {
                     rider3 = rider2;
                     rider2 = info[i].finishTime;
                     r3 = r2;
                     r2 = info[i];
                  }

                  else if (info[i].finishTime > rider3) {
                     rider3 = info[i].finishTime;
                     r3 = info[i];
                  }
               }
            }

            // print rider3 rider2 rider1
            printf("\nRider\t\t\t\t\t\t\t       Age Group Time\n");
            for (int i = 0; i < 39; i++) printf("- ");
            printf("\n");

            if (rider3 == INT_MAX) {
               printf("NOT AWARDED\n");
            }
            else {
               char age[10], time[10];
               getAgeGroup(r3.age, age);
               getTime(r3.startTime, time);
               getTime(r3.finishTime - r3.startTime, time);
               printf("%-40s \t\t\t %-8s%-8s\n", r3.name, age, time);
            }
            
            if (rider2 == INT_MAX) {
               printf("NOT AWARDED\n");
            }
            else {
               char age[10], time[10];
               getAgeGroup(r2.age, age);
               getTime(r2.finishTime - r2.startTime, time); 
               printf("%-40s \t\t\t %-8s%-8s\n", r2.name, age, time);
            }            
            
            if (rider1 == INT_MAX) {
               printf("NOT AWARDED\n");
            }
            else {
               char age[10], time[10];
               getAgeGroup(r1.age, age); 
               getTime(r1.finishTime - r1.startTime, time);
               printf("%-40s \t\t\t %-8s%-8s\n", r1.name, age, time);
            }
            break;
         }

         case 4:
         {

            float small, med, large;
            small = 1.0f * INT_MAX, med = 1.0f * INT_MAX, large = 1.0f * INT_MAX;
            struct RiderInfo r1, r2, r3;

            for (int i = 0; i < c; i++) {
               if (!info[i].withdrawn) {
                  if (info[i].raceLength == 'S' && info[i].finishTime < small) {
                     small = info[i].finishTime;
                     r1 = info[i];
                  }

                  else if (info[i].raceLength == 'M' && info[i].finishTime < med) {
                     med = info[i].finishTime;
                     r2 = info[i];
                  }

                  else if (info[i].raceLength == 'L' && info[i].finishTime < large) {
                     large = info[i].finishTime;
                     r3 = info[i];
                  }
               }
            }

            // print r1, r2, r3
            printf("\nRider\t\t\t\t\t\t\t\t\tAge Group Category Time\n");
            for (int i = 0; i < 48; i++) printf("- ");
            printf("\n");
            
            if (small == INT_MAX) {
               printf("NOT AWARDED\n");
            }
            else {
               char age[10], time[10], category[10];
               getAgeGroup(r1.age, age);
               getTime(r1.finishTime - r1.startTime, time);
               getCategory(r1.raceLength, category);
               printf("%-40s \t\t\t\t  %-8s %-8s%s\n", r1.name, age, category, time);
            }
            
            if (med == INT_MAX) {
               printf("NOT AWARDED\n");
            }
            else {
               char age[10], time[10], category[10];
               getAgeGroup(r2.age, age); 
               getTime(r2.finishTime - r2.startTime, time);
               getCategory(r2.raceLength, category);
               printf("%-40s \t\t\t\t  %-8s %-8s%s\n", r2.name, age, category, time);
            }            
            
            if (large == INT_MAX) {
               printf("NOT AWARDED\n");
            }
            else {
               char age[10], time[10], category[10];
               getAgeGroup(r3.age, age); 
               getTime(r3.finishTime - r3.startTime, time);
               getCategory(r3.raceLength, category);
               printf("%-40s \t\t\t\t   %-8s%-8s%s\n", r3.name, age, category, time);
            }
            break;
         }
         
         default:
         {
            printf("\nERROR!!! Out of range, please choose an option from 1 to 4.\n");
            break;
         }
      }
      printf("\n");
   }


			
	return 0;
}
