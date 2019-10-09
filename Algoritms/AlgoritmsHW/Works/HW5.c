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
#define T char

typedef struct Node{
	T data;
	struct Node *next;
}Node;

typedef struct{
	Node *head;
	int size;
}List;

void initList(List *list){
	list->head = NULL;
	list->size = 0;
}


boolean push(List *lt, T value) {
  Node *temp = (Node*) malloc(sizeof(Node));
  if (temp == NULL)
	return false;

  temp->data = value;
  temp->next = lt->head;

  lt->head = temp;
  lt->size++;
  return true;
}

T pop(List *lt) {
  if (lt->size == 0) {
	return -1;
  }

  Node *temp = lt->head;
  T result = lt->head->data;

  lt->head = lt->head->next;
  lt->size--;
  free(temp);
  return result;
}

List copyList(List *list){
	List result;
	initList(&result);

	int size = list->size;
	Node *temp;
	temp = list->head;
	//Take data
	T *arr = malloc(size*sizeof(*arr));
	for (int i = 0; i < size; ++i) {
		*(arr+i) = temp->data;
		temp = temp->next;
	}
	//Turn data array
	for (int j = size-1; j >= 0; j--) {
		push(&result, *(arr+j));
	}

	return result;
}

void readList(List *list){
	while (list->size > 0) {
		printf("%c ", pop(list));
	}
	printf("\n");
}


void HW5_Task2(){
	List ltbase;
	initList(&ltbase);

	push(&ltbase, 'a');
	push(&ltbase, 'r');
	push(&ltbase, 'f');
	push(&ltbase, 'g');
	push(&ltbase, 'V');

	List result;
	result = copyList(&ltbase);

	printf("Base:    ");
	readList(&ltbase);

	printf("Copied:  ");
	readList(&result);
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  3.
 *  * Implement a queue based on a doubly linked list.
*/
void HW5_Task3(){

}
