/*
 * HW1Source.c
 *
 *  Created on: 25 ����. 2019 �.
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
		printf("�������: %d\n ����� ������: %d\n �������: \n%s\n\n",i ,(array + i)->Number, (array+i)->ToDo);
	}
	printf("������� �� �����: -1\n");
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
					.ToDo = "������ ��� � ���� ��������. ���������� � ������� ������ ����� ���� �� ������� I=m/(h*h);\n ��� m-����� ���� � �����������, h - ���� � ������.",
					.func = Task1
			},
			{
					.Number = 3,
					.ToDo = "�������� ��������� ������ ���������� ���� ������������� ����������:\n	b. *��� ������������� ������� ����������.",
					.func = Task3
			},
			{
					.Number = 4,
					.ToDo = "�������� ��������� ���������� ������ ��������� ����������� ���������.",
					.func = Task4
			},
			{
					.Number = 6,
					.ToDo = "������ ������� �������� (�� 1 �� 150 ���) � ������� ��� ������ � ����������� ������ ����, ����� ��� ����.",
					.func = Task6
			},
			{
					.Number = 7,
					.ToDo = "������� �������� ���������� ���� ����� ��������� ����� (x1,y1,x2,y2). \n��������� ����������, ��������� �� � ���� � ������ ����� ��� ���.",
					.func = Task7
			},
			{
					.Number = 9,
					.ToDo = "���� ����� ������������� ����� N � K. ��������� ������ �������� �������� � ���������, \n����� ������� �� ������� ������ N �� K, � ����� ������� �� ����� �������.",
					.func = Task9
			},
			{
					.Number = 10,
					.ToDo = "���� ����� ����� N (> 0). � ������� �������� ������� ������ � ������ ������� �� ������� ����������,\n ������� �� � ������ ����� N �������� �����.\n	���� �������, �� ������� True, ���� ��� � ������� False.",
					.func = Task10
			},
			{
					.Number = 14,
					.ToDo = "* ����������� �����.  ����������� ����� ���������� �����������, ���� ��� ����� ��������� ������ ������ ��������.  ��������, 25^2 = 625.\n �������� ���������, ������� ������� �� ����� ��� ����������� �����, � �������� 1_000_000",
					.func = Task14
			}
	};

	TaskMenu(tasks,TCount);

	int userInput=0;
	printf("������� ������� ������: ");
	scanf("%d",&userInput);

	if(userInput >= 0 && userInput < TCount)
			tasks[userInput].func();
		else if(userInput == -1)
			printf("�� ��������!");
		else
			printf("���-�� ����� �� ���\n");
}


/*//////////////////////////////////////////////////////////////////////////////////////
 *  1.
 *  ������ ��� � ���� ��������.
 *  ���������� � ������� ������ ����� ���� �� ������� I=m/(h*h);
 *   ��� m-����� ���� � �����������,
 *   h - ���� � ������.
