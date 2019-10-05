/*
 * Source.c
 *
 *  Created on: 24 сент. 2019 г.
 *      Author: Ivan Barmin
 *
 *
 */

#include <stdio.h>
#include <string.h>

#define HWCount 3

typedef struct{
	char Theme[256];
	void (*func)();
}HW;

void HWMenu();

void HW1_main();
void HW2_main();
void HW3_main();

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	HW homeWorks[HWCount] ={
		{.Theme = "Simple algorithms", .func = HW1_main},
		{.Theme = "Asymptotic complexity of the algorithm. Recursion", .func = HW2_main},
		{.Theme = "Search in an array. Simple sorting", .func = HW3_main}
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

