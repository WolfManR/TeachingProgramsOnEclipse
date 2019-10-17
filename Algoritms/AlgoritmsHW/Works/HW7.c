/*
 * HW7.c
 *
 *  Created on: 16 окт. 2019 г.
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

//What hold all GraphNode's?

typedef struct DynamicArray{
	struct GraphNode* graphs;
	int size;
	int capacity;
}DynArray;

typedef struct GraphNode{
	int data;
	int used;
	DynArray *children;
}GraphNode;

void initDynArray(DynArray *arr){
	arr->size = 0;
	arr->graphs = calloc(1, sizeof(*arr->graphs));
	arr->capacity = 1;
}

void Expand(DynArray * arr){
	arr->graphs = realloc(arr->graphs, (arr->capacity * 2) * sizeof(*arr->graphs));
	if(arr->graphs != NULL) arr->capacity *= 2;
}

void Add(DynArray* arr, struct GraphNode *Node){
	if(arr->size < arr->capacity){
		arr->graphs[arr->size] = *Node;
		arr->size++;
	}
	else{
		Expand(arr);
		arr->graphs[arr->size] = *Node;
		arr->size++;
	}
}

typedef struct Node{
	GraphNode graph;
	struct Node *next;
}Node;

typedef struct Queue{
	Node *first;
	Node *last;
	int size;
}Queue;

void initQueue(Queue *que){
	que->first = NULL;
	que->last = NULL;
	que->size = 0;
}

void enqueue(Queue *que, GraphNode *graph){
	Node *temp = malloc(sizeof(*temp));
	temp->graph = *graph;
	if(que->last == NULL){
		que->first = que->last = temp;
	}
	else{
		que->last->next = temp;
		que->last = temp;
	}
}

GraphNode* dequeue(Queue *que){
	GraphNode *result = malloc(sizeof(*result));
	if(que->first != NULL){
		*result = que->first->graph;
		que->first = que->first->next;
		return result;
	}
	else{
		*result = que->last->graph;
		que->last = NULL;
		return result;
	}
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  Write a graph traversal function in depth.
 *  Написать функцию обхода графа в глубину.
*/
void HW7_Task1(){

}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  Write a recursive graph traversal function in width.
 *  Написать рекурсивную функцию обхода графа в ширину.
*/

int widthTravers(GraphNode *start, GraphNode *stop) {
	Queue *temp = malloc(sizeof(*temp));
	initQueue(temp);
  enqueue(temp, start);
  start->used = 1;
  while (temp->size != 0) {
	GraphNode *current = dequeue(temp);
	if (current->data == stop->data)
	  return 1;


	for (int i = 0; i < current->children->size; i++) {
		GraphNode tempNode = current->children->graphs[i];
	  if (tempNode.used != 1) {
		enqueue(temp, &tempNode);
		current->children->graphs[i].used = 1;
	  }
	}
  }
  return 0;
}

void HW7_Task2(){

}
