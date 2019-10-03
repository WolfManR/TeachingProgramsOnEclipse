/*
 * Works.h
 *
 *  Created on: 29 ����. 2019 �.
 *      Author: wolfm
 *
 *
 *      ��� ��������� �������?
 */
typedef struct{
	char ToDo[400];
	int Number;
	void (*func)();
}Task;

void TaskMenu(Task* array, int arrLength);

void PlayTask(int input, int TCount, Task* tasks);

void fillArray(int* arr, int len);
void printArray(int* arr, int len);
void swap(int *a, int *b);
