/*
 * HW3.c
 *
 *  Created on: 3 окт. 2019 г.
 *      Author: wolfm
 */


#include "Works.h"
#include <stdio.h>

#define TCount 3

void HW3_Task1();
void HW3_Task2();
void HW3_Task3();

void HW3_main(){
	Task tasks[TCount] = {
				{
						.Number = 1,
						.ToDo = "Попробовать оптимизировать пузырьковую сортировку. \nСравнить количество операций сравнения оптимизированной и не оптимизированной программы. \nНаписать функции сортировки, которые возвращают количество операций.",
						.func = HW3_Task1
				},
				{
						.Number = 2,
						.ToDo = "Реализовать шейкерную сортировку.",
						.func = HW3_Task2
				},
				{
						.Number = 3,
						.ToDo = "Погуглить как осуществляется Pigeon Hole Sort и попробовать реализовать на языке С.",
						.func = HW3_Task3
				}
		};

	TaskMenu(tasks,TCount);

	int userInput=0;
	printf("Введите команду задачи: ");
	scanf("%d",&userInput);

	PlayTask(userInput, TCount, tasks);
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  Попробовать оптимизировать пузырьковую сортировку.
 *  Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
 *  Написать функции сортировки, которые возвращают количество операций.
*/
int bubbleSort(int* arr, int len, void (*swap)()) {
	int operations = 0;
  for (int i = 0; i < len; i++) {
	for (int j = 0; j < len - 1; j++) {
	  if (arr[j] > arr[j + 1])
		swap(&arr[j], &arr[j + 1]);
	  operations++;
	}
  }
  return operations;
}

int pickSort(int* arr, int len, void (*swap)()) {
	int operations = 0;
  for (int i = 0; i < len; i++) {
	int flag = i;
	operations++;
	for (int j = i + 1; j < len; j++) {
	  if (arr[j] < arr[flag])
		flag = j;
	  operations++;
	}
	swap(&arr[i], &arr[flag]);
	operations++;
  }
  return operations;
}

void HW3_Task1(){
	int Size= 20;
 int arr[Size];
 fillArray(arr,Size);
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  Реализовать шейкерную сортировку.
*/
void HW3_Task2(){

}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  3. optional.
 *  Погуглить как осуществляется Pigeon Hole Sort и попробовать реализовать на языке С.
*/
void HW3_Task3(){

}
