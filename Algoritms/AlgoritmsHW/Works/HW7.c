/*
 * HW7.c
 *
 *  Created on: 16 ���. 2019 �.
 *      Author: wolfm
 */

#include "Works.h"
#include <stdio.h>
#include <stdlib.h>

#define TCount 2


void HW7_Task1();
void HW7_Task2();

void HW7_main(){
	Task tasks[TCount] = {
				{
						.Number = 1,
						.ToDo = "Write a graph traversal function in depth.",
						.func = HW7_Task1
				},
				{
						.Number = 2,
						.ToDo = "Write a recursive graph traversal function in width.",
						.func = HW7_Task2
				}
		};

	TaskMenu(tasks,TCount);
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  Write a graph traversal function in depth.
 *  �������� ������� ������ ����� � �������.
*/
void HW7_Task1(){

}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  Write a recursive graph traversal function in width.
 *  �������� ����������� ������� ������ ����� � ������.
*/
void HW7_Task2(){

}
