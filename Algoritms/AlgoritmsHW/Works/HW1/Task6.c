/*
 * HW1Source.c
 *
 *  Created on: 25 ����. 2019 �.
 *      Author: Ivan Barmin
 *
	6. ������ ������� �������� (�� 1 �� 150 ���) � ������� ��� ������ � ����������� ������ ����, ����� ��� ����.
 */
#include <stdio.h>

void Task6_main(){
	int inputAge = 0;
	do{
		printf("������� ������� �������� �� 1 �� 150 ���: ");
		scanf("%d",&inputAge);
	}while(inputAge < 1 || inputAge > 150);

	printf("�������: %d",inputAge);

}
