// ��������� ��� ������ �� ���������� �������
#include <stdlib.h>
#include <time.h>

/*
	��������� ������������� �������� �������� ���� ����� �������
	� ����� ������ ��� ���������� ��������
*/
#define bool int
#define true 1
#define false 0

// ����� ����� ���������� � ������� �������� ��������� �������� ����� ������������ �� ��� ���� ���������

// ����������� �������� ������������� �������� ������� � ������������ ����������� �����, ������� ����������� ��������� ��������� �����
#define ARRAY_LENGTH 10
#define NUMBER_AMOUNT 1000000

void printArray(int* array, int length) {
	for (int i = 0; i < length; i++) printf("%d", array[i]);
}


float average(int* array, int length) {
	float result = 0;
	for (int i = 0; i < length; i++)
		result += *(array + i);
	return result;
}

void voidFunction();  // �������� ���������� ������� � ������ �����
void advancedArray();

int EightToTen_main() {

	voidFunction(); // ����� ������� �� ������� �����


	 // ������ ������������ ����� ������ ��������� ����� � ������, � ������� ����������� ������ ���������� ������
	int array[ARRAY_LENGTH];
	array[0] = 1;			   // ������ � ������ �������������� ����� ��������� �� ������ ������
	array[1] = 2;
	// ....

	int array1[5] = { 0,1,2,3,4 };


	srand(time(NULL));
	int frequency[ARRAY_LENGTH] = { 0 };
	int a, i;
	for (i = 0; i < NUMBER_AMOUNT; i++)
	{
		a = rand() % ARRAY_LENGTH;
		frequency[a]++;
	}

	for (i = 0; i < ARRAY_LENGTH; i++)
	{
		printf("Numbers %d generated %6d (%5.2f%%) times\n", i, frequency[i], ((float)frequency[i] / NUMBER_AMOUNT * 100));
	}

	// ���������� ���������� � �������� ������� � �������
	i = 0;
	int arr[ARRAY_LENGTH];
	while (i < ARRAY_LENGTH) {
		printf("Enter value no.%d", i);
		scanf_s("%d", arr + i);                  // arr+i ��� ����������� �� ��������� �������
		i++;
	}
	printf("\nOur array is: ");
	printArray(arr, ARRAY_LENGTH);           // ����� ������� � �������� �������
	printf("\nAnd the average is: ");
	printf("%f\n", average(arr, ARRAY_LENGTH));


	advancedArray();

	return 0;
}
