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
	///����� ����� ��������������� \\\
	
	double step, n;
	cout << "������� ����� ��������:\n";
	cin >> n;
	step = (integration_range2 - integration_range1) / n;

	double result = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		result += function(integration_range1 + i * step) * step;
	}
	cout << "��������� ���������� ���������:  " << result;
}

void medium_rectangle_method(double integration_range1, double integration_range2)
{
	///����� ������� ��������������� \\\
	
	double step, n;
	cout << "������� ����� ��������:\n";
	cin >> n;
	step = (integration_range2 - integration_range1) / n;

	double result = 0;
	for (double i = 0.5; i <= n - 0.5; i++)
	{
		result += function(integration_range1 + i * step) * step;
	}
	cout << "��������� ���������� ���������:  " << result;
}

void right_rectangle_method(double integration_range1, double integration_range2)
{
	///����� ������ ��������������� \\\
	
	double step, n;
	cout << "������� ����� ��������:\n";
	cin >> n;
	step = (integration_range2 - integration_range1) / n;

	double result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += function(integration_range1 + i * step) * step;
	}
	cout << "��������� ���������� ���������:  " << result;
}

void rectangle_method(double integration_range1, double integration_range2)
{
	cout << "�������� �����: \n" << "��� ����� ��������������� - 1\n" << "��� ������� ��������������� - 2\n" << "��� ������ ��������������� - 3\n" << "��� ������ - 0\n";
	int method0;
	cin >> method0;

	switch (method0)
	{
	case 1: left_rectangle_method(integration_range1, integration_range2); break;
	case 2: medium_rectangle_method(integration_range1, integration_range2); break;
	case 3: right_rectangle_method(integration_range1, integration_range2); break;
	default: cout << "������ �����!!!\n";
	}
}

void trapezoid_method(double integration_range1, double integration_range2)
{
	///����� �������� \\\
	
	double step, n;
	cout << "������� ����� ��������:\n";
	cin >> n;
	step = (integration_range2 - integration_range1) / n;

	double result = function(integration_range1) + function(integration_range2);
	for (int i = 1; i <= n - 1; i++)
	{
		result += function(integration_range1 + i*step)* 2;
	}
	result *= step / 2;
	cout << "��������� ���������� ���������:  " << result;
}

void Simpson_method(double integration_range1, double integration_range2)
{
	///����� �������� \\\
	
	double step, n;
	int k;
	cout << "������� ����� ��������:\n";
	cin >> n;
	step = (integration_range2 - integration_range1) / n;

	double result = function(integration_range1) + function(integration_range2);
	for (int i = 1; i <= n - 1; i++)
	{
		k = 2 + (i % 2) * 2;
		result += function(integration_range1 + i * step) * k;
	}
	result *= step / 3;
	cout << "��������� ���������� ���������:  " << result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int x = 0;

	cout << "�������� ������ ��� ���������� ���������:\n" << "������� ��������������� - 1\n" << "������� �������� - 2\n" << "������� �������� - 3\n" << "��� ������ - 0\n";

	int choice_method;
	cin >> choice_method;

	cout << "������� ������ ������ ��������������:\n";
	double integration_range1;
	cin >> integration_range1;

	cout << "������� ������� ������ ��������������:\n";
	double integration_range2;
	cin >> integration_range2;

	switch (choice_method)
	{
	case 1: rectangle_method(integration_range1, integration_range2); break;
	case 2: trapezoid_method(integration_range1, integration_range2); break;
	case 3: Simpson_method(integration_range1, integration_range2); break;
	default: printf("������ �����!!!\n");
	}

}