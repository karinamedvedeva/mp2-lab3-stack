#pragma once
#include <string>
#include "Stack.h"
using namespace std;

class Calculator
{
	string formula;
	Stack <char> st_c; 
	Stack <double> st_d;
	string infix;
	string postfix; 
	int Priority(char elem);
public:
	Calculator() :st_c(10), st_d(10)
	{
		infix = "";
		postfix = "";
	}
	void SetFormula(string str)
	{
		formula = str; 
	}
	bool CheckBrackets();
	void ToPostfix(); //������� � ����������� �����
	double CalcPostfix(); //���������� ��������� � ����������� �����
};

