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
			operations++;
			if (arr[j] > arr[j + 1])
				operations++;
				swap(&arr[j], &arr[j + 1]);
		}
	}

	return operations;
}

int pickSort(int* arr, int len, void (*swap)()) {
	int operations = 0;

	for (int i = 0; i < len; i++) {
		operations++;
		int flag = i;
		for (int j = i + 1; j < len; j++) {
			operations++;
			if (arr[j] < arr[flag]){
				operations++;
				flag = j;
			}
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
int cocktailSort(int* arr, int len, void (*swap)() ){
	int operations = 0;

	for (int i = 0; i < len-1; ++i) {
		operations+=2;
		int j,k = 0;
		for (j = k; j < len-(i+1); ++j) {
			operations++;
			if (arr[j] > arr[j + 1]){
				operations++;
				swap(&arr[j], &arr[j + 1]);
			}
		}
		for (k = j-1; k > i; --k) {
			operations++;
			if (arr[k] > arr[k - 1]){
				operations++;
				swap(&arr[k], &arr[k - 1]);
			}
		}
	}

	return operations;
}

void HW3_Task2(){
	int Size= 20;
	int arr[Size];
	fillArray(arr,Size);

	printf("before: ");
	printArray(arr, Size);

	cocktailSort(arr, Size	, swap );
	printf("after:  ");
	printArray(arr,Size);
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  3. optional.
 *  ��������� ��� �������������� Pigeon Hole Sort � ����������� ����������� �� ����� �.
*/
void HW3_Task3(){

}
