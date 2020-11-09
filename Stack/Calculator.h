#pragma once
#include <string>
#include "Stack.h"
using namespace std;

class Calculator
{
	string formula;
	Stack <char> st_c; 
public:
	Calculator() :st_c(10) {}
	void SetFormula(string str)
	{
		formula = str; 
	}
	bool CheckBrackets();
};

bool Calculator:: CheckBrackets()
{
	for (int i = 0; i < formula.size(); i++)
	{
		if (formula[i] == '(')
		{
			if (st_c.Full())
			{
				return false;
			}
			else
			{
				st_c.Push('(');
			}
		}
		if (formula[i] == ')')
		{
			if (st_c.Empty())
			{
				return false;
			}
			else
			{
				st_c.Pop();
			}
		}	
	}
	return st_c.Empty();
}