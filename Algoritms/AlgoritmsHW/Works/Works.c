/*
 * Works.c
 *
 *  Created on: 29 ����. 2019 �.
 *      Author: wolfm
 */
#include "Works.h"
#include <stdio.h>
#include <stdlib.h>



void TaskMenu(Task* array, int arrLength){
	for(int i = 0; i < arrLength; i++){
		printf("�������: %d 		����� ������: %d\n �������: \n%s\n\n",i ,(array + i)->Number, (array+i)->ToDo);
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


///// Array Help From Lessons
void fillArray(int* arr, int len) {
  int i;
  for (i = 0; i < len; i++) {
	arr[i] = rand() % 100;
  }
}

void printArray(int* arr, int len) {
  int i;
  for (i = 0; i < len; i++) {
	printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
