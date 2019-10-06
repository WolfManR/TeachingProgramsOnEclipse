/*
 * HW4.c
 *
 *  Created on: 5 окт. 2019 г.
 *      Author: wolfm
 */

#include "Works.h"
#include <stdio.h>
#include <stdlib.h>

#define TCount 2

void HW4_Task1();
void HW4_Task2();

void HW4_main(){
	Task tasks[TCount] = {
				{
						.Number = 1,
						.ToDo = "* Number of routes with obstacles. Implement reading an array with an obstacle and finding the number of routes.",
						.func = HW4_Task1
				},
				{
						.Number = 2,
						.ToDo = "*** It is required to go around the horse with a NxM-sized chessboard, passing through all the board fields once.",
						.func = HW4_Task2
				}
		};

	TaskMenu(tasks,TCount);
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  * Number of routes with obstacles. Implement reading an array with an obstacle and finding the number of routes.
*/

#define wall 0

int routes(int x, int y) {
  if (x == 0 || y == 0) return 1;
  else return routes(x - 1, y) + routes(x, y - 1);
}

int routes2(int x, int y, int* arr, int cols) {
	if(*(arr+(y*cols+x)) == wall) return 0;
	else{
		if (x == 0 || y == 0) return 1;
		else return routes2(x - 1, y,arr,cols) + routes2(x, y - 1,arr,cols);
	}
}

void HW4_Task1(){

	printf("Setup Size of checkboard\n");
	int* field;
	int cols = 7;
	int rows = 7;
	printf("Enter Columns: ");
	scanf("%d",&cols);
	printf("Enter Rows: ");
	scanf("%d",&rows);

	field=malloc(rows*cols*sizeof(*field));
	for (int var = 0; var < rows*cols; ++var) {
		*(field+var)=1;
	}

	printf("Enter a number of blocks: ");
	int blockNums;
	scanf("%d",&blockNums);
	printf("Enter blocks of path (x is col, y is row)\n");

	for (int block = 0; block < blockNums; ++block) {
		int x;
		int y;
		printf("Enter x: ");
		scanf("%d",&x);
		printf("Enter y: ");
		scanf("%d",&y);
		*(field+((y-1)*cols+x-1))=wall;
		puts("");
	}

	/*    											//Print Default CheckBoard with Blocks
	for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				printf("%7d ", *(field+(i*cols+j)));
			}
			printf("\n");
	}
	puts("");
	*/

	for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				printf("%7d ", routes2(j,i,field,cols));
			}
			printf("\n");
	}
	puts("");

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%7d ", routes(i, j));
		}
		printf("\n");
	}

	free(field);
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  *** It is required to go around the horse with a NxM-sized chessboard, passing through all the board fields once.
*/
void HW4_Task2(){

}
