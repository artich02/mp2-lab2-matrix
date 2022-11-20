// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include "tmatrix.h" 
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
using namespace std;

void main()
{
	int N, n, op = 0, val;
	char c;
	setlocale(LC_ALL, "Russian");
	std::srand(time(NULL));
	cout << "Для Старта введите размер квадратных матриц n (1 число): ";
	cin >> n;
	cout <<"\n!Все дальнейшие оперции будут выполняться с квадратными матрицами размера n=" << n << "!\n";
	system("pause");
	TDynamicMatrix<int> a(n), b(n), res(n);
	
	//Меню выбора
	char menu_str[8][80] = {
		{"Ручное заполнение матриц A и B"},
		{"Автоматическое заполнение матриц A и B"},
		{"Сложение матриц A и B"},
		{"Разность матриц A и B"},
		{"Произведение матриц a и B"},
		{"Умножение матрицы A на вектор"},
		{"Умножение матрицы A на скаляр"},
		{"Вывести матрицы A и B"}
				
	};
	
	int n_op = 8; //количество строк выбора
	while (true)
	{
		system("cls");
		cout << "FAQ: Размер пространства n=" << n << "\n";
		cout << "     Для выхода из окна дважды нажмите Esc\n";
		cout << "     Для выбора строки используйте up и down\n";
		cout << "     Для выполнения операции используйте Enter\n\n";
		
		for (int i = 0; i < n_op; i++)

		{
			if (i == op)
			{
				printf("* ");
			}
			else
			{
				printf(" ");
			}
			printf("%s\n", menu_str[i]);
		}

		c = _getch();
		if (c == -32)
		{
			c = _getch();
		}
		//клавиши
		if (c == 72)
		{
			op = (op + n_op - 1) % n_op;
		}
		if (c == 80)
		{
			op = (op + 1) % n_op;
		}
		if (c == 27)
		{
			break;
		}
		if (c == 13)
		{
			if (c == 13)
			{
				switch (op)
				{
					case 0://ввод hand
					{
						cout << "Введите матрицу A (" << n * n <<" чисел)\n";
						cin >> a;
						cout << "Введите матрицу B (" << n * n << " чисел)\n";
						cin >> b;

					}
					break;

					case 1://ввод auto
					{
						for (size_t i = 0; i < n; i++)
							for (size_t j = 0; j < n; j++)
								a[i][j] = rand() % 100 + 1;

						for (size_t i = 0; i < n; i++)
							for (size_t j = 0; j < n; j++)
								b[i][j] = rand() % 100 + 1;
					}
					break;

				    case 2://+
					{
                        TDynamicMatrix<int> res(n);
						res = a + b;
						cout << "Ответ:\n";
						cout << res;
						system("pause");
					}
					break;
					
					case 3://-
					{
						
						TDynamicMatrix<int> res(n);
						res = a - b;
						cout << "Ответ:\n";
						cout << res;
						system("pause");
					}
					break;
					
					case 4://*
					{
						TDynamicMatrix<int> res(n);
						res = a * b;
						cout << "Ответ:\n";
						cout << res;
						system("pause");
					}
					break;
					
					case 5://*v
					{
						TDynamicVector<int> v(n);
						TDynamicVector<int> res(n);
						cout << "Введите вектор длины " << n << ": ";
						cin >> v;
						res = a * v;
						cout << "Ответ:\n";
						cout << res;
						system("pause");
					}
					break;
					
					case 6://*sk
					{
						int val;
						cout << "Введите один скаляр: ";
						cin >> val;
						cout << "Ответ:\n";
						cout << a * val;
						system("pause");
					}
					break;
					
					case 7://вывод
					{
						cout << "Матрица A:\n" << a;
						cout << "Матрица B:\n" << b;
						system("pause");
					}
					break;
				}
				
			}
		}
	}
}