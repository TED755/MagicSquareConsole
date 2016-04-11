#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "check_square.h"
#include "build_square.h"
#include "functions.h"

int main()
{
	system("color 0E");//меняем цвет на желтый
	setlocale(LC_ALL, "Rus");//меняем язык на русский
	char c;
	int n, i, j, k, l;
	printf("Введите размер квадрата от 3 до 19(порядок квадрата): ");
	scanf("%d", &n);//ввод порядка
	if ((n <= 2) || (n > 19))//проверка ввода
	{
		do
		{
			fflush(stdin);
			printf("Введите целое число от 3 до 19: ");
			scanf("%d", &n);
		}
		while ((n <= 2) || (n > 19));
	}
	system("cls");//очищение консоли
	printf("Для продолжения нажмите enter\n");
	printf("Для выхода нажмите esc\n");
	printf("О программе нажмите space (пробел)\n");
	while (c = getch())//работа с клавиатурой
	{
		switch(c)
		{
			case 13://если нажат enter
			{
				system("color E");//меняем цвет на желтый
				system("cls");//очищаем консоль
				int **matr = new int *[n];//заводим матрицу для работы
				for (int i = 0; i < n; ++i)
				{
					matr[i] = new int [n];
				}
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						matr[i][j] = 0;//инициализируем матрицу нулями
				int **matrC = new int *[n];//заводим матрицу для проверки
				for (int i = 0; i < n; ++i)
				{
					matrC[i] = new int [n];
				}
				if (n % 2 != 0)//определение четности квадрата
				{//если нечетный
					build_square_odd(matr, n);// построение квадрата нечетного порядка
					for (int i = 0; i < n; i++)
						for (int j = 0; j < n; j++)
							matrC[i][j] = matr[i][j];//копирование построенной матрицы для проверки
					zero(matr, n);//инициализация матрицы нулями
					print_square(matr, n);//вывод матрицы
					if (filling(matr, matrC, n) == true)//работа с матрицей
					{//если квадрат магический (filling вернула true)
						system("cls");//очищение консоли
						system("color A");//изменение цвета на зеленый
						print_square(matr, n);
						n++;//увелечение порядка
						printf("Квадрат магический!\n");
						printf("Желаете повысить сложность?\n");
						printf("enter - да\n");
						printf("esc - нет\n");
						break;
					}
				}
				else//если четный
				{
					build_square_even(matr, n);//построение квадрата четного порядка
					for (int i = 0; i < n; i++)//далее то же самое
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
						printf("Квадрат магический!\n");
						printf("Желаете повысить сложность?\n");
						printf("enter - да\n");
						printf("esc - нет\n");
						break;
					}
				}
			}
			case 27:{// если нажат esc
				exit(0);//выход из прогаммы
				break;
			}
			case 32://если нажат пробел
			{
				system ("cls");
				system("color 17");
				printf("============================================\n");
				printf("*     Программа разработана учеником       *\n");
				printf("* 10 информационно-технологического класса *\n");
				printf("*   средней школы «Провинциальны колледж»  *\n");
				printf("*    Тихомировым Евгением в 2016 году      *\n");
				printf("============================================\n\n");
				printf("Для возвращения к игре нажмите enter");
				break;
			}
		}
	}
}