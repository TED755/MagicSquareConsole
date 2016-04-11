#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "check_square.h"
#include "functions.h"
#include "build_square.h"

void build_square_odd(int **matr, int n)//построение квадратов нечетного порядка
{
	int x;
	srand(time(NULL));//для генерации случайных чисел
	x = rand()%2;//генерируем случайное число от 0 до 1
	if (n == 3)//если порядок равен 3
	{
		x = rand()%4;//генерируем случайное число от 0 до 3 для квадратов 3-го порядка
		if (x == 0)//если число равно 0
			version1(matr, n);//генерируем матрицу 3-го порядка
		else
			if (x == 1)//если 1
				version2(matr, n);//генерируем другим способом
			else
				if (x == 2)//если 2
				version3(matr, n);//третьим
				else//если 3
					version4(matr, n);//четырем
	}
	else//если порядок не равен 3
	{
		if (x == 0)
			version1(matr, n);//первый способ
		else 
			version2(matr, n);//второй способ
	}
}

int version1(int **matr, int n)//способ первый
{
	int i = 0, k = 0, j;//i - ряд, j - столбец, k - некий счетчик
	j = n/2;//задаем начальное значение столбцу
	for (k = 1; k <= n*n; ++k)//в цикле от 1 до квадрата порядка
	{
		matr[i][j] = k;//заполняем матрицу
		i--;//уменьшаем ряд
		j++;//увеличиваем столбец
		if (k % n == 0)//если текущее число кратно порядку
		{
			i += 2;//ряд увеличваем на 2
			--j;//стобец уменьшаем на 1
		}
		else 
		{
			if (j == n)//если столбец равен порядку
				j -= n;//вычитаем из столбца порядок
			else if (i < 0)//если ряд меньше 0
				i += n;//ряд плюс порядок
		}
	}//цикл продолжается пока вся матрица не заполнится
	return **matr;//возвращаем матрицу в main()
}

int version2(int **matr, int n)//способ второй
{
	srand(time(NULL));
	int i = 0, k = 0, j;
	i = n/2;
	j = 0;
	for (k = 1; k <= n*n; ++k)
	{
	
		matr[i][j] = k;
		i++;
		j--;
		if (k % n == 0)
		{
			j += 2;
			--i;
		}
		else 
		{
			if (i == n)
				i -= n;
			else if (j < 0)
				j += n;
		}
	}
	return **matr;
}

int version3(int **matr, int n)//способ 3
{//просто заполняем матрицу числами
	matr[0][0] = 4;
	matr[0][1] = 9;
	matr[0][2] = 2;
	matr[1][0] = 3;
	matr[1][1] = 5;
	matr[1][2] = 7;
	matr[2][0] = 8;
	matr[2][1] = 1;
	matr[2][2] = 6;
	return **matr;
}

int version4(int **matr, int n)//способ 4
{
	matr[0][0] = 2;
	matr[0][1] = 7;
	matr[0][2] = 6;
	matr[1][0] = 9;
	matr[1][1] = 5;
	matr[1][2] = 1;
	matr[2][0] = 4;
	matr[2][1] = 3;
	matr[2][2] = 8;
	return **matr;
}

