/*
 * Works.c
 *
 *  Created on: 29 ����. 2019 �.
 *      Author: wolfm
 */
#include "Works.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void TaskMenu(Task* array, int arrLength){
	for(int i = 0; i < arrLength; i++){
		printf("COMMAND: %d 		Task �: %d\n The task: \n%s\n\n",i ,(array + i)->Number, (array+i)->ToDo);
		printf("***********************************************************************************************\n");
	}
	printf("Exit command: -1\n");

	int userInput=0;
	printf("Enter the task command: ");
	scanf("%d",&userInput);

	PlayTask(userInput, arrLength, array);
}

void PlayTask(int input, int TCount, Task* tasks){
	if(input >= 0 && input < TCount)
		tasks[input].func();
	else if(input == -1)
		printf("Goodbye!");
	else
		printf("Something went wrong\n");
}


///// Array Help From Lessons
void fillArray(int* arr, int len) {
	srand(time(NULL));
  int i;
  for (i = 0; i < len; i++) {
	arr[i] = rand() % 100;
  }
}

void printIntArray(int* arr, int len) {
  int i;
  for (i = 0; i < len; i++) {
	printf("%d ", arr[i]);
  }
  printf("\n");
}

void printCharArray(char* arr, int len) {
  for (int i = 0; i < len; i++) {
	printf("%c ", arr[i]);
  }
  printf("\n");
}

void copyArray(int* arrFrom, int* arrTo, int len) {
	int i;
	for (i = 0; i < len; i++)
		arrTo[i] = arrFrom[i];
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