*/
void Task1(){
	double weight,height;

	printf("������� ����� ���� � ��");
	scanf("%lf",&weight);
	printf("������� ���� �������� � ������");
	scanf("%lf",&height);

	printf("��� ����� %lf", weight / (height * height));
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  3.
 *  �������� ��������� ������ ���������� ���� ������������� ����������:
 *   b. *��� ������������� ������� ����������.
*/

// ������� ������ ���������� � �������������� ������� ����������
void swapWithThird(int* first, int* second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

// ������� ������ ���������� ��� ������������� ������� ����������
void swapNotWithThird(int* first, int* second) {
	*first ^= *second;
	*second ^= *first;
	*first ^= *second;
}

void Task3() {
	int x,y;

	printf("������� �������� ������ ����������: ");
	scanf("%d",&x);
	printf("������� �������� ������ ����������: ");
	scanf("%d",&y);

	int select;
	printf("�������� ������ ������������:\n1 - � �������������� ������� ����������\n2 - ��� ������������� ������� ����������\n");
	scanf("%d",&select);
	switch(select){
	case 1:
		swapWithThird(&x, &y);
		printf("������������ � �������������� ������� ����������:\n x:%d , y:%d\n\n", x, y);
		break;
	case 2:
		swapNotWithThird(&x, &y);
		printf("������������ ��� ������������� ������� ����������:\n x:%d , y:%d\n\n", x, y);
		break;
	default:
		printf("Something go wrong");
		break;
	}
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  4.
 *  �������� ��������� ���������� ������ ��������� ����������� ���������.
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

	printf("������� ����� ����������� ��������� ax^2+bx+c=0\n");
	printf("\n������� \'a\': ");
	scanf("%d",&a);
	printf("\n������� \'b\': ");
	scanf("%d",&b);
	printf("\n������� \'c\': ");
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
 *  ������ ������� �������� (�� 1 �� 150 ���) � ������� ��� ������ � ����������� ������ ����, ����� ��� ����.
*/
char* ageAdder(int age) {
    if (age % 10 == 1 && (age % 100 != 11))
        return "���";
    else if ((age % 10 >= 2 && age % 10 < 5) &&
             !(age % 100 >= 12 && age % 100 < 15))
        return "����";
    else
        return "���";
}

void Task6(){
	int inputAge = 0;

	do{
		printf("������� ������� �������� �� 1 �� 150 ���: ");
		scanf("%d",&inputAge);
	}while(inputAge < 1 || inputAge > 150);

	printf("�������: %d %s",inputAge, ageAdder(inputAge));
}

/*//////////////////////////////////////////////////////////////////////////////////////
 *  7.
 *  ������� �������� ���������� ���� ����� ��������� ����� (x1,y1,x2,y2).
 *  ��������� ����������, ��������� �� � ���� � ������ ����� ��� ���.
*/
int isInDescRange(int coordinate){
	if(coordinate < 1 || coordinate > 8){
		printf("�� ����� �������� ��������");
		return 1;
	}
	else return 0;
}

void Task7(){
	int x1,y1,x2,y2 = 0;
	int flag = 0;

	do {
		printf("������� ���������� ���� ����� �� ��������� �����, ��������� 8*8\n");
		printf("������ ���� �� ��� x: ");
		scanf("%d",&x1);
		if(isInDescRange(x1)) continue;

		printf("������ ���� �� ��� y: ");
		scanf("%d",&y1);
		if(isInDescRange(y1)) continue;

		printf("������ ���� �� ��� x: ");
		scanf("%d",&x2);
		if(isInDescRange(x2)) continue;

		printf("������ ���� �� ��� y: ");
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
 *  ���� ����� ������������� ����� N � K.
 *  ��������� ������ �������� �������� � ���������, ����� ������� �� ������� ������ N �� K,
 *  � ����� ������� �� ����� �������.
*/
void Task9(){
	int n,k;

	printf("������� �����: ");
	scanf("%d",&n);
	do{
		printf("��������: ");
		scanf("%d",&k);
		if(k==0)printf("������ ������ �� 0\n");
	}while(k==0);

	int result=0;
	while(n>k){
		n-=k;
		result++;
	}
	printf("�������: %d\n������� �� �������: %d", result, n);
}

/*//////////////////////////////////////////////////////////////////////////////////////
 * 10.
 * ���� ����� ����� N (> 0).
 * � ������� �������� ������� ������ � ������ ������� �� ������� ����������,
 * ������� �� � ������ ����� N �������� �����.
 *  ���� �������, �� ������� True,
 *  ���� ��� � ������� False.
*/
void Task10(){
	int n=0;

	printf("������� ����� ����� ������ ����: ");
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
 * 14.  * ����������� �����.
 * 		����������� ����� ���������� �����������, ���� ��� ����� ��������� ������ ������ ��������. ��������, 25^2 = 625.
 * �������� ���������, ������� ������� �� ����� ��� ����������� �����, � �������� 1_000_000
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
