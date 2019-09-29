/*
 * HW1Source.c
 *
 *  Created on: 25 сент. 2019 г.
 *      Author: Ivan Barmin
 */
#include <stdio.h>
#include <string.h>
#define TCount 8

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

void Task1();
void Task3();
void Task4();
void Task6();
void Task7();
void Task9();
void Task10();
void Task14();


void HW1_main(){
	Task tasks[TCount] = {
			{
					.Number = 1,
					.ToDo = "Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);\n где m-масса тела в килограммах, h - рост в метрах.",
					.func = Task1
			},
			{
					.Number = 3,
					.ToDo = "Написать программу обмена значениями двух целочисленных переменных:\n	b. *без использования третьей переменной.",
					.func = Task3
			},
			{
					.Number = 4,
					.ToDo = "Написать программу нахождения корней заданного квадратного уравнения.",
					.func = Task4
			},
			{
					.Number = 6,
					.ToDo = "Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».",
					.func = Task6
			},
			{
					.Number = 7,
					.ToDo = "Имеются числовые координаты двух полей шахматной доски (x1,y1,x2,y2). \nТребуется определить, относятся ли к поля к одному цвету или нет.",
					.func = Task7
			},
			{
					.Number = 9,
					.ToDo = "Даны целые положительные числа N и K. Используя только операции сложения и вычитания, \nнайти частное от деления нацело N на K, а также остаток от этого деления.",
					.func = Task9
			},
			{
					.Number = 10,
					.ToDo = "Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить,\n имеются ли в записи числа N нечетные цифры.\n	Если имеются, то вывести True, если нет — вывести False.",
					.func = Task10
			},
			{
					.Number = 14,
					.ToDo = "* Автоморфные числа.  Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.  Например, 25^2 = 625.\n Напишите программу, которая выводит на экран все автоморфные числа, в пределах 1_000_000",
					.func = Task14
			}
	};

	TaskMenu(tasks,TCount);

	int userInput=0;
	printf("Введите команду задачи: ");
	scanf("%d",&userInput);

	if(userInput >= 0 && userInput < TCount)
			tasks[userInput].func();
		else if(userInput == -1)
			printf("До свидания!");
		else
			printf("Что-то пошло не так\n");
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  Ввести вес и рост человека.
 *  Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);
 *   где m-масса тела в килограммах,
 *   h - рост в метрах.
*/
void Task1(){
	double weight,height;

	printf("Введите массу тела в кг");
	scanf("%lf",&weight);
	printf("Введите рост человека в метрах");
	scanf("%lf",&height);

	printf("ИМТ равен %lf", weight / (height * height));
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  3.
 *  Написать программу обмена значениями двух целочисленных переменных:
 *   b. *без использования третьей переменной.
*/

// функция обмена значениями с использованием третьей переменной
void swapWithThird(int* first, int* second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

// функция обмена значениями без использования третьей переменной
void swapNotWithThird(int* first, int* second) {
	*first ^= *second;
	*second ^= *first;
	*first ^= *second;
}

void Task3() {
	int x,y;

	printf("Введите значение первой переменной: ");
	scanf("%d",&x);
	printf("Введите значение второй переменной: ");
	scanf("%d",&y);

	int select;
	printf("Выберите способ перестановки:\n1 - с использованием третьей переменной\n2 - без использования третьей переменной\n");
	scanf("%d",&select);
	switch(select){
	case 1:
		swapWithThird(&x, &y);
		printf("перестановка с использованием третьей переменной:\n x:%d , y:%d\n\n", x, y);
		break;
	case 2:
		swapNotWithThird(&x, &y);
		printf("перестановка без использования третьей переменной:\n x:%d , y:%d\n\n", x, y);
		break;
	default:
		printf("Something go wrong");
		break;
	}
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  4.
 *  Написать программу нахождения корней заданного квадратного уравнения.
*/
#include <math.h>

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

void Task4(){
	int a, b, c;
	float x1, x2;

	printf("Введите числа квадратного уравнения ax^2+bx+c=0\n");
	printf("\nВведите \'a\': ");
	scanf("%d",&a);
	printf("\nВведите \'b\': ");
	scanf("%d",&b);
	printf("\nВведите \'c\': ");
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
 *  Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
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

void Task6(){
	int inputAge = 0;

	do{
		printf("Введите возраст человека от 1 до 150 лет: ");
		scanf("%d",&inputAge);
	}while(inputAge < 1 || inputAge > 150);

	printf("Возраст: %d %s",inputAge, ageAdder(inputAge));
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  7.
 *  Имеются числовые координаты двух полей шахматной доски (x1,y1,x2,y2).
 *  Требуется определить, относятся ли к поля к одному цвету или нет.
*/
int isInDescRange(int coordinate){
	if(coordinate < 1 || coordinate > 8){
		printf("Вы ввели неверное значение");
		return 1;
	}
	else return 0;
}

void Task7(){
	int x1,y1,x2,y2 = 0;
	int flag = 0;

	do {
		printf("Введите координаты двух полей на шахматной доске, размерами 8*8\n");
		printf("Первое поле по оси x: ");
		scanf("%d",&x1);
		if(isInDescRange(x1)) continue;

		printf("Первое поле по оси y: ");
		scanf("%d",&y1);
		if(isInDescRange(y1)) continue;

		printf("Второе поле по оси x: ");
		scanf("%d",&x2);
		if(isInDescRange(x2)) continue;

		printf("Второе поле по оси y: ");
		scanf("%d",&y2);
		if(isInDescRange(y2)) continue;
		flag = 1;
	} while (flag == 0);

	if(((x1 + y1) % 2) == ((x2 + y2) % 2))
		printf("True");
	else printf("False");
	}
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  9.
 *  Даны целые положительные числа N и K.
 *  Используя только операции сложения и вычитания, найти частное от деления нацело N на K,
 *  а также остаток от этого деления.
*/
void Task9(){
	int n,k;

	printf("делимое число: ");
	scanf("%d",&n);
	do{
		printf("делитель: ");
		scanf("%d",&k);
		if(k==0)printf("нельзя делить на 0\n");
	}while(k==0);

	int result=0;
	while(n>k){
		n-=k;
		result++;
	}
	printf("Частное: %d\nОстаток от деления: %d", result, n);
}

/*//////////////////////////////////////////////////////////////////////////////////////
 * 10.
 * Дано целое число N (> 0).
 * С помощью операций деления нацело и взятия остатка от деления определить,
 * имеются ли в записи числа N нечетные цифры.
 *  Если имеются, то вывести True,
 *  если нет — вывести False.
*/
void Task10(){
	int n=0;

	printf("Введите целое число больше нуля: ");
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
 * 14.  * Автоморфные числа.
 * 		Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. Например, 25^2 = 625.
 * Напишите программу, которая выводит на экран все автоморфные числа, в пределах 1_000_000
*/
void Task14(){
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
