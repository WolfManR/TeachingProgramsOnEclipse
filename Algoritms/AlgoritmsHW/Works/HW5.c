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
#define T char


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

//////////////////////////////////////////////////////////////////
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

typedef struct element{
	T data;
	struct element *next;
	struct element *prev;
}Element;

typedef struct{
	Element *front;
	Element *back;
	int size;
}Deque;

void initDeque(Deque *deq){
	deq->front = NULL;
	deq->back = NULL;
	deq->size = 0;
}

boolean pushBack(Deque *deq, T value){
	Element *temp = (Element*) malloc(sizeof(Element));
	if (temp == NULL)
		return false;
	//if(deq->back != NULL)
	//	deq->back->next = temp;

	temp->data = value;
	temp->next = NULL;
	if(deq->back == NULL && deq->front == NULL){
			free(deq->front);
			deq->front = temp;
			temp->prev = NULL;
		}
	else
		temp->prev = deq->back;

	deq->back = temp;
	deq->size++;
	return true;
}

boolean pushFront(Deque *deq, T value){
	Element *temp = (Element*) malloc(sizeof(Element));
	if (temp == NULL)
		return false;
	//if(deq->front != NULL)
	//	deq->front->next = temp;

	temp->data = value;
	temp->prev = NULL;
	if(deq->back == NULL && deq->front == NULL){
		free(deq->back);
		deq->back = temp;
		temp->next = NULL;
	}
	else
		temp->next = deq->front;

	deq->front = temp;
	deq->size++;
	return true;
}

T popBack(Deque *deq){
	if (deq->size == 0) {
		return -1;
	}

	Element *temp = deq->back;
	T result = deq->back->data;

	deq->back = deq->back->prev;
	deq->size--;
	free(temp);
	return result;
}

T popFront(Deque *deq){
	if (deq->size == 0) {
		return -1;
	}

	Element *temp = deq->front;
	T result = deq->front->data;

	deq->front = deq->front->next;
	deq->size--;
	free(temp);
	return result;
}

void readDeqFromBack(Deque *deq){
	while (deq->size > 0) {
		printf("%c ", popBack(deq));
	}
	printf("\n");
}

void readDeqFromFront(Deque *deq){
	while (deq->size > 0) {
		printf("%c ", popFront(deq));
	}
	printf("\n");
}

void HW5_Task3(){
	Deque deq;
	initDeque(&deq);

	pushBack(&deq, 'T');
	pushBack(&deq, 'f');
	pushBack(&deq, 'B');
	pushBack(&deq, 'd');
	pushBack(&deq, 'c');
	printf("size: %d\n", deq.size);
	readDeqFromBack(&deq);
}
