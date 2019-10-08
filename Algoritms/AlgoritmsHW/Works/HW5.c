/*
 * HW5.c
 *
 *  Created on: 8 окт. 2019 г.
 *      Author: wolfm
 */


#include "Works.h"
#include <stdio.h>
#include <stdlib.h>

#define TCount 3

void HW5_Task1();
void HW5_Task2();
void HW5_Task3();

void HW5_main(){
	Task tasks[TCount] = {
				{
						.Number = 1,
						.ToDo = "Write a program that determines whether the parenthesis sequence entered is correct.\n Examples of correct bracket expressions: (), ([]) (), {} (), ([{}]),\n incorrect -) (, ()) ({), (,])}), ([(] ) for the brackets [, (, {.\nFor example: (2+ (2 * 2)) or [2 / {5 * (4 + 7)}]",
						.func = HW5_Task1
				},
				{
						.Number = 2,
						.ToDo = "* Create a function that copies a simply connected list \n(that is, it creates a copy of a simply connected list in memory without deleting the first list).",
						.func = HW5_Task2
				},
				{
						.Number = 3,
						.ToDo = "* Implement a queue based on a doubly linked list.",
						.func = HW5_Task3
				}
		};

	TaskMenu(tasks,TCount);
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  Write a program that determines whether the parenthesis sequence entered is correct.
 *  	Examples of correct bracket expressions: (), ([]) (), {} (), ([{}]),
 *  	incorrect -) (, ()) ({), (,])}), ([(] ) for the brackets [, (, {.
 *  For example: (2+ (2 * 2)) or [2 / {5 * (4 + 7)}]
*/
void HW5_Task1(){

}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  * Create a function that copies a simply connected list
 *  (that is, it creates a copy of a simply connected list in memory without deleting the first list).
*/
void HW5_Task2(){

}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  3.
 *  * Implement a queue based on a doubly linked list.
*/
void HW5_Task3(){

}
