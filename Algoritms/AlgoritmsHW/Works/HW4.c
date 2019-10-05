/*
 * HW4.c
 *
 *  Created on: 5 окт. 2019 г.
 *      Author: wolfm
 */

#include "Works.h"
#include <stdio.h>

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
void HW4_Task1(){

}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  *** It is required to go around the horse with a NxM-sized chessboard, passing through all the board fields once.
*/
void HW4_Task2(){

}
