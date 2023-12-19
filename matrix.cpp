#include <iostream>
#include "Header.h";
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	char OperationOp = 'y';

	int** matrix;
	int** matrix_2;

	int** matrix_sum;
	int** matrix_subtraction;
	int** matrix_multiplication;

	int first, second, first_2, second_2, user;
	cout << "Введите параметры для первой матрницы: " << endl;
	cin >> first >> second;
	creation_matrix(matrix, first, second);
	filling_matrix(matrix, first, second);
	cOutMatrix(matrix, first, second);

	cout << "Введите параметры для второй матрицы: " << endl;
	cin >> first_2 >> second_2;
	creation_matrix(matrix_2, first_2, second_2);
	filling_matrix(matrix_2, first_2, second_2);
	cOutMatrix(matrix_2, first_2, second_2);


	while (OperationOp == 'y' || OperationOp == 'Y')
	{
		cout << "Отлично! Выберите номер операции, которую хотите провести над данными матрицами:\n"
			"1. Сложение\n"
			"2. Вычитание\n"
			"3. Умножение\n"
			"4. Транспонирование\n"
			"5. Вычислить ранг матрицы\n" << endl;


		cin >> user;
		switch (user)
		{
		case 1:
			if (first == first_2 && second == second_2)
			{

				creation_matrix(matrix_sum, first, second);
				matrix_Sum(matrix_sum, matrix, matrix_2, first, second);
				cout << "Сумма двух матриц: " << endl;
				cOutMatrix(matrix_sum, first, second);
				clean_matrix(matrix_sum, first);
			}
			else
			{
				cout << "Складывать можно только матрицы одного размера." << endl;
			}
			break;

		case 2:
			if (first == first_2 && second == second_2)
			{
				creation_matrix(matrix_subtraction, first, second);
				matrix_Subtraction(matrix_subtraction, matrix, matrix_2, first, second);
				cout << "Разница двух матриц: " << endl;
				cOutMatrix(matrix_subtraction, first, second);
				clean_matrix(matrix_subtraction, first);
			}
			else
			{
				cout << "Вычитать можно только матрицы одного размера. " << endl;
			}
			break;
		case 3:
			if (second == first_2)
			{
				creation_matrix(matrix_multiplication, first, second_2);
				matrix_Multiplication(matrix_multiplication, matrix, matrix_2, first, second_2, second);
				cout << "Произведение матриц: " << endl;
				cOutMatrix(matrix_multiplication, first, second_2);
			}
			else
			{
				cout << "Неверные значения. Матрицы перемножить нельзя!" << endl;
			}
			break;
		case 4:
			cout << "Транспонирование какой матрицы сделать?\n"
				"1. первая\n"
				"2. вторая\n" << endl;

			int choice;
			cin >> choice;
			if (choice == 1) {
				matrix_Transposition(matrix, first, second);
				swap(first, second);
				cout << "Транспонирование первой матрицы: " << endl;
				cOutMatrix(matrix, first, second);
			}
			else if (choice == 2)
			{
				matrix_Transposition(matrix_2, first_2, second_2);
				swap(first_2, second_2);
				cout << "Транспонирование второй матрицы: " << endl;
				cOutMatrix(matrix_2, first_2, second_2);
			}
			else
			{
				cout << "Неккоретный ввод. Попробуйте ещё раз." << endl;
			}
			break;
		case 5:
			cout << "Ранг какой матрицы найти?\n"
				"1. первая\n"
				"2. вторая\n" << endl;
			int user_Input;
			cin >> user_Input;
			if (user_Input == 1) {
				cout << "Ранг первой матрицы: ";
				cout << rankmat(matrix, first, second) << endl;
			}
			else if (user_Input == 2)
			{
				cout << "Ранг второй матрицы: ";
				cout << rankmat(matrix_2, first_2, second_2) << endl;
			}
			else {
				cout << "Неверный ввод. Попробуйте ещё раз!" << endl;
			}
			break;
		}

		cout << "Хотите ли вы продолжить? (y/n)" << endl;
		cin >> OperationOp;
	}
	return 0;
}