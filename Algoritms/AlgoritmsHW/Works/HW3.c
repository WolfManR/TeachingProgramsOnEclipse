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
						.ToDo = "Try optimize Bubble Sort. \nCompare the number of comparing operations between the optimized and non-optimized programs. \nWrite sorting functions that return the number of operations.",
						.func = HW3_Task1
				},
				{
						.Number = 2,
						.ToDo = "Implement shaker sorting.",
						.func = HW3_Task2
				},
				{
						.Number = 3,
						.ToDo = "Google how Pigeon Hole Sort is done and try to implement it in C.",
						.func = HW3_Task3
				}
		};

	TaskMenu(tasks,TCount);
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  Try optimize Bubble Sort.
 *  Compare the number of comparing operations between the optimized and non-optimized programs.
 *  Write sorting functions that return the number of operations.
*/
int bubbleSort(int* arr, int len, void (*swap)()) {
	int operations = 0;

	for (int i = 0; i < len; i++) {
		operations++;
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
		operations+=2;
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
			operations+=3;
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
	printf("Number of operations in different sorts\n");
	fillArray(arr,Size);
	printf("\n%d	Bubble Sort (Basic)",bubbleSort(arr, Size, swap));

	fillArray(arr,Size);
	printf("\n%d	Bubble Sort (Optimized)",bubbleSort2(arr, Size, swap));

	fillArray(arr,Size);
	printf("\n%d	Sort by selection", pickSort(arr, Size, swap));

	fillArray(arr,Size);
	printf("\n%d	Insert Sort", insertSort(arr, Size, swap));

	fillArray(arr,Size);
	printf("\n%d	Cocktail Sort", cocktailSort(arr, Size, swap));
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  Implement shaker sorting.
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
 *  Google how Pigeon Hole Sort is done and try to implement it in C.
*/
void HW3_Task3(){

}
