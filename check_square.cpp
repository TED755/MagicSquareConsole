#include <stdio.h>
#include <stdlib.h>
#include "check_square.h"

bool check_square(int **matr, int n)//������� ������� ��������
{
	if ((check_sum(matr, n) == 1) && (check_degr(matr, n) == 1) 
		 && (check_num(matr, n) == 1))//���� ��� ������� �������� 1
		return true;//���������� true
	else return false;//����� ���������� false
}

int check_degr(int **matr, int n)//��������, ��� �� ���� ������� ������� �� ����������� n*n
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (matr[i][j] > n*n)
				return 0;
		return 1;
}

int check_sum (int **matr, int n)//�������� ���� 
{
	int sumD = 0;
	for (int d = 0; d < n; d++)//�� ���������
		sumD += matr[d][d];
	int sumStr = 0;
	for (int i = 0; i < n; i++)//�� �����������
		sumStr += matr[0][i];
	int sumCol = 0;
	for (int j = 0; j < n; j++)//�� ���������
		sumCol += matr[j][0];
	if ((sumD == sumStr) && (sumCol == sumD) && (sumStr == sumCol))//���� ��� ����� ����� ����� �����
		return 1;//��������� 1
	else 
		return 0;
}

int check_num(int **matr, int n)
{//��������, ��� ������ ����� ����������� � �������� ���� ���
	int *b;
	b = (int*)malloc(n*n *sizeof(int));
	for (int m = 0; m < n*n; m++)
		b[m] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (b[matr[i][j] - 1] == 0)
				b[matr[i][j] - 1]++;
			else return 0;
	return 1;
}