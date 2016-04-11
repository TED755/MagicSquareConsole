#include <stdio.h>
#include <stdlib.h>
#include "check_square.h"

bool check_square(int **matr, int n)//главная функция проверки
{
	if ((check_sum(matr, n) == 1) && (check_degr(matr, n) == 1) 
		 && (check_num(matr, n) == 1))//если все функции возращют 1
		return true;//возвращаем true
	else return false;//иначе возвращаем false
}

int check_degr(int **matr, int n)//проверка, что ни один элемент матрицы не превосходит n*n
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (matr[i][j] > n*n)
				return 0;
		return 1;
}

int check_sum (int **matr, int n)//проверка сумм 
{
	int sumD = 0;
	for (int d = 0; d < n; d++)//по диагонали
		sumD += matr[d][d];
	int sumStr = 0;
	for (int i = 0; i < n; i++)//по горизонтали
		sumStr += matr[0][i];
	int sumCol = 0;
	for (int j = 0; j < n; j++)//по вертикали
		sumCol += matr[j][0];
	if ((sumD == sumStr) && (sumCol == sumD) && (sumStr == sumCol))//если все суммы равны между собой
		return 1;//возращаем 1
	else 
		return 0;
}

int check_num(int **matr, int n)
{//проверка, что каждое число встретилось в квадрате один раз
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