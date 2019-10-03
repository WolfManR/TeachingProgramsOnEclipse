/*
 * HW2.c
 *
 *  Created on: 29 ����. 2019 �.
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
						.ToDo = "����������� ������� �������� �� 10 ������� � �������� ��������� ��������.",
						.func = HW2_Task1
				},
				{
						.Number = 2,
						.ToDo = "����������� ������� ���������� ����� a � ������� b:\n a. ��� ��������;\n b. ����������;\n c. *����������, ��������� �������� �������� �������.",
						.func = HW2_Task2
				},
				{
						.Number = 3,
						.ToDo = "����������� ����������� ����������� ����� �����, ���������� �� ������. \n� ����������� ��� �������, ������ ������� �������� �����:\n 1.������� 1 - ����������� ����� �� ������ �� 1 \n 2.������ �� 2 - ����������� ����� � 2 ����. \n������� ���������� ��������, ������� ����� 3 ����������� � ����� 20?\n �) � �������������� �������;\n �) � �������������� ��������.",
						.func = HW2_Task3
				}
		};

	TaskMenu(tasks,TCount);

	int userInput=0;
	printf("������� ������� ������: ");
	scanf("%d",&userInput);

	PlayTask(userInput, TCount, tasks);
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  ����������� ������� �������� �� 10 ������� � �������� ��������� ��������.
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
	printf("������� ����� ���������� ������� ���������:\n");
	scanf("%d",&input);

	char out[64]="";
	binary(input, out);
	printf("%s", out);
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  ����������� ������� ���������� ����� a � ������� b:
 *   a. ��� ��������;
 *   b. ����������;
 *   c. *����������, ��������� �������� �������� �������.
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

	printf("������� ����� ");
	scanf("%d",&a);
	printf("������� ������������� �������� ������� ");
	scanf("%d",&b);

	printf("��� �������� %li",power(a,b));
	printf("\n\n� ��������� %li",power2(a,b));
	printf("\n\n���������� ���������� � ������� %li",quickPow(1,a,b));
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  3.
 *  ����������� ����������� ����������� ����� �����, ���������� �� ������.
 *  � ����������� ��� �������, ������ ������� �������� �����:
 *    1. ������� 1 - ����������� ����� �� ������ �� 1
 *    2. ������ �� 2 - ����������� ����� � 2 ����
 *  ������� ���������� ��������, ������� ����� 3 ����������� � ����� 20?
 *    �) � �������������� �������;
 *    �) � �������������� ��������.
*/

void ways(int number, int max, int* result){
	if(number==max) (*result)++;
	else if(number<max && (number+1<max || number*2<max)){
		ways(number+1, max, result);
		ways(number*2, max, result);
	}
}
/// ����� ����������� ������ ������� ������� ����������� � �������� ��
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
	printf("����������� ��������: %d", programs);
	printf("\n����������� ��������: %d", calc(num,max));
}
