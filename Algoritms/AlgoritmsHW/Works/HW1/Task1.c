/*
 * HW1Source.c
 *
 *  Created on: 25 ����. 2019 �.
 *      Author: Ivan Barmin
 *
 *  1. ������ ��� � ���� ��������. ���������� � ������� ������ ����� ���� �� ������� I=m/(h*h); ��� m-����� ���� � �����������, h - ���� � ������.
 *
 */
void Task1_main(){
	double weight,height;
	printf("������� ����� ���� � ��");
	scanf("%lf",&weight);
	printf("������� ���� �������� � ������");
	scanf("%lf",&height);
	printf("��� ����� %lf", weight / (height * height));
}
