/*
 * HW3.c
 *
 *  Created on: 3 ���. 2019 �.
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
						.ToDo = "����������� �������������� ����������� ����������. \n�������� ���������� �������� ��������� ���������������� � �� ���������������� ���������. \n�������� ������� ����������, ������� ���������� ���������� ��������.",
						.func = HW3_Task1
				},
				{
						.Number = 2,
						.ToDo = "����������� ��������� ����������.",
						.func = HW3_Task2
				},
				{
						.Number = 3,
						.ToDo = "��������� ��� �������������� Pigeon Hole Sort � ����������� ����������� �� ����� �.",
						.func = HW3_Task3
				}
		};

	TaskMenu(tasks,TCount);

	int userInput=0;
	printf("������� ������� ������: ");
	scanf("%d",&userInput);

	PlayTask(userInput, TCount, tasks);
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  ����������� �������������� ����������� ����������.
 *  �������� ���������� �������� ��������� ���������������� � �� ���������������� ���������.
 *  �������� ������� ����������, ������� ���������� ���������� ��������.
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
 *  ����������� ��������� ����������.
*/
void HW3_Task2(){

}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  3. optional.
 *  ��������� ��� �������������� Pigeon Hole Sort � ����������� ����������� �� ����� �.
*/
void HW3_Task3(){

}
