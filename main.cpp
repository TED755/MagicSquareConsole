#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "check_square.h"
#include "build_square.h"
#include "functions.h"

int main()
{
	system("color 0E");//������ ���� �� ������
	setlocale(LC_ALL, "Rus");//������ ���� �� �������
	char c;
	int n, i, j, k, l;
	printf("������� ������ �������� �� 3 �� 19(������� ��������): ");
	scanf("%d", &n);//���� �������
	if ((n <= 2) || (n > 19))//�������� �����
	{
		do
		{
			fflush(stdin);
			printf("������� ����� ����� �� 3 �� 19: ");
			scanf("%d", &n);
		}
		while ((n <= 2) || (n > 19));
	}
	system("cls");//�������� �������
	printf("��� ����������� ������� enter\n");
	printf("��� ������ ������� esc\n");
	printf("� ��������� ������� space (������)\n");
	while (c = getch())//������ � �����������
	{
		switch(c)
		{
			case 13://���� ����� enter
			{
				system("color E");//������ ���� �� ������
				system("cls");//������� �������
				int **matr = new int *[n];//������� ������� ��� ������
				for (int i = 0; i < n; ++i)
				{
					matr[i] = new int [n];
				}
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						matr[i][j] = 0;//�������������� ������� ������
				int **matrC = new int *[n];//������� ������� ��� ��������
				for (int i = 0; i < n; ++i)
				{
					matrC[i] = new int [n];
				}
				if (n % 2 != 0)//����������� �������� ��������
				{//���� ��������
					build_square_odd(matr, n);// ���������� �������� ��������� �������
					for (int i = 0; i < n; i++)
						for (int j = 0; j < n; j++)
							matrC[i][j] = matr[i][j];//����������� ����������� ������� ��� ��������
					zero(matr, n);//������������� ������� ������
					print_square(matr, n);//����� �������
					if (filling(matr, matrC, n) == true)//������ � ��������
					{//���� ������� ���������� (filling ������� true)
						system("cls");//�������� �������
						system("color A");//��������� ����� �� �������
						print_square(matr, n);
						n++;//���������� �������
						printf("������� ����������!\n");
						printf("������� �������� ���������?\n");
						printf("enter - ��\n");
						printf("esc - ���\n");
						break;
					}
				}
				else//���� ������
				{
					build_square_even(matr, n);//���������� �������� ������� �������
					for (int i = 0; i < n; i++)//����� �� �� �����
						for (int j = 0; j < n; j++)
							matrC[i][j] = matr[i][j];
					zero(matr, n);
					print_square(matr, n);
					if (filling(matr, matrC, n) == true)
					{
						system ("cls");
						system("color A");
						print_square(matr, n);
						n++;
						printf("������� ����������!\n");
						printf("������� �������� ���������?\n");
						printf("enter - ��\n");
						printf("esc - ���\n");
						break;
					}
				}
			}
			case 27:{// ���� ����� esc
				exit(0);//����� �� ��������
				break;
			}
			case 32://���� ����� ������
			{
				system ("cls");
				system("color 17");
				printf("============================================\n");
				printf("*     ��������� ����������� ��������       *\n");
				printf("* 10 �������������-���������������� ������ *\n");
				printf("*   ������� ����� �������������� �������  *\n");
				printf("*    ����������� �������� � 2016 ����      *\n");
				printf("============================================\n\n");
				printf("��� ����������� � ���� ������� enter");
				break;
			}
		}
	}
}