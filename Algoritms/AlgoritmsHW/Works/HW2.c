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
						.ToDo = "Implement the function of translation from 10 systems to binary using recursion.",
						.func = HW2_Task1
				},
				{
						.Number = 2,
						.ToDo = "Implement the function of raising the number a to the power of b:\n a. no recursion;\n b. recursively;\n c. * recursively using the property of degree parity.",
						.func = HW2_Task2
				},
				{
						.Number = 3,
						.ToDo = "Contractor Calculator converts an integer written on the screen. \nThe performer has two teams, each team is assigned a number:\n 1.Apply 1 - increases the number on the screen by 1 \n 2. Multiply by 2 - increases the number by 2 times. \nHow many programs exist that convert the number 3 to the number 20?\n a) using an array;\n b) using recursion.",
						.func = HW2_Task3
				}
		};

	TaskMenu(tasks,TCount);
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  Implement the function of translation from 10 systems to binary using recursion.
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
	printf("Enter the number of decimal number system:\n");
	scanf("%d",&input);

	char out[64]="";
	binary(input, out);
	printf("%s", out);
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  2.
 *  Implement the function of raising the number a to the power of b:
 *   a. no recursion;
 *   b. recursively;
 *   c. * recursively using the property of degree parity.
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

	printf("Insert the number ");
	scanf("%d",&a);
	printf("Enter a positive degree value ");
	scanf("%d",&b);

	printf("no recursion %li",power(a,b));
	printf("\n\nwith recursion %li",power2(a,b));
	printf("\n\naccelerated exponentiation %li",quickPow(1,a,b));
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  3.
 *  Contractor Calculator converts an integer written on the screen.
 *  The performer has two teams, each team is assigned a number:
 *    1.Apply 1 - increases the number on the screen by 1
 *    2. Multiply by 2 - increases the number by 2 times.
 *  How many programs exist that convert the number 3 to the number 20?
 *    a) using an array;
 *    b) using recursion.
*/

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
	int num = 3, max = 20;



	printf("\nNumber of programs: %d", calc(num,max));
}
