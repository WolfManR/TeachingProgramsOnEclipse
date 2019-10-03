/*
 * Works.c
 *
 *  Created on: 29 ����. 2019 �.
 *      Author: wolfm
 */
#include "Works.h"
#include <stdio.h>



void TaskMenu(Task* array, int arrLength){
	for(int i = 0; i < arrLength; i++){
		printf("�������: %d\n ����� ������: %d\n �������: \n%s\n\n",i ,(array + i)->Number, (array+i)->ToDo);
	}
	printf("������� �� �����: -1\n");
}

void PlayTask(int input, int TCount, Task* tasks){
	if(input >= 0 && input < TCount)
				tasks[input].func();
			else if(input == -1)
				printf("�� ��������!");
			else
				printf("���-�� ����� �� ���\n");
}
