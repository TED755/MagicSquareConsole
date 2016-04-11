#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "check_square.h"
#include "functions.h"

void print_square(int **matr, int n)//функция вывода квадрата на экран
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
{//функция работы с квадратом
	int row, column, num;
	char c;
	infor();//выодим информацию
	while (c = getch())//работа с клавиатурой
	{
		switch(c)
		{
			case 13://если нажат enter
			{
				system("cls");
				print_square(matr, n);
				printf("Введите ряд, столбец и число: ");
				scanf("%d%d%d", &row, &column, &num);//ввод данных
				do
				{//проверка ввода данных
					if(row > n || column > n || num > n*n)
					{
						system("cls");
						print_square(matr, n);
						printf("Данные введены неверно\n");
						printf("Повторите ввод данных: ");
						scanf("%d%d%d", &row, &column, &num);
						system("cls");
					}
				}
				while(row > n || column > n || num > n*n);
				row--;//вычитание ряда и столбца
				column--;//необходимо для работы программы
				if (matr[row][column] != 0)
				{//проверка на позицию
					do
					{//если позиция занята выполнять пока
						system("cls");
						print_square(matr, n);
						printf("Данная позиция занята\n");
						printf("Введите ряд, столбец и число: ");
						scanf("%d%d%d", &row, &column, &num);
						do
						{//проверка ввода данных
							if(row > n || column > n || num > n*n)
							{
								system("cls");
								print_square(matr, n);
								printf("Данные введены неверно\n");
								printf("Повторите ввод данных: ");
								scanf("%d%d%d", &row, &column, &num);
								system("cls");
							}
						}
						while(row > n || column > n || num > n*n);
						row--;
						column--;
					}//позиция не будет свободна
					while (matr[row][column] != 0);
					matr[row][column] = num;//если свободна матрице значение
					system("cls");
					print_square(matr, n);
					if (matr[row][column] == matrC[row][column])
					{//если число введено верно
						printf("Число введено верно\n");
						system("pause");
						system("cls");
					}
					else
					{
						do
						{//если неверно выолнять
							printf("Число введено неверно\n");
							printf("Введите число повторно: ");
							scanf("%d", &num);
							matr[row][column] = num;
							system("cls");
							print_square(matr, n);
						}//пока не будет введено верно
						while (matr[row][column] != matrC[row][column]);
						printf("Число введено верно\n");
						system("pause");
						system("cls");
					}
					print_square(matr, n);
					infor();
				}
				else //если позиция не занята
				{
					matr[row][column] = num;
					system("cls");
					print_square(matr, n);
					if (matr[row][column] == matrC[row][column]){
						//если число введено верно
							printf("Число введено верно\n");
							system("pause");
					}
				else//иначе
				{
					do
					{//проверка правильности числа
						printf("Число введено неверно\n");
						printf("Введите число повторно: ");
						scanf("%d", &num);
						matr[row][column] = num;
						system("cls");
						print_square(matr, n);
					}
					while (matr[row][column] != matrC[row][column]);
					printf("Число введено верно\n");
					system("pause");
				}
				system("cls");
				print_square(matr, n);
				infor();
				for (row = 0; row < n; row++)
					for (column = 0; column < n; column++)
						if (matr[row][column] != 0)
						{//если вся матрица заполнена
							if (check_square(matr, n) == true)
							{//если квадрат магический
								return true;//возвращаем true
							}
						}
				}
				break;
			}
			case 118://если нажата v
			{
				if (check_square(matr, n) == true)
				{//если квадрат магический
					return true;//возвращаем true
				}
				else//иначе
				{
					system("color C");//цвет на красный
					printf("Квадрат немагический!\n");
					system("pause");
					system("cls");
					system("color E");
					print_square(matr, n);
					infor();
				}
				break;
			}
			case 27://если нажат esc
			{
				exit(0);//выход из программы
				break;
			}
		}
	}
}

void zero(int **matr, int n)//фунция инициализации случайных чисел матрицы "0"
{
	int x;
	x = n;
	while (x > 0)
	{
		matr[rand()%n][rand()%n] = 0;//случайному числу в матрице присваиваем 0
		x--;
	}
	return;
}

void infor()//информирующая функция
{
	printf("Для заполнения нажмите enter\n");
	printf("Для проверки нажмите v\n");
	printf("Для выхода нажмите esc\n");
	return;
}