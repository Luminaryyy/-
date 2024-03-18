#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;


double function(double x)
{
	return x * x - 8;
}

void left_rectangle_method(double integration_range1, double integration_range2)
{
	///Метод левых прямоугольников \\\
	
	double step, n;
	cout << "Введите число итераций:\n";
	cin >> n;
	step = (integration_range2 - integration_range1) / n;

	double result = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		result += function(integration_range1 + i * step) * step;
	}
	cout << "Результат вычисления интеграла:  " << result;
}

void medium_rectangle_method(double integration_range1, double integration_range2)
{
	///Метод средних прямоугольников \\\
	
	double step, n;
	cout << "Введите число итераций:\n";
	cin >> n;
	step = (integration_range2 - integration_range1) / n;

	double result = 0;
	for (double i = 0.5; i <= n - 0.5; i++)
	{
		result += function(integration_range1 + i * step) * step;
	}
	cout << "Результат вычисления интеграла:  " << result;
}

void right_rectangle_method(double integration_range1, double integration_range2)
{
	///Метод правых прямоугольников \\\
	
	double step, n;
	cout << "Введите число итераций:\n";
	cin >> n;
	step = (integration_range2 - integration_range1) / n;

	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += function(integration_range1 + i * step) * step;
	}
	cout << "Результат вычисления интеграла:  " << result;
}

void rectangle_method(double integration_range1, double integration_range2)
{
	cout << "Выберите метод: \n" << "Для левых прямоугольников - 1\n" << "Для средних прямоугольников - 2\n" << "Для правых прямоугольников - 3\n" << "Для выхода - 0\n";
	int method0;
	cin >> method0;

	switch (method0)
	{
	case 1: left_rectangle_method(integration_range1, integration_range2); break;
	case 2: medium_rectangle_method(integration_range1, integration_range2); break;
	case 3: right_rectangle_method(integration_range1, integration_range2); break;
	default: cout << "Ошибка ввода!!!\n";
	}
}

void trapezoid_method(double integration_range1, double integration_range2)
{
	///Метод трапеции \\\
	
	double step, n;
	cout << "Введите число итераций:\n";
	cin >> n;
	step = (integration_range2 - integration_range1) / n;

	double result = function(integration_range1) + function(integration_range2);
	for (int i = 1; i <= n - 1; i++)
	{
		result += function(integration_range1 + i*step)* 2;
	}
	result *= step / 2;
	cout << "Результат вычисления интеграла:  " << result;
}

void Simpson_method(double integration_range1, double integration_range2)
{
	///Метод Симпсона \\\
	
	double step, n;
	int k;
	cout << "Введите число итераций:\n";
	cin >> n;
	step = (integration_range2 - integration_range1) / n;

	double result = function(integration_range1) + function(integration_range2);
	for (int i = 1; i <= n - 1; i++)
	{
		k = 2 + (i % 2) * 2;
		result += function(integration_range1 + i * step) * k;
	}
	result *= step / 3;
	cout << "Результат вычисления интеграла:  " << result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int x = 0;

	cout << "Выберите способ для вычисления интеграла:\n" << "Формула прямоугольников - 1\n" << "Формула трапеции - 2\n" << "Формула Симпсона - 3\n" << "Для выхода - 0\n";

	int choice_method;
	cin >> choice_method;

	cout << "Введите нижний предел интегрирования:\n";
	double integration_range1;
	cin >> integration_range1;

	cout << "Введите верхний предел интегрирования:\n";
	double integration_range2;
	cin >> integration_range2;

	switch (choice_method)
	{
	case 1: rectangle_method(integration_range1, integration_range2); break;
	case 2: trapezoid_method(integration_range1, integration_range2); break;
	case 3: Simpson_method(integration_range1, integration_range2); break;
	default: printf("Ошибка ввода!!!\n");
	}

}