#pragma once
#include"Configer.h"
namespace MyQueue
{
	template<class T>
	class MyQueue
	{
	public:
		void Push(const T& Data)
		{
			S1.push(Data);
		}
		void Pop()
		{
			if (S2.empty())
			{
				while (!S1.empty())
				{
					S2.push(S1.top());
					S1.pop();
				}
			}
			if (!S2.empty())
				S2.pop();
			else
				cout << "Queue is Empty" << endl;
		}
	private:
		stack<T> S1;
		stack<T> S2;
	};

	void Test()
	{
		MyQueue<int> _MyQueue;
		_MyQueue.Pop();
		vector<int> Vector = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		for (int i = 0; i < Vector.size(); ++i)
			_MyQueue.Push(Vector[i]);

		_MyQueue.Pop();
		_MyQueue.Pop();
		_MyQueue.Pop();
		_MyQueue.Pop();
	}
}
