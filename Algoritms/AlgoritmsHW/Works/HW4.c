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
#define QUEENS 8
#define X 8
#define Y 8
int board[Y][X];

void annull() {
  int i;
  int j;
  for (i = 0; i < Y; i++) {
	for (j = 0; j < X; j++) {
	  board[i][j] = 0;
	}
  }
}

void printBoard() {
  int i;
  int j;
  for (i = 0; i < Y; i++) {
	for (j = 0; j < X; j++) {
	  printf("%3d", board[i][j]);
	}
	printf("\n");
  }
}

int checkQueen(int x, int y) {
  int i;
  int j;
  for (i = 0; i < Y; i++) {
	for (j = 0; j < X; j++) {
	  if (board[i][j] != 0)
		if (!(i == x && j == y)) {
		  if (i - x == 0 || j - y == 0)
			return 0;
		  if (abs(i - x) == abs(j - y))
			return 0;
		}
	}
  }
  return 1;
}

int checkBoard() {
  int i;
  int j;
  for (i = 0; i < Y; i++) {
	for (j = 0; j < X; j++) {
	  if (board[i][j] != 0)
		if (checkQueen(i, j) == 0)
		  return 0;
	}
  }
  return 1;
}

int operations = 0;
int queens(int n) {
  if (checkBoard() == 0) return 0;
  if (n == QUEENS + 1) return 1;
  int row;
  int col;
  for (row = 0; row < Y; row++) {
	for (col = 0; col < X; col++) {
	  operations++;
	  if (board[row][col] == 0) {
		board[row][col] = n;
		if (queens(n + 1))
		  return 1;
		board[row][col] = 0;
	  }
	}
  }
  return 0;
}

void HW4_Task2(){
	annull();
	queens(1);
	printBoard();
	printf("operations = %d\n", operations);
}
