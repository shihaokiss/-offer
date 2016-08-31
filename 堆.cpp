#include"Configer.h"

/*堆*/
class Heap
{
public:
	Heap(const vector<int>& Vector)
	{
		_array = Vector;
		for (int i = (_array.size() - 2) / 2; i >= 0; i--)
		{
			AdjustDown(i);
		}
	}

	Heap& operator = (const Heap& h)
	{
		if (this != &h)
		_array = h._array;
		return *this;
	}

	void Push(int num)
	{
		_array.push_back(num);
		AdjustUp();
	}
	void Pop()
	{
		std::swap(_array[0], _array[_array.size() - 1]);
		_array.pop_back();
		AdjustDown(0);
	}
	int GetTop()
	{
		return _array[0];
	}
private:
	vector<int> _array;
protected:
	void AdjustDown(int index);
	void AdjustUp();
};

void Heap::AdjustDown(int index)
{
	int back = _array.size();      //"[)"
	int child = index * 2 + 1;
	while (child < back)
	{
		if (child + 1 < back && _array[child + 1] > _array[child])
		{
			child++;
		}
		if (_array[child] > _array[index])
		{
			std::swap(_array[child], _array[index]);
			index = child;
			child = 2 * child + 1;
		}
		else
			break;
	}
}

void Heap::AdjustUp()
{
	int child = _array.size() - 1;
	int father = (child - 1) / 2;
	while (child > 0)
	{
		if (_array[child] > _array[father])
			std::swap(_array[child], _array[father]);
		child = father;
		father = (father - 1) / 2;
	}
}

//void Test()
//{
//	vector<int> V = { 6, 7, 8, 9, 10 };
//	Heap H(V);
//	cout << H.GetTop() << endl;
//	H.Pop();
//	cout << H.GetTop() << endl;
//	H.Pop();
//	cout << H.GetTop() << endl;
//	H.Pop();
//	cout << H.GetTop() << endl;
//	H.Pop();
//	cout << H.GetTop() << endl;
//	H.Pop();
//}

/*优先级队列*/

class PriQueue
{
public:
	PriQueue(const vector<int>& V)
		:_heap(Heap(V))
	{}

	void Push(int num)
	{
		_heap.Push(num);
	}
	void Pop()
	{
		_heap.Pop();
	}
	int GetTop()
	{
		return _heap.GetTop();
	}
private:
	Heap _heap;
};

//void Test2()
//{
//	vector<int> V = { 6, 7, 8, 9, 10 };
//	PriQueue P(V);
//	cout << P.GetTop() << endl;
//	P.Pop();
//	cout << P.GetTop() << endl;
//	P.Pop();
//	cout << P.GetTop() << endl;
//	P.Pop();
//	cout << P.GetTop() << endl;
//	P.Pop();
//	cout << P.GetTop() << endl;
//	P.Pop();
//	P.Push(1);
//	P.Push(2);
//	P.Push(3);
//	cout << P.GetTop() << endl;
//	P.Pop();
//	cout << P.GetTop() << endl;
//	P.Pop();
//	cout << P.GetTop() << endl;
//	P.Pop();
//}
//void main()
//{
//	Test2();
//}
