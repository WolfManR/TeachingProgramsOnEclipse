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

#define wall 1

int routes(int x, int y) {
  if (x == 0 || y == 0) return 1;
  else return routes(x - 1, y) + routes(x, y - 1);
}

void HW4_Task1(){
	printf("Setup Size of checkboard");
	int* field;
	int cols;
	printf("Enters Columns: ");
	scanf("%d",&cols);
	int rows;
	printf("\nEnters Rows: ");
	scanf("%d",&rows);
	field=malloc(rows*cols*sizeof(*field));

	for (int var = 0; var < rows*cols; ++var) {
		*(field+var)=0;
	}

	printf("Enter a number of blocks: ");
	int blockNums;
	scanf("%d",&blockNums);
	printf("Enter blocks of path (x is col, y is row)");

	for (int block = 0; block < blockNums; ++block) {
		int x;
		int y;
		printf("\nEnter x: ");
		scanf("%d",&x);
		printf("Enter y: ");
		scanf("%d",&y);
		*(field+((y-1)*cols+x-1))=wall;
	}

	for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				printf("%7d ", *(field+(i*cols+j)));
			}
			printf("\n");
		}
	puts("");
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
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
