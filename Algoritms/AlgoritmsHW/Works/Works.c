/*
 * Works.c
 *
 *  Created on: 29 сент. 2019 г.
 *      Author: wolfm
 */
#include "Works.h"
#include <stdio.h>
#include <stdlib.h>



void TaskMenu(Task* array, int arrLength){
	for(int i = 0; i < arrLength; i++){
		printf("КОМАНДА: %d 		Номер задачи: %d\n Задание: \n%s\n\n",i ,(array + i)->Number, (array+i)->ToDo);
	}
	printf("Команда на выход: -1\n");
}

void PlayTask(int input, int TCount, Task* tasks){
	if(input >= 0 && input < TCount)
				tasks[input].func();
			else if(input == -1)
				printf("До свидания!");
			else
				printf("Что-то пошло не так\n");
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
