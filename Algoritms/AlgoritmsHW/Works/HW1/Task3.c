/*
 * HW1Source.c
 *
 *  Created on: 25 ����. 2019 �.
 *      Author: Ivan Barmin
 *
	3. �������� ��������� ������ ���������� ���� ������������� ����������:
		b. *��� ������������� ������� ����������.
 */
#include <stdio.h>
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

void Task3_main() {
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
