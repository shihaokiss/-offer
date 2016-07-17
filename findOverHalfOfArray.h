#include"Configer.h"

namespace findOverHalfOfArray   
{
	/*寻找超过一半的数*/
	int findOverHalfOfArray_1(int array[], int N)
	{
		assert(array);
		stack<int> Stack;
		for (int i = 0; i < N; ++i)
		{
			if (Stack.empty())
				Stack.push(array[i]);
			else if (Stack.top() != array[i])
			Stack.pop();
			else
				Stack.push(array[i]);
		}
		cout << "The OverHalfOfArray Number is : " << Stack.top() << endl;
		return Stack.top();
	}

	int findOverHalfOfArray_2(int array[], int N)
	{
		assert(array);
		int tmp, times = 0;

		for (int i = 0; i < N; ++i)
		{
			if (times == 0)
			{
				tmp = array[i];
				times++;
			}
			else
			{
				tmp == array[i] ? ++times : --times;
			}
		}
		cout << "The OverHalfOfArray Num is :" << tmp << endl;
		return tmp;
	}

	void Test()
	{
		int Array[] = { 1, 1, 1, 4, 8, 6, 4, 1, 1, 3, 1, 8, 6, 1, 0,
						0, 1, 1, 1, 1, 3, 2,1, 1, 5 };
		//findOverHalfOfArray_1(Array,25);
		findOverHalfOfArray_2(Array, 25);
	}
}