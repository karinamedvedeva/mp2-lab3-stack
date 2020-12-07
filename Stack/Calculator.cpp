#include "Calculator.h"

void Calculator::SetFormula(string str)
{
	infix = " ";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			infix += " ";
		}
		infix += str[i];
		infix += " ";
	}
	if (!CheckBrackets())
	{
		throw 0;
	}
}

bool Calculator::CheckBrackets()
{
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
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
		if (infix[i] == ')')
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

int Calculator::Priority(char elem)
{
	if (elem == ')')
	{
		return 0;
	}
	if (elem == '(')
	{
		return 1;
	}
	if (elem == '+')
	{
		return 2;
	}
	if (elem == '-')
	{
		return 2;
	}
	if (elem == '*')
	{
		return 3;
	}
	if (elem == '/')
	{
		return 3;
	}
	if (elem == '^')
	{
		return 4;
	}
}

void Calculator::ToPostfix()
{
	if (!CheckBrackets())
	{
		throw 0;
	}
	postfix = "";
	string src = "(" + infix + ")";
	unsigned int i = 0;
	st_c.Clear();
	char elem = '!';
	while (i < src.size())
	{
		if (src[i] == '(')
		{
			st_c.Push(src[i]);
		} 
		else
		{
			if (src[i] >= '0' && src[i] <= '9')
			{
				postfix += src[i];
			}
			else
			{
				if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/' || src[i] == '^')
				{
					postfix += " ";
					elem = st_c.Pop();
					while (Priority(elem) >= Priority(src[i]))
					{
						postfix += elem;
						elem = st_c.Pop();
					}
					st_c.Push(elem);
					st_c.Push(src[i]);
				}
				else
				{
					if (src[i] == ')')
					{
						elem = st_c.Pop();
						do
						{
							postfix += elem;
							elem = st_c.Pop();
						} while (elem != '(');
					}
				}
			}
		}
		i++;
	}
}

double Calculator::CalcPostfix()
{
	if (!CheckBrackets())
	{
		throw 0;
	}
	st_d.Clear();
	unsigned int i = 0;
	char* c;
	while (i < postfix.size())
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			double tmp = strtod(&postfix[i], &c);
			int j = c - &postfix[i];
			i += j - 1;
			st_d.Push(tmp);
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			if (st_d.Empty())
			{
				throw st_d;
			}
			else
			{
				double k2 = st_d.Pop();
				double k1 = st_d.Pop();
				switch (postfix[i])
				{
				case '+':
				{
					st_d.Push(k2 + k1);
					break;
				}
				case'-':
				{
					st_d.Push(k1 - k2);
					break;
				}
				case'*':
				{
					st_d.Push(k2 * k1);
					break;
				}
				case'/':
				{
					st_d.Push(k1 / k2);
					break;
				}
				case'^':
				{
					st_d.Push(pow(k1, k2));
					break;
				}
				}
			}	
		}
		i++;
	}
	if (st_d.Empty())
	{
		throw st_d;
	}
	else
	{
		return st_d.Top();
	}
}



