/*
 * Source.c
 *
 *  Created on: 24 ����. 2019 �.
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
		{.Theme = "������� ���������", .func = HW1_main},
		{.Theme = "��������������� ��������� ���������. ��������", .func = HW2_main}
	};

	HWMenu(homeWorks,HWCount);
	int userInput=0;
	printf("������� ����� ��: ");
	scanf("%d",&userInput);
	puts("/////////////////////////////////////////////////////");
	if(userInput >= 0 && userInput < HWCount)
		homeWorks[userInput].func();
	else if(userInput == -1)
		printf("�� ��������!");
	else
		printf("���-�� ����� �� ���\n");
}

void HWMenu(HW* array, int arrLength){
	for(int i = 0; i < arrLength; i++){
		printf("����� ��: %d\n  ����: %s\n\n",i, (array+i)->Theme);
	}
	printf("������� �� �����: -1\n");
}

