/*
 * HW6.c
 *
 *  Created on: 13 îêò. 2019 ã.
 *      Author: wolfm
 */


#include "Works.h"
#include <stdio.h>
#include <stdlib.h>

#define TCount 3


void HW6_Task1();
void HW6_Task2();
void HW6_Task3();

void HW6_main(){
	Task tasks[TCount] = {
				{
						.Number = 1,
						.ToDo = "Implement the simplest hash function. \nA line is fed to the input of the function, the sum of the character codes is the output.",
						.func = HW6_Task1
				},
				{
						.Number = 2,
						.ToDo = "Implement a binary search tree\n a) Add a tree walk in various ways;\n b) Implement a search in the binary search tree;",
						.func = HW6_Task2
				},
				{
						.Number = 3,
						.ToDo = "*** Develop a database of students from the two fields\n\t“Name”,\n\t“Age”,\n\t“Personnel number” \nin which to use all the knowledge gained in the lessons.\nRead data into a binary search tree. Search for any field in the database (age, weight)",
						.func = HW6_Task3
				}
		};

	TaskMenu(tasks,TCount);
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  Implement the simplest hash function.
 *  A line is fed to the input of the function, the sum of the character codes is the output.
*/
#define hSize 10

int GetHashCode(char *str){
	int i=0, result=0;
	while(*(str+i)!='\0'){
		result+=*(str+i);
		i++;
	}
	return result;
}

void HW6_Task1(){
	int arr[hSize];
	char *str[10] = {
			"Hello",
			"Its something",
			"Welcome",
			"Iteration",
			"Saturday",
			"Next",
			"Daughter",
			"Tomorrow",
			"Week",
			"Naught"
			};
	for (int i = 0; i < hSize; ++i) {
		arr[i] = GetHashCode(*(str+i));
	}
	printIntArray(arr, hSize);
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  Implement a binary search tree
 *   a) Add a tree walk in various ways;
 *   b) Implement a search in the binary search tree;
*/

typedef int T;
typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// Ðàñïå÷àòêà äâîè÷íîãî äåðåâà â âèäå ñêîáî÷íîé çàïèñè
void printTree(Node *root) {
    if (root)
    {
        printf("%d",root->data);
        if (root->left || root->right)
        {
        printf("(");

        if (root->left)
            printTree(root->left);
        else
            printf("NULL");
        printf(",");

        if (root->right)
            printTree(root->right);
        else
            printf("NULL");
        printf(")");
        }
    }
}

// Ñîçäàíèå íîâîãî óçëà
Node* getFreeNode(T value, Node *parent) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}
															/// wrong insert wrong solution, Make self
// Âñòàâêà óçëà
void insert(Node **head, int value) {
    Node *tmp = NULL;
    if (*head == NULL)
    {
        *head = getFreeNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp)
    {
        if (value> tmp->data)
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                continue;
            }
            else
            {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        }
        else if (value< tmp->data)
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                continue;
            }
            else
            {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        }
        else
        {
            exit(2);                     // Äåðåâî ïîñòðîåíî íåïðàâèëüíî
        }
    }
}

void preOrderTravers(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inOrderTravers(Node* root) {
    if (root) {
    	inOrderTravers(root->left);
        printf("%d ", root->data);
        inOrderTravers(root->right);
    }
}

void postOrderTravers(Node* root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d ", root->data);
    }
}

T searchInTree(Node* tree, T value){
	if(tree == NULL) return -1;
	if(tree->data == value){
		return tree->data;
	}
	else
		return (tree->data < value)? searchInTree(tree->left, value): searchInTree(tree->right,value);
}

void HW6_Task2(){
	Node *Tree = NULL;
	int arr[9] = { 1, 3, 4, 2, 5, 6, 9, 7, 8 };
	for (int k = 0; k < 9; ++k) {
		insert(&Tree, arr[k]);
	}
	printTree(Tree);
	printf("\nPreOrder:");
	preOrderTravers(Tree);
	puts("\nInOrder:");
	inOrderTravers(Tree);
	puts("\nPostOrder:");
	postOrderTravers(Tree);

	T search = 4;
	printf("\nsearch value: %d, is %s",search, (searchInTree(Tree, search) == search)?"finded":"dont finded");
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  3.
 *  *** Develop a database of students from the two fields
 *  	“Name”,
 *  	“Age”,
 *  	“Personnel number”
 *  in which to use all the knowledge gained in the lessons.
 *  Read data into a binary search tree. Search for any field in the database (age, weight)
*/

typedef struct{
	char FName[50];
	int Age;
}Person;

typedef struct{
	Person person;
	int personalNumber;
}Student;

void HW6_Task3(){

}
