/*
 * HW1Source.c
 *
 *  Created on: 25 сент. 2019 г.
 *      Author: Ivan Barmin
 */
#include "Works.h"
#include <stdio.h>
#include <math.h>

#define TCount 8

void HW1_Task1();
void HW1_Task3();
void HW1_Task4();
void HW1_Task6();
void HW1_Task7();
void HW1_Task9();
void HW1_Task10();
void HW1_Task14();

void HW1_main(){
	Task tasks[TCount] = {
			{
					.Number = 1,
					.ToDo = "Enter the weight and height of the person. Calculate and derive a body mass index by the formula I=m/(h*h);\n where m is the body weight in kilograms, h is the height in meters.",
					.func = HW1_Task1
			},
			{
					.Number = 3,
					.ToDo = "Write a program for exchanging the values of two integer variables:\n	b. * without using a third variable.",
					.func = HW1_Task3
			},
			{
					.Number = 4,
					.ToDo = "Write a program for finding the roots of a given quadratic equation.",
					.func = HW1_Task4
			},
			{
					.Number = 6,
					.ToDo = "Enter the personТs age (from 1 to 150 years) and display it with the next word УyearФ, УyearФ or УyearsФ.",
					.func = HW1_Task6
			},
			{
					.Number = 7,
					.ToDo = "There are numerical coordinates of two checkerboard fields (x1, y1, x2, y2). \nIt is required to determine whether the fields belong to the same color or not.",
					.func = HW1_Task7
			},
			{
					.Number = 9,
					.ToDo = "Given positive integers N and K. Using only the addition and subtraction operations, \nfind the quotient of the division of N entirely by K, as well as the remainder of this division.",
					.func = HW1_Task9
			},
			{
					.Number = 10,
					.ToDo = "Given an integer N (> 0). Using whole division operations and taking the remainder of the division, determine\n if there are odd digits in the record of N.\n If yes, print True; if not, print False.",
					.func = HW1_Task10
			},
			{
					.Number = 14,
					.ToDo = "* Automorphic numbers. A natural number is called automorphic if it is equal to the last digits of its square. For example, 25 ^ 2 = 625.\n Write a program that displays all automorphic numbers, within 1_000_000 ",
					.func = HW1_Task14
			}
	};

	TaskMenu(tasks,TCount);
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  Enter the weight and height of the person.
†*  Calculate and derive a body mass index according to the formula I = m / (h * h);
†*   where m is the body weight in kilograms,
†*   h - growth in meters.
*/
void HW1_Task1(){
	double weight,height;

	printf("¬ведите массу тела в кг");
	scanf("%lf",&weight);
	printf("¬ведите рост человека в метрах");
	scanf("%lf",&height);

	printf("»ћ“ равен %lf", weight / (height * height));
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  3.
 *  Write a program for exchanging the values of two integer variables:
 *   b. * without using a third variable.
*/

// value exchange function using the third variable
void swapWithThird(int* first, int* second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

// value exchange function without using a third variable
void swapNotWithThird(int* first, int* second) {
	*first ^= *second;
	*second ^= *first;
	*first ^= *second;
}

void HW1_Task3() {
	int x,y;

	printf("Enter the value of the first variable: ");
	scanf("%d",&x);
	printf("Enter the value of the second variable: ");
	scanf("%d",&y);

	int select;
	printf("Choose a permutation method:\n1 - using the third variable\n2 - without using a third variable\n");
	scanf("%d",&select);
	switch(select){
	case 1:
		swapWithThird(&x, &y);
		printf("permutation using the third variable:\n x:%d , y:%d\n\n", x, y);
		break;
	case 2:
		swapNotWithThird(&x, &y);
		printf("permutation without using the third variable:\n x:%d , y:%d\n\n", x, y);
		break;
	default:
		printf("Something go wrong");
		break;
	}
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  4.
 *  Write a program for finding the roots of a given quadratic equation.
*/
int calculateSquareEquation(int a, int b, int c, float* x1, float* x2) {
	double D = b * b - 4 * a * c;
	if(a!=0){
		if (D < 0) return -1;
			else if (D == 0) {
				*x1 = *x2 = -b / (2 * a);
				return 0;
			}
			else
			{
				*x1 = (-b + sqrt(D)) / (2 * a);
				*x2 = (-b - sqrt(D)) / (2 * a);
				return 1;
			}
	}
	else
	{
		*x1 = -c / b;
		return 0;
	}
}

void HW1_Task4(){
	int a, b, c;
	float x1, x2;

	printf("Enter the numbers of the quadratic equation ax^2+bx+c=0\n");
	printf("\nEnter \'a\': ");
	scanf("%d",&a);
	printf("\nEnter \'b\': ");
	scanf("%d",&b);
	printf("\nEnter \'c\': ");
	scanf("%d",&c);

	if (a == 0) printf("x = %f",(float)(-c/b));
	else {
		switch (calculateSquareEquation(a, b, c, &x1, &x2))
		{
		case -1:
			printf("d < 0");
			break;
		case 0:
			printf("d = 0  x1 = %5.2f, x2 = %5.2f", x1, x2);
			break;
		case 1:
			printf("d > 0  x1 = %5.2f, x2 = %5.2f", x1, x2);
			break;
		default:
			break;
		}
	}
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  6.
 *  Enter the personТs age (from 1 to 150 years) and display it with the next word УгодФ, УгодаФ or УлетФ.
*/
char* ageAdder(int age) {
    if (age % 10 == 1 && (age % 100 != 11))
        return "год";
    else if ((age % 10 >= 2 && age % 10 < 5) &&
             !(age % 100 >= 12 && age % 100 < 15))
        return "года";
    else
        return "лет";
}

void HW1_Task6(){
	int inputAge = 0;

	do{
		printf("Enter the person's age from 1 to 150 years: ");
		scanf("%d",&inputAge);
	}while(inputAge < 1 || inputAge > 150);

	printf("Age: %d %s",inputAge, ageAdder(inputAge));
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  7.
 *  There are numerical coordinates of two checkerboard fields (x1, y1, x2, y2).
 *  It is required to determine whether the fields belong to the same color or not.
*/
int isInDescRange(int coordinate){
	if(coordinate < 1 || coordinate > 8){
		printf("You entered an invalid value");
		return 1;
	}
	else return 0;
}

void HW1_Task7(){
	int x1,y1,x2,y2 = 0;
	int flag = 0;

	do {
		printf("Enter the coordinates of the two fields on the chessboard, in size 8*8\n");
		printf("The first field along the axis x: ");
		scanf("%d",&x1);
		if(isInDescRange(x1)) continue;

		printf("The first field along the axis y: ");
		scanf("%d",&y1);
		if(isInDescRange(y1)) continue;

		printf("The second field along the axis x: ");
		scanf("%d",&x2);
		if(isInDescRange(x2)) continue;

		printf("The second field along the axis y: ");
		scanf("%d",&y2);
		if(isInDescRange(y2)) continue;
		flag = 1;
	} while (flag == 0);

	if(((x1 + y1) % 2) == ((x2 + y2) % 2))
		printf("True");
	else printf("False");
	}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  9.
 *  Given positive integers N and K.
 *  Using only the addition and subtraction operations, find the quotient of dividing N completely by K,
 *  as well as the remainder of this division.
*/
void HW1_Task9(){
	int n,k;

	printf("dividend: ");
	scanf("%d",&n);
	do{
		printf("divider: ");
		scanf("%d",&k);
		if(k==0)printf("cannot be divided by 0\n");
	}while(k==0);

	int result=0;
	while(n>k){
		n-=k;
		result++;
	}
	printf("Quotient: %d\nRemainder of the division: %d", result, n);
}

/*//////////////////////////////////////////////////////////////////////////////////////
 * 10.
 * Given an integer N (> 0).
 * Using the operations of division completely and taking the remainder of the division to determine,
 * are there odd digits in the record of number N.
 *  If available, print True,
 *  if not, print False.
*/
void HW1_Task10(){
	int n=0;

	printf("Enter an integer greater than zero: ");
	scanf("%d", &n);

	int flag = 0;
	while(n>0){
		if(n % 10 % 2){
			printf("True");
			flag = 1;
			break;
		}
		n /= 10;
	}
	if(flag == 0) printf("False");
}

/*//////////////////////////////////////////////////////////////////////////////////////
 * 14.  * Automorphic numbers.
 * 		A natural number is called automorphic if it is equal to the last digits of its square. For example, 25 ^ 2 = 625.
 * Write a program that displays all automorphic numbers, within 1_000_000
*/
void HW1_Task14(){
	const int max = 1000000;
	int sqrNum, width, temp;
	for(int n=0;n<=max;n++){
		temp = n;
		sqrNum = n*n;
		width = 1;
		while(temp>0){
			temp/=10;
			width*=10;
		}
		if(sqrNum % width == n) printf("%d\n",n);
	}
}
