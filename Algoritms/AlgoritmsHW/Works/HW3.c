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
			operations++;
			if (arr[j] > arr[j + 1]){
				operations++;
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}

	return operations;
}

int bubbleSort2(int* arr, int len, void (*swap)()) {
	int operations = 0;

	for (int i = 0; i < len; i++) {
		operations++;
		int changed = 0;
		for (int j = 0; j < len - 1; j++) {
			operations++;
			if (arr[j] > arr[j + 1]){
				operations+=2;
				swap(&arr[j], &arr[j + 1]);
				changed = 1;
			}
		}
		if(changed == 0)
			break;
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

int insertSort(int* arr, int len, void (*swap)()){
	int operations = 0;
	
	for (int i = 0; i < len; i++)
	    {
			operations+=2;
	        int temp = arr[i];
	        int j = i;
	        while (j > 0 && arr[j - 1] > temp)
	        {            
	        	operations+=2;
	            swap(&arr[j], &arr[j - 1]);
	            j--;
	        }
	    }
	
	return operations;
}

int cocktailSort(int* arr, int len, void (*swap)() );

void HW3_Task1(){
	int Size= 20;
	int arr[Size];
	printf("Колличество операций разными сортировками\n");
	fillArray(arr,Size);
	printf("\n%d	Пузырьковая сортировка(базовая)",bubbleSort(arr, Size, swap));

	fillArray(arr,Size);
	printf("\n%d	Пузырьковая сортировка(оптимизированная)",bubbleSort2(arr, Size, swap));

	fillArray(arr,Size);
	printf("\n%d	Сортировка выборкой", pickSort(arr, Size, swap));

	fillArray(arr,Size);
	printf("\n%d	Сортировка вставкой", insertSort(arr, Size, swap));

	fillArray(arr,Size);
	printf("\n%d	Шейкерная сортировка", cocktailSort(arr, Size, swap));
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  Реализовать шейкерную сортировку.
*/
int cocktailSort(int* arr, int len, void (*swap)() ){
	int operations = 0;

	operations+=4;
	int j=0;
	int k = 0;
	int min=0;
	int max=len-1;
    for (int i = 0; i < len-1; ++i) {
        operations++;

        if(i%2){
        	for (k = max; k > min; --k) {
        		operations++;
                if (arr[k] < arr[k - 1]){
                	operations++;
                    swap(&arr[k], &arr[k - 1]);
                }
        	}
        	min=k+1;
        }
        else{
        	for (j = min; j < max; ++j) {
        		operations++;
        		if (arr[j] > arr[j + 1]){
        			operations++;
        			swap(&arr[j], &arr[j + 1]);
        		}
        	}
        	max=j-1;
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
 *  Погуглить как осуществляется Pigeon Hole Sort и попробовать реализовать на языке С.
*/
void HW3_Task3(){

}
