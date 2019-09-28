/*
	  1) ���������.
	  ��������� ������������ ���� <math.h>, ������� �������,

	  int calculateSquareEquality(int a, int b, int c, float* x1, float* x2);

	  ������� ����� ������ ���������� ��������� ����
	  a * x ^ 2 + b * x + c = 0
	  � ���������� ����� ����� ��������� � ����������,
	  ������ ������� �������� � �������� ���������� �1 � �2.

	  ������� ������ ������� -1, ���� ��������� �� ����� ������,
	  0, ���� � ��������� ���� ���� ������,
	  � 1, ���� � ��������� ��� �����.


	  2) �������.
	  ���������������� ������ �� ����� �����, ������� �������, ����������� �� ���� ���� ������.

	  ������� ������ ������� ����, ���� � ������� ��� �������� �����,
	  � ��������� ������ ������� ��� �������� ����� � ������� � ������� �������.

	  ����� ���������� �������, ���� ������ ��� ������, ������� ��� ����� �� ������� �� �����.


	  3) ��������.
	  ��� ��������, ���������� ���� integer �������� � ������ 4 �����, � ���������� ���� short ��� �����.

	  ������� �������, ������� ��������� ������ �� ��������������������� ����� (���� int),
	  � ������� ��� �� ����� ��������������������� ������� (���� short). ���, �� ����, ������ ���������� ���� �������.
	  ������ ����������� ��� ��������������� ������ �� �������� ������� ��� ����� �������� ������.

	  ����� ���� ��� �� �������� �������� �������, ������������, ����������,
	  � ������������ "������� ��������� ������� ���� 10" � ������� "���������" ������.
*/
#include <math.h>
#include <stdio.h>

int calculateSquareEquation(int a, int b, int c, float* x1, float* x2) {
	double D = b * b - 4 * a * c;
	if(a==0){
		*x1 = -c / b;
		return 0;
	}
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

int OddDoubler(int* arr, int length) {
	for (int i = 0; i < length; i++)
	{
		if (arr[i] % 2 != 0) {
			for (int k = 0; k < length; k++)
				if (arr[k] % 2 != 0)
					arr[k] *= 2;

			return 1;
		}
	}
	return 0;
}

void intToShortArray(unsigned int* array) {
	unsigned short* arr = array;
	printf("this is array after ");
	for (int i = 0; i < 20; i++) printf("%d ", *(arr + i));
}

void InputArray(int *array, int length){
	printf("enter array\n");
		for (int i = 0; i < length; i++) {
			printf("n.%d is ", i);
			scanf("%d", array + i);
		}
}

int LessonTen_main() {
	printf("This is Lesson Ten Homework\n");

	// 1
	int a, b, c;
	float x1, x2;
	printf("Enter numbers in square equality ax^2+bx+c=0, like a b c\n");
	printf("\nenter a: ");
	scanf("%d",&a);
	printf("\nenter b: ");
	scanf("%d",&b);
	printf("\nenter c: ");
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
	printf("\n");

	// 2
	int array[5];
	printf("enter array\n");
	for (int i = 0; i < 5; i++) {
		printf("n.%d is ", i);
		scanf("%d", array + i);
	}

	printf("base array is: ");
	for (int i = 0; i < 5; i++) printf("%d ", array[i]);
	printf("\n");

	int change = 0;
	OddDoubler(array, 5);
	if (change == 1) {
		printf("changed array is: ");
		for (int i = 0; i < 5; i++) printf("%d ", array[i]);
		printf("\n");
	}
	else printf("array not changed\n");



	printf("enter five integers\n");
	unsigned int array2[10] = { 2000000,1000000,3000000,4000000,100000,200000 , 30000 , 400000 , 65535, 65536 };
	intToShortArray(array2);

	printf("\n");

	return 0;
}
