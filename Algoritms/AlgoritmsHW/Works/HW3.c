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
		for (int j = 0; j < len - 1; j++) {
			operations++;
			if (arr[j] > arr[j + 1]){
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}

	return operations;
}

int bubbleSort2(int* arr, int len, void (*swap)()) {
	int operations = 0;

	for (int i = 0; i < len; i++) {
		int changed = 0;
		for (int j = 0; j < len - 1; j++) {
			operations++;
			if (arr[j] > arr[j + 1]){
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
		int flag = i;
		for (int j = i + 1; j < len; j++) {
			operations++;
			if (arr[j] < arr[flag]){
				flag = j;
			}
		}
		swap(&arr[i], &arr[flag]);
	}

  return operations;
}

int insertSort(int* arr, int len, void (*swap)()){
	int operations = 0;
	
	for (int i = 0; i < len; i++)
	    {
	        int temp = arr[i];
	        int j = i;
	        while (j > 0 && arr[j - 1] > temp)
	        {            
	        	operations++;
	            swap(&arr[j], &arr[j - 1]);
	            j--;
	        }
	    }
	
	return operations;
}

int cocktailSort(int* arr, int len, void (*swap)() );

void HW3_Task1(){
	int Size= 20;
	int arr1[Size];
	int arr2[Size];
	int arr3[Size];
	int arr4[Size];
	int arr5[Size];

	fillArray(arr1,Size);
	copyArray(arr1,arr2,Size);
	copyArray(arr1,arr3,Size);
	copyArray(arr1,arr4,Size);
	copyArray(arr1,arr5,Size);

	printf("Number of operations in different sorts\n");

	printf("\n%d	Bubble Sort (Basic)",bubbleSort(arr1, Size, swap));

	printf("\n%d	Bubble Sort (Optimized)",bubbleSort2(arr2, Size, swap));

	printf("\n%d	Sort by selection", pickSort(arr3, Size, swap));

	printf("\n%d	Insert Sort", insertSort(arr4, Size, swap));

	printf("\n%d	Cocktail Sort", cocktailSort(arr5, Size, swap));
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  Implement shaker sorting.
*/
int cocktailSort(int* arr, int len, void (*swap)() ){
	int operations = 0;

	int j=0;
	int k = 0;
	int min=0;
	int max=len-1;
    for (int i = 0; i < len-1; ++i) {

        if(i%2){
        	for (k = max; k > min; --k) {
        		operations++;
                if (arr[k] < arr[k - 1]){
                    swap(&arr[k], &arr[k - 1]);
                }
        	}
        	min=k+1;
        }
        else{
        	for (j = min; j < max; ++j) {
        		operations++;
        		if (arr[j] > arr[j + 1]){
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
int getMax(int* arr, int size) {
   if (size == 1) return arr[0];
   int r = arr[0];
   int i;
	for (i = 1; i < size; i++)
       if (r < arr[i])
           r = arr[i];
   return r;
}

int getMin(int* arr, int size) {
   if (size == 1) return arr[0];
   int r = arr[0];
   int i;
   for (i = 1; i < size; i++)
       if (r > arr[i])
           r = arr[i];
   return r;
}
/*
int pigeon(int* arr, int size) {
   int steps = 0;
   int min = getMin(arr, size);
   int max = getMax(arr, size);
   int length = max - min + 1;
   int freq[length] = {0};				//ошибка
   for (int i = 0; i < size; i++) {
   		steps++;
       freq[arr[i] - min]++;
   }

   int arrIndex = 0;
   for (int i = 0; i < length; i++)
       for (int elems = freq[i]; elems > 0; elems--) {
       		steps++;
           arr[arrIndex++] = i + min;
       }
   return steps;
}
*/
void HW3_Task3(){

}
