#include <iostream>
using namespace std;
#include "Header.h"


void creation_matrix(int**& array, int rows, int cols)
{
	array = new int * [rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[cols];
	}
}

void filling_matrix(int** array, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = rand() % 10;
		}
	}
}

void cOutMatrix(int** array, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
}


void clean_matrix(int** array, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
}

void matrix_Sum(int** array, int** array_1, int** array_2, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = array_1[i][j] + array_2[i][j];
		}

	}
}

void matrix_Subtraction(int** array, int** array_1, int** array_2, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = array_1[i][j] - array_2[i][j];
		}

	}
}

void matrix_Multiplication(int** array, int** array1, int** array2, int rows, int cols, int rows_2)
{
	for (int i = 0; i < rows; i++)
	{

		for (int j = 0; j < cols; j++)
		{
			array[i][j] = 0;
			for (int k = 0; k < rows_2; k++)
			{
				array[i][j] += array1[i][k] * array2[k][j];
			}

		}
	}
}

void matrix_Transposition(int**& array, int rows, int cols)
{
	int** temp;
	creation_matrix(temp, cols, rows);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			temp[j][i] = array[i][j];
		}
	}
	clean_matrix(array, rows);
	creation_matrix(array, cols, rows);
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			array[i][j] = temp[i][j];
		}
	}
	clean_matrix(temp, rows);
}

int rankmat(int** array, int n, int m)
{
	int** rank;
	creation_matrix(rank, n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			rank[i][j] = array[i][j];
		}

	}

	float x;
	for (int i = 0; i < n - 2; ++i)
	{
		x = rank[i][i];
		for (int j = i; j < m; ++j)
		{
			rank[i][j] /= x;
		}

		for (int k = i; k < n - 1; ++k)
		{
			x = rank[k + 1][i];
			for (int j = i; j < m; ++j)
			{
				rank[k + 1][j] = rank[k + 1][j] - (rank[i][j] * x);

			}
		}
	}

	int rk = n;
	for (int i = 0; i < n; i++)
	{
		float sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += rank[i][j];

		}
		if (sum == 0)
			rk--;
	}

	clean_matrix(rank, n);
	return rk;
}