int build_square_even (int **matr, int n)//построение квадратов четного порядка
{
	srand(time(NULL));
	int i, j, count = 0, r, c, sm = 0;
	bool flag = false, cwise;
	int** matr1 = new int*[2*n-2];//создание отдельной матрицы
	for (j = 0; j < 2*n-2; j++)
	{
		matr1[j] = new int[n];
	}
	for (i = 0; i < 2*n-2; i++)//инициализация ее нулями
		for (j = 0; j < n; j++)
			matr1[i][j] = 0;
	if(n%4 == 2)          //для построения четно-четного порядка
	{             //первоначально нужно построить n-2
		n = n - 2;
		flag = true;
	}
	if(n%4 == 0)    //построение четно-четного порядка методом квадратных рамок
	{
		cwise = true;              // направление заполнения
		while (sm + 1 < n)    //пока не пройдем всю матрицу)  +2
		{
			if(cwise == true)//если движение по часовой истинно
			{
				r = (n/2) - 1 + sm; // стартовые значения для почасовой //ряд
				c = 0;//столбец
				while(count%(2*n)!= 1)//цикл заполнения
				{//остаток от деления count на удвоенный порядок не равен 1
					count = 1+n*sm;//count присваиваем новое значение
					matr1[r][c] = count++;//матрице это значение +1
					while(count%(n/2) != 1)//далее в четырех циклах
					{
						r--;//перемещаемся по матрице
						c++;
						matr1[r][c] = count++;//заполняя ее
					}
					matr1[r][++c] = count++;
					while(count%(n/2) != 1)
					{
						r++;
						c++;
						matr1[r][c] = count++;
					}
					matr1[++r][c]= count++;
					while(count%(n/2) != 1)
					{
						r++;
						c--;
						matr1[r][c] = count++;
					}
					matr1[r][--c] = count++;
					while(count%(n/2) != 1)
					{
						r--;
						c--;
						matr1[r][c] = count++;
					}
					cwise = false;
				}//после последенего
				sm += 2;//увеличиваем sm на 2
			}
			if(cwise == false)//если двигаемся против часовой
			{
				r =  (n/2) - 1 + sm;       // стартовые значения для непочасовой
				c = n - 1;
				while(count%(2*n)!= 0)
				{//выполняем операции заполнения для непочасовой
					matr1[r][c] = count++;
					while(count%(n/2) != 1)
					{
						r--;
						c--;
						matr1[r][c] = count++;
					}
					matr1[r][--c] = count++;
					while(count%(n/2) != 1)
					{
						r++;
						c--;
						matr1[r][c] = count++;
					}
					matr1[++r][c]= count++;
					while(count%(n/2) != 1)
					{
						r++;
						c++;
						matr1[r][c] = count++;
					}
					matr1[r][++c] = count++;
					while(count%(n/2) != 1)
					{
						r--;
						c++;
						matr1[r][c] = count++;
					}
					count -= 1;
					cwise = true;
				}
				sm += 2;
			}
		}
		for(i = 0; i < n/2 - 1; i++)//выполняем сдвиги
			for(j = 0; j < n; j++)
			{
				if(matr1[i][j]!= 0)
					matr1[i+n][j] = matr1[i][j];
			}
		for(i = n + n/2 - 1; i < 2*n - 2; i++ )
			for(j = 0; j < n; j++)
			{
				if(matr1[i][j]!= 0)
					matr1[i-n][j] = matr1[i][j];
			}
		if (flag != true)
			{
				int k;//заведение отдельного счетчика
				for(i = n/2 - 1, k = 0; i < n + n/2 -1; i++, k++)
				{
					for(j = 0; j < n; j++)
						matr[k][j] = matr1[i][j];//копирование матрицы
				}
				for (int i = 0; i < n;  i++)
					delete[] matr1[i];
				delete[] matr1;//удаление матрицы
				return **matr;//возвращение матрицы в основную программу
			}
	}
	//построение четно-нечетного порядка
	if(n%4 == 0 && flag == true)
	{
		n = n + 2;//присваиваем порядку изначальное значение
		int** matr2 = new int*[n];      // копирование первой матрицы
		for (j = 0; j < n; j++)           // и расстановка чисел в ней
		{
			matr2[j] = new int[n];
		}
		for(i = 1; i < n - 1; i++)
		{
			for(j = 1; j < n - 1; j++)
			{
				matr2[i][j] = matr1[i + (n-2)/2 - 2][j-1] + 2*(n - 1);//добавление 2*(n-1)
			}
		}
		for (int i = 0; i < 2*n-2;  i++)//удаление matr1
			delete[] matr1[i];
		delete[] matr1;

		matr2[0][0] =  3*(n/2) - 1;
		matr2[0][n-1] = 1;
		matr2[n-1][n-1] = n*n + 2 - (3*n)/2;
		matr2[n-1][0] = n*n;
		i = 1;

		for(j = 1; j < n - 1; j++)         //дополнение верхней строки
		{
			if (i <= n/2 - 2)
			{
				matr2[0][j++] = 2*i + 1;
			}
			matr2[0][j] = n*n + 1 - 2*i;
			i++;
		}
		matr2[1][0] = n - 1;
		i = 1;
		int q = 1;
		for(j = 2; j < n - 1; j++)                  // левый столбец
		{
			while(i <= n/4)
			{
				matr2[j++][0] = (3*n)/2 - 1 - i;
				i++;
			}
			i = 1;
			while(i <= n/4 + 1)
			{
				matr2[j++][0] = n*n + 2 - 2*n + i;
				i++;
			}
			i = 1;
			while (i <= n/4 - 1)
			{
				matr2[j++][0] = (3*n)/2 - 1 + q;
				matr2[j][0] = n*n + 1 - n - q++;
				i++;
				j++;
			}
		}
// добавление чисел в нижнюю строку и правый столбец
		for(j = 1; j < n - 1; j++)
			matr2[n-1][j] = n*n + 1 - matr2[0][j];  //комплементарные числа
		for(i = 1; i < n - 1; i++)
			matr2[i][n-1] = n*n + 1 - matr2[i][0];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				matr[i][j] = matr2[i][j];
		for (int i = 0; i < n;  i++)
				delete[] matr2[i];
			delete[] matr2;//удаляем матрицу
	}
	return **matr;//возвращаем матрицу
}