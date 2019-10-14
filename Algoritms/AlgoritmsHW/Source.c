/*
 * Source.c
 *
 *  Created on: 24 ЯЕМР. 2019 Ц.
 *      Author: Ivan Barmin
 *
 *
 */

#include <stdio.h>
#include <string.h>

#define HWCount 6

typedef struct{
	char Theme[256];
	void (*func)();
}HW;

void HWMenu();

void HW1_main();
void HW2_main();
void HW3_main();
void HW4_main();
void HW5_main();
void HW6_main();

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	HW homeWorks[HWCount] ={
		{.Theme = "Simple algorithms", .func = HW1_main},
		{.Theme = "Asymptotic complexity of the algorithm. Recursion", .func = HW2_main},
		{.Theme = "Search in an array. Simple sorting", .func = HW3_main},
		{.Theme = "Dynamic programming. Return Search", .func = HW4_main},
		{.Theme = "Dynamic data structures	дг ме гюбепьемн", .func = HW5_main},
		{.Theme = "Trees", .func = HW6_main}
	};

	HWMenu(homeWorks,HWCount);

	int userInput=0;
	printf("Enter the HW command: ");
	scanf("%d",&userInput);
	puts("/////////////////////////////////////////////////////");
	if(userInput >= 0 && userInput < HWCount)
		homeWorks[userInput].func();
	else if(userInput == -1)
		printf("Goodbye!");
	else
		printf("Something went wrong\n");
}

void HWMenu(HW* array, int arrLength){
	for(int i = 0; i < arrLength; i++){
		printf("COMMAND: %d		HW Number: %d\n  Theme: %s\n\n",i,i+1, (array+i)->Theme);
	}
	printf("Exit command: -1\n");
}

