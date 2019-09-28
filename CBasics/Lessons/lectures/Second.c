// ��� ������������ �����������

/*
  ��� ������������� �����������
*/


//  ��������� ������������� ����� ��� ����������� ������� ������ ����
#include <stdio.h>


// ������� ��� ������ ��������� ������� ����� ��� main � ���������� int
int Second_main() {
	/*
		printf() - ������� ��������� � stdio.h, ������������ ��� ������ ������ �� �������

		� ������� ��� �� �������������� ������������:
		 �������� �����������:
		  \n - ������ ����� ������
		  \t - ������ ���������
		  \\ - ������ \
		  \0 - ������ ����� ������
	*/
	printf("Hello World!\n");
	printf("This is a new row with \ttab\n");
	printf("This row with \\ symbol\n");
	printf("This row without \0end\n");

	printf("\n");
	/*
		 ����������� ����������:
		  %d - int
		  %s - ������
		  %c - char
		  %p - ���������
		  %f - float
		  %lf - double
		  %x - �������������������
		  %% - ������ ��������

		 ��� �������� ����� ������������ ��������� ����� �����
		  %05d ��� ������ �������� � ����������� ������ "00050"
		  %5d ������ ����� ������������ ������� "   50"
		  %.2f ��������� ������� ������ ������ ���� ����� ������� "50.00"
	*/
	short shrt = 345;
	int num = 50;
	char sym = 'A';
	char sym2 = 75;
	float flo = 50.02f;
	double dbl = 50.24;
	// ��� ���� boolean, ������������ ��� int ������ 1 - true, 0 - false

	// ���� ������� unsigned:   char, int

	printf("This is int %d \n", num);
	printf("This is int %05d with pre 0 \n", num);
	printf("This is int %5d with pre   \n", num);
	printf("%c \n", sym);
	printf("%c \n", sym2);
	printf("This is float %f \n", flo);
	printf("This is float %.2f with after numbers \n", flo);
	printf("This is float %.2lf with after numbers \n", flo);

	// �������� ���������� �� ��������
	printf("%d \n", num);
	// �������� ������� ����������
	printf("%p \n", &num);

	printf("Tipe any number: ");
	int inputNum;
	// ������� ����������������� ����� � �������
	scanf("%d", &inputNum);
	// ��������� ��� �������� ���������� � ������ ���������� ��� ������ ��������
	// printf("\nyou tipe this %d number and we multiply it %d", inputNum/*,inputNum*2 �������������� �����������*/);
	printf("\nyou tipe this %d number and we multiply it", inputNum);


	// �������������� ��������
	/*
	�����������: +, -, *, /, %

	��������:
	  & - �
	  | - ���
	  ! - ��
	  ^ - ����������� ���
	  << >> - ����� ����� � ������

	��������� - ++var, var++
	��������� - --var, var--

	�������� � ����������� ���������� �������� � ������ ����������(+=, -=, *=, ...)
	*/

	int variable = 70;
	printf("var is: %d\n", variable);
	variable += 50;
	variable++;
	++variable;
	printf("now var is: %d\n", variable);

	printf("\n");

	// �������� ����������
	/*
	  1 & 0 = 0
	  1 | 0 = 1
	  0 ^ 1 = 1
	  !1 = 0
	*/
	int a = 11; // a= 00001011
	int b = 15;	// b= 00001111
	printf("a=%d,b=%d\n", a, b);

	a = a ^ b; // 00000100
	b = b ^ a; // 00001011
	a = a ^ b; // 00001111
	printf("a=%d,b=%d\n", a, b);

	a = a << 3; // a �������� �� 2 � ������� 3
	b = b >> 2; // b �������� �� 2 �� 2 �������

	printf("a=%d,b=%d\n", a, b);


	// ����� main ����������� ������ ���������� 0, ��� �������� ���������� ���������
	return 0;
}
