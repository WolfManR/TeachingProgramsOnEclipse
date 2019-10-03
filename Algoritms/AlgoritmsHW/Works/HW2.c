/*
 * HW2.c
 *
 *  Created on: 29 сент. 2019 г.
 *      Author: wolfm
 */
#include "Works.h"
#include <stdio.h>
#include <string.h>

#define TCount 3

void HW2_Task1();
void HW2_Task2();
void HW2_Task3();

void HW2_main(){
	Task tasks[TCount] = {
				{
						.Number = 1,
						.ToDo = "Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.",
						.func = HW2_Task1
				},
				{
						.Number = 2,
						.ToDo = "Реализовать функцию возведения числа a в степень b:\n a. без рекурсии;\n b. рекурсивно;\n c. *рекурсивно, используя свойство чётности степени.",
						.func = HW2_Task2
				},
				{
						.Number = 3,
						.ToDo = "Исполнитель Калькулятор преобразует целое число, записанное на экране. \nУ исполнителя две команды, каждой команде присвоен номер:\n 1.Прибавь 1 - увеличивает число на экране на 1 \n 2.Умножь на 2 - увеличивает число в 2 раза. \nСколько существует программ, которые число 3 преобразуют в число 20?\n а) с использованием массива;\n б) с использованием рекурсии.",
						.func = HW2_Task3
				}
		};

	TaskMenu(tasks,TCount);

	int userInput=0;
	printf("Введите команду задачи: ");
	scanf("%d",&userInput);

	PlayTask(userInput, TCount, tasks);
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
*/
void binary(int n, char* b) {
    if (n>0)					//if(n)
        binary(n / 2, b);
    else
    	return;
    strcat(b, (n % 2) ? "1" : "0");
    return;
}

void HW2_Task1(){
	int input;
	printf("Введите число десятичной системы счисления:\n");
	scanf("%d",&input);

	char out[64]="";
	binary(input, out);
	printf("%s", out);
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  Реализовать функцию возведения числа a в степень b:
 *   a. без рекурсии;
 *   b. рекурсивно;
 *   c. *рекурсивно, используя свойство чётности степени.
*/
long power(int a, int b)
{
   long p = 1;
   while(b)
   {
       p *= a;
       b--;
   }
   return p;
}

long power2(int a, int b){
	if(b==0) return 1;
	else return a*power2(a,--b);
}

long quickPow(long n,int a, int b) {
    if (b!=0) {
        if (b % 2!=0) return quickPow(n*a,a,--b);
        else return quickPow(n, a*a, b/2);
    }
    else return n;
}


void HW2_Task2(){
	int a,b;

	printf("Введите число ");
	scanf("%d",&a);
	printf("Введите положительное значение степени ");
	scanf("%d",&b);

	printf("без рекурсии %li",power(a,b));
	printf("\n\nс рекурсией %li",power2(a,b));
	printf("\n\nускоренное возведение в степень %li",quickPow(1,a,b));
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  3.
 *  Исполнитель Калькулятор преобразует целое число, записанное на экране.
 *  У исполнителя две команды, каждой команде присвоен номер:
 *    1. Прибавь 1 - увеличивает число на экране на 1
 *    2. Умножь на 2 - увеличивает число в 2 раза
 *  Сколько существует программ, которые число 3 преобразуют в число 20?
 *    а) с использованием массива;
 *    б) с использованием рекурсии.
*/

void ways(int number, int max, int* result){
	if(number==max) (*result)++;
	else if(number<max && (number+1<max || number*2<max)){
		ways(number+1, max, result);
		ways(number*2, max, result);
	}
}
/// Позже разобраться почему верхнее считает неправильно и доделать дз
int calc(int from, int to) {
	if (from < to)
		return calc(from + 1, to) + calc(from * 2, to);
	else if (from == to)
		return 1;
	else
		return 0;
}
void ways2(int number, int max, int* result, int* arr, int arrLength){

}

void HW2_Task3(){
	int num = 3, max = 20, programs = 0;


	ways(num, max, &programs);
	printf("Колличество программ: %d", programs);
	printf("\nКолличество программ: %d", calc(num,max));
}
