/*
 * Works.h
 *
 *  Created on: 29 сент. 2019 г.
 *      Author: wolfm
 *
 *
 *      It's correct?
 */
typedef struct{
	char ToDo[400];
	int Number;
	void (*func)();
}Task;

typedef int boolean;
#define true 1
#define false 0

void TaskMenu(Task* array, int arrLength);

void PlayTask(int input, int TCount, Task* tasks);

void fillArray(int* arr, int len);
void printIntArray(int* arr, int len);
void printCharArray(char* arr, int len);
void copyArray(int* arrFrom, int* arrTo, int len);
void swap(int *a, int *b);
