/*
 * HW1Source.c
 *
 *  Created on: 25 ����. 2019 �.
 *      Author: Ivan Barmin
 *
	9. ���� ����� ������������� ����� N � K. ��������� ������ �������� �������� � ���������, ����� ������� �� ������� ������ N �� K, � ����� ������� �� ����� �������.
 */

#include <stdio.h>

void Task9_main(){
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
