/*
 * Works.h
 *
 *  Created on: 29 сент. 2019 г.
 *      Author: wolfm
 */

#ifndef WORKS_WORKS_H_
#define WORKS_WORKS_H_
#include <stdio.h>
typedef struct{
	char ToDo[400];
	int Number;
	void (*func)();
}Task;

void TaskMenu(Task* array, int arrLength){
	for(int i = 0; i < arrLength; i++){
		printf("КОМАНДА: %d\n Номер задачи: %d\n Задание: \n%s\n\n",i ,(array + i)->Number, (array+i)->ToDo);
	}
	printf("Команда на выход: -1\n");
}

void PlayTask(int input, int TCount, Task* tasks){
	if(input >= 0 && input < TCount)
				tasks[input].func();
			else if(input == -1)
				printf("До свидания!");
			else
				printf("Что-то пошло не так\n");
}
#endif /* WORKS_WORKS_H_ */
