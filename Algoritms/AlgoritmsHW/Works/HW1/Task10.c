/*
 * HW1Source.c
 *
 *  Created on: 25 ����. 2019 �.
 *      Author: Ivan Barmin
 *
	10. ���� ����� ����� N (> 0). � ������� �������� ������� ������ � ������ ������� �� ������� ����������, ������� �� � ������ ����� N �������� �����.
	���� �������, �� ������� True, ���� ��� � ������� False.
 */

#include <stdio.h>

void Task10_main(){
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
