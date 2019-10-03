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
#define HWCount 2

typedef struct{
	char Theme[256];
	void (*func)();
}HW;

void HWMenu();

void HW1_main();
void HW2_main();

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	HW homeWorks[HWCount] ={
		{.Theme = "Простые алгоритмы", .func = HW1_main},
		{.Theme = "Асимптотическая сложность алгоритма. Рекурсия", .func = HW2_main}
	};

	HWMenu(homeWorks,HWCount);
	int userInput=0;
	printf("Введите номер ДЗ: ");
	scanf("%d",&userInput);
	puts("/////////////////////////////////////////////////////");
	if(userInput >= 0 && userInput < HWCount)
		homeWorks[userInput].func();
	else if(userInput == -1)
		printf("До свидания!");
	else
		printf("Что-то пошло не так\n");
}

void HWMenu(HW* array, int arrLength){
	for(int i = 0; i < arrLength; i++){
		printf("Номер ДЗ: %d\n  Тема: %s\n\n",i, (array+i)->Theme);
	}
	printf("Команда на выход: -1\n");
}

