#include <stdio.h>
#define size 10
int Fourteen_main() {
	// void* malloc(<memory size>);

	int variable;
	int* area = (int*)malloc(sizeof(int) * size);
//	int* area = (int*)calloc(size, sizeof(int));
	// ����� ���� � ����
	int array[size];
	int i;
	for (i = 0; i < size; i++)array[i] = i * 10;
	for (i = 0; i < size; i++)printf("%d ", array[i]);
	puts("");
	for (i = 0; i < size; i++) * (area + i) = i * 10;
	for (i = 0; i < size; i++)printf("%d ", *(area + i));
	// free(area); ����������� ������ ���������� �� ���� �������
	puts("");
	int newsize = size + 10;
	area = realloc(area, sizeof(int) * (newsize + 10));
	for (i = 0; i < newsize; i++) * (area + i) = i * 10;
	for (i = 0; i < newsize; i++)printf("%d ", *(area + i));
	free(area); // �� �������� ����������� ������

	return 0;
}
