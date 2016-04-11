#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "check_square.h"
#include "functions.h"
#include "build_square.h"

void build_square_odd(int **matr, int n)//���������� ��������� ��������� �������
{
	int x;
	srand(time(NULL));//��� ��������� ��������� �����
	x = rand()%2;//���������� ��������� ����� �� 0 �� 1
	if (n == 3)//���� ������� ����� 3
	{
		x = rand()%4;//���������� ��������� ����� �� 0 �� 3 ��� ��������� 3-�� �������
		if (x == 0)//���� ����� ����� 0
			version1(matr, n);//���������� ������� 3-�� �������
		else
			if (x == 1)//���� 1
				version2(matr, n);//���������� ������ ��������
			else
				if (x == 2)//���� 2
				version3(matr, n);//�������
				else//���� 3
					version4(matr, n);//�������
	}
	else//���� ������� �� ����� 3
	{
		if (x == 0)
			version1(matr, n);//������ ������
		else 
			version2(matr, n);//������ ������
	}
}

int version1(int **matr, int n)//������ ������
{
	int i = 0, k = 0, j;//i - ���, j - �������, k - ����� �������
	j = n/2;//������ ��������� �������� �������
	for (k = 1; k <= n*n; ++k)//� ����� �� 1 �� �������� �������
	{
		matr[i][j] = k;//��������� �������
		i--;//��������� ���
		j++;//����������� �������
		if (k % n == 0)//���� ������� ����� ������ �������
		{
			i += 2;//��� ���������� �� 2
			--j;//������ ��������� �� 1
		}
		else 
		{
			if (j == n)//���� ������� ����� �������
				j -= n;//�������� �� ������� �������
			else if (i < 0)//���� ��� ������ 0
				i += n;//��� ���� �������
		}
	}//���� ������������ ���� ��� ������� �� ����������
	return **matr;//���������� ������� � main()
}

int version2(int **matr, int n)//������ ������
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

int version3(int **matr, int n)//������ 3
{//������ ��������� ������� �������
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

int version4(int **matr, int n)//������ 4
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

int build_square_even (int **matr, int n)//���������� ��������� ������� �������
{
	srand(time(NULL));
	int i, j, count = 0, r, c, sm = 0;
	bool flag = false, cwise;
	int** matr1 = new int*[2*n-2];//�������� ��������� �������
	for (j = 0; j < 2*n-2; j++)
	{
		matr1[j] = new int[n];
	}
	for (i = 0; i < 2*n-2; i++)//������������� �� ������
		for (j = 0; j < n; j++)
			matr1[i][j] = 0;
	if(n%4 == 2)          //��� ���������� �����-������� �������
	{             //������������� ����� ��������� n-2
		n = n - 2;
		flag = true;
	}
	if(n%4 == 0)    //���������� �����-������� ������� ������� ���������� �����
	{
		cwise = true;              // ����������� ����������
		while (sm + 1 < n)    //���� �� ������� ��� �������)  +2
		{
			if(cwise == true)//���� �������� �� ������� �������
			{
				r = (n/2) - 1 + sm; // ��������� �������� ��� ��������� //���
				c = 0;//�������
				while(count%(2*n)!= 1)//���� ����������
				{//������� �� ������� count �� ��������� ������� �� ����� 1
					count = 1+n*sm;//count ����������� ����� ��������
					matr1[r][c] = count++;//������� ��� �������� +1
					while(count%(n/2) != 1)//����� � ������� ������
					{
						r--;//������������ �� �������
						c++;
						matr1[r][c] = count++;//�������� ��
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
				}//����� �����������
				sm += 2;//����������� sm �� 2
			}
			if(cwise == false)//���� ��������� ������ �������
			{
				r =  (n/2) - 1 + sm;       // ��������� �������� ��� �����������
				c = n - 1;
				while(count%(2*n)!= 0)
				{//��������� �������� ���������� ��� �����������
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
		for(i = 0; i < n/2 - 1; i++)//��������� ������
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
				int k;//��������� ���������� ��������
				for(i = n/2 - 1, k = 0; i < n + n/2 -1; i++, k++)
				{
					for(j = 0; j < n; j++)
						matr[k][j] = matr1[i][j];//����������� �������
				}
				for (int i = 0; i < n;  i++)
					delete[] matr1[i];
				delete[] matr1;//�������� �������
				return **matr;//����������� ������� � �������� ���������
			}
	}
	//���������� �����-��������� �������
	if(n%4 == 0 && flag == true)
	{
		n = n + 2;//����������� ������� ����������� ��������
		int** matr2 = new int*[n];      // ����������� ������ �������
		for (j = 0; j < n; j++)           // � ����������� ����� � ���
		{
			matr2[j] = new int[n];
		}
		for(i = 1; i < n - 1; i++)
		{
			for(j = 1; j < n - 1; j++)
			{
				matr2[i][j] = matr1[i + (n-2)/2 - 2][j-1] + 2*(n - 1);//���������� 2*(n-1)
			}
		}
		for (int i = 0; i < 2*n-2;  i++)//�������� matr1
			delete[] matr1[i];
		delete[] matr1;

		matr2[0][0] =  3*(n/2) - 1;
		matr2[0][n-1] = 1;
		matr2[n-1][n-1] = n*n + 2 - (3*n)/2;
		matr2[n-1][0] = n*n;
		i = 1;

		for(j = 1; j < n - 1; j++)         //���������� ������� ������
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
		for(j = 2; j < n - 1; j++)                  // ����� �������
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
// ���������� ����� � ������ ������ � ������ �������
		for(j = 1; j < n - 1; j++)
			matr2[n-1][j] = n*n + 1 - matr2[0][j];  //��������������� �����
		for(i = 1; i < n - 1; i++)
			matr2[i][n-1] = n*n + 1 - matr2[i][0];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				matr[i][j] = matr2[i][j];
		for (int i = 0; i < n;  i++)
				delete[] matr2[i];
			delete[] matr2;//������� �������
	}
	return **matr;//���������� �������
}