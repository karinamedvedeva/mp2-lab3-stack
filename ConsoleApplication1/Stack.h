#pragma once
template <class T>
class Stack
{
	int size, MaxSize;
	T* mas;
public:
	Stack (int _MaxSize)
	{
		MaxSize = _MaxSize;
		mas = new T[MaxSize];
		size = 0;
	}

	Stack (const Stack <T>& m) //конструктор копирования
	{
		MaxSize = m.MaxSize;
		mas = new T[MaxSize];
		size = m.size;
		for (int i = 0; i < size; i++)
		{
			mas[i] = m.mas[i];
		}
	}

	~Stack() //деструктор
	{
		delete[]mas;
	}

	Stack& operator=(const Stack <T>& m)
	{
		if (MaxSize != m.MaxSize)
		{
			delete[]mas;
			MaxSize = m.MaxSize;
			mas = new T[MaxSize];
		}
		size = m.size;
		for (int i = 0; i < size; i++)
		{
			mas[i] = m.mas[i];
		}
		return *this;
	}

	bool Empty()
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}

	bool Full()
	{
		if (size == MaxSize)
		{
			return true;
		}
		return false;
	}

	void Push(T a)
	{
		if (Full())
		{
			throw MaxSize;
		}
		mas[size] = a;
		size++;
	}

	T Pop()
	{
		if (Empty())
		{
			throw 0;
		}
		size--;
		return mas[size];
	}

};
