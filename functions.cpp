#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "check_square.h"
#include "functions.h"

void print_square(int **matr, int n)//������� ������ �������� �� �����
{
	printf("   ");
	for (int i = 1; i <= n; i++)
		printf("%4d", i);
	printf("\n");
	printf("\n");
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%-3d", i+1);
		for (int j = 0; j < n; j++)
		{
			if (matr[i][j] == 0)
				printf("%4c", '_');
			else
				printf("%4d", matr[i][j]);
		}
		printf("\n\n");
		
	}
	printf("\n");
	return;
}

bool filling(int **matr, int **matrC, int n)
{//������� ������ � ���������
	int row, column, num;
	char c;
	infor();//������ ����������
	while (c = getch())//������ � �����������
	{
		switch(c)
		{
			case 13://���� ����� enter
			{
				system("cls");
				print_square(matr, n);
				printf("������� ���, ������� � �����: ");
				scanf("%d%d%d", &row, &column, &num);//���� ������
				do
				{//�������� ����� ������
					if(row > n || column > n || num > n*n)
					{
						system("cls");
						print_square(matr, n);
						printf("������ ������� �������\n");
						printf("��������� ���� ������: ");
						scanf("%d%d%d", &row, &column, &num);
						system("cls");
					}
				}
				while(row > n || column > n || num > n*n);
				row--;//��������� ���� � �������
				column--;//���������� ��� ������ ���������
				if (matr[row][column] != 0)
				{//�������� �� �������
					do
					{//���� ������� ������ ��������� ����
						system("cls");
						print_square(matr, n);
						printf("������ ������� ������\n");
						printf("������� ���, ������� � �����: ");
						scanf("%d%d%d", &row, &column, &num);
						do
						{//�������� ����� ������
							if(row > n || column > n || num > n*n)
							{
								system("cls");
								print_square(matr, n);
								printf("������ ������� �������\n");
								printf("��������� ���� ������: ");
								scanf("%d%d%d", &row, &column, &num);
								system("cls");
							}
						}
						while(row > n || column > n || num > n*n);
						row--;
						column--;
					}//������� �� ����� ��������
					while (matr[row][column] != 0);
					matr[row][column] = num;//���� �������� ������� ��������
					system("cls");
					print_square(matr, n);
					if (matr[row][column] == matrC[row][column])
					{//���� ����� ������� �����
						printf("����� ������� �����\n");
						system("pause");
						system("cls");
					}
					else
					{
						do
						{//���� ������� ��������
							printf("����� ������� �������\n");
							printf("������� ����� ��������: ");
							scanf("%d", &num);
							matr[row][column] = num;
							system("cls");
							print_square(matr, n);
						}//���� �� ����� ������� �����
						while (matr[row][column] != matrC[row][column]);
						printf("����� ������� �����\n");
						system("pause");
						system("cls");
					}
					print_square(matr, n);
					infor();
				}
				else //���� ������� �� ������
				{
					matr[row][column] = num;
					system("cls");
					print_square(matr, n);
					if (matr[row][column] == matrC[row][column]){
						//���� ����� ������� �����
							printf("����� ������� �����\n");
							system("pause");
					}
				else//�����
				{
					do
					{//�������� ������������ �����
						printf("����� ������� �������\n");
						printf("������� ����� ��������: ");
						scanf("%d", &num);
						matr[row][column] = num;
						system("cls");
						print_square(matr, n);
					}
					while (matr[row][column] != matrC[row][column]);
					printf("����� ������� �����\n");
					system("pause");
				}
				system("cls");
				print_square(matr, n);
				infor();
				for (row = 0; row < n; row++)
					for (column = 0; column < n; column++)
						if (matr[row][column] != 0)
						{//���� ��� ������� ���������
							if (check_square(matr, n) == true)
							{//���� ������� ����������
								return true;//���������� true
							}
						}
				}
				break;
			}
			case 118://���� ������ v
			{
				if (check_square(matr, n) == true)
				{//���� ������� ����������
					return true;//���������� true
				}
				else//�����
				{
					system("color C");//���� �� �������
					printf("������� ������������!\n");
					system("pause");
					system("cls");
					system("color E");
					print_square(matr, n);
					infor();
				}
				break;
			}
			case 27://���� ����� esc
			{
				exit(0);//����� �� ���������
				break;
			}
		}
	}
}

void zero(int **matr, int n)//������ ������������� ��������� ����� ������� "0"
{
	int x;
	x = n;
	while (x > 0)
	{
		matr[rand()%n][rand()%n] = 0;//���������� ����� � ������� ����������� 0
		x--;
	}
	return;
}

void infor()//������������� �������
{
	printf("��� ���������� ������� enter\n");
	printf("��� �������� ������� v\n");
	printf("��� ������ ������� esc\n");
	return;
}