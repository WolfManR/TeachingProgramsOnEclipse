#include <string.h>
#include <stdlib.h>

void helloFunction(char* name, char* out) {
	char welcome[256] = "Hello, ";
	name[0] = tolower(name[0]);
	if (strcmp("ivan", name) == 0)
		strcpy_s(name, 8, "Master!");
	name[0] = toupper(name[0]);
	strcat_s(welcome, sizeof(*name) / sizeof(char), name);
	strcpy_s(out, sizeof(welcome) / sizeof(char), welcome);
}

//isalpha() isdigit() isspace() isupper() islower toupper() tolower()

int Eleven_main() {
	/*
		������� string �� ����������, ��� �����������
		� ������ ������ ������������ ������ �� ���������� ������ �,
		� ������ ����� �� ������, ������������ ���������� ��� ������ � ����
	*/

	// ������������� ������ � C
	// ��� ������ ����������� �����
	char string1[256] = "This is a string!";
	// ��� ��������� �� ��� char
	char* string2 = "This is also a string!";

	printf("%s \n", string1);
	printf("%s \n", string2);

	// ������ � ���� ������� ��������� �������� ����� ������������ � �� ������
	string1[5] = 'X';
	printf("%s \n", string1);
	// ������ � ���� ��������� ������ �� ����� ���������, �.� � ������ �������� �����������
	// ����������� ������ �������� � ������ ��������,
	// �������� �������� �� � ������� ������� ����� ��������� ����� ���� ������

	char name[256];
	char result[256];
	gets(name);         // ��������� ������ �� ������� � ��������� � � ��������� ����������

	helloFunction(name, result);
	puts(result);       // ��������� ������ ������ � ���� ��������� � ������� � � ������� � ����������� ������� \n � ����� ������

	// atoi() - ��������� ������ � ���������� ������������ � � ���� int
	// atof() - ��������� ������ � ���������� ������������ � � ���� float
	char num[64];
	puts("Enter a number");
	gets(num);
	int number = atoi(num);
	number *= number;

	printf("We powered your number to %d", number);

	return 0;
}
