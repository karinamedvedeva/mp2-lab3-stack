#include "Calculator.h"

bool Calculator::CheckBrackets()
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

int Calculator::Priority(char elem)
{
	if (elem == ')')
	{
		return 0;
	}
	if (elem == '+')
	{
		return 1;
	}
	if (elem == '-')
	{
		return 1;
	}
	if (elem == '*')
	{
		return 2;
	}
	if (elem == '/')
	{
		return 2;
	}
	if (elem == '^')
	{
		return 3;
	}
}


void Calculator::ToPostfix()
{
	postfix = "";
	string src = "(" + infix + ")";
	unsigned i = 0;
	st_c.Clear();
	char elem = '!';
	while (i < src.size())
	{
		if (src[i] == '(')
		{
			st_c.Push(src[i]);
		}
		if (src[i] >= '0' && src[i] <= '9')
		{
			postfix += src[i];
		}
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
		if (src[i] == ')')
		{
			elem = st_c.Pop();
			do
			{
				postfix += elem;
				elem = st_c.Pop();
			} while (elem != ')');
		}
		i++;
	}
}

double Calculator::CalcPostfix()
{
	st_d.Clear();
	int unsigned i = 0;
	while (i < postfix.size())
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			double tmp = 0;
			if (postfix[i] >= 48 && postfix[i] <= 57)
			{
				tmp += postfix[i] - '0';
			}
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
					st_d.Push(k2 - k1);
					break;
				}
				case'*':
				{
					st_d.Push(k2 * k1);
					break;
				}
				case'/':
				{
					st_d.Push(k2 / k1);
					break;
				}
				/*case'^':
				{
					st_d.Push(k2 ^ k1);
					break;
				}*/
				}
			}
			i++;
			if (st_d.Empty())
			{
				throw st_d;
			}
			else
			{
				st_d.Pop();
				if (st_d.Empty())
				{
					return st_d.Pop();
				}
			}
		}
	}
}

