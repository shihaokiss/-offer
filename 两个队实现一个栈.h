#pragma once
#include"Configer.h"

namespace MyStack
{
	template<class T>
	class MyStack
	{
	public:
		void Push(const T& Data)
		{
			Q1.empty() == 1 ? Q2.push(Data) : Q1.push(Data);
		}
		void PoP()
		{
			if (!Q1.empty())
			{
				while (Q1.size() > 1)
				{
					Q2.push(Q1.front());
					Q1.pop();
				}
				Q1.pop();
			}
			else
			{
				while (Q2.size() > 1)
				{
					Q1.push(Q2.front());
					Q2.pop();
				}
				Q2.pop();
			}
		}
	private:
		queue<T> Q1;
		queue<T> Q2;
	};


	void Test()
	{
		MyStack<int> _MyStack;
		vector<int> Vector = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		for (int i = 0; i < Vector.size();++i)
		_MyStack.Push(Vector[i]);

		_MyStack.PoP();
		_MyStack.PoP();
		_MyStack.PoP();
		_MyStack.PoP();
	}
}


