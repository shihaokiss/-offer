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

	/*寻找数组中的三个元素，这三个元素的数目均超过数组大小的1/4*/
	vector<int> findOverQuarterThreeNumsOfArray(vector<int> Vector)
	{
		vector<vector<int>> vectorArray(3);
		vector<int> vetcorResult;
		for (int i = 0; i < Vector.size(); ++i)
		{
			bool check = true;       
			for (int j = 0; j < 3; j++)
			{
				if (vectorArray[j].size() == 0 || vectorArray[j].back() == Vector[i])
				{
					vectorArray[j].push_back(Vector[i]);
					check = false;
					break;
				}
			}
			if (check)
			{
				vectorArray[0].pop_back();
				vectorArray[1].pop_back();
				vectorArray[2].pop_back();
			}
		}
		for (int i = 0; i < 3; ++i)
			vetcorResult.push_back(vectorArray[i].front());
		return vetcorResult;
	}

	vector<int> findOverQuarterThreeNumsOfArray(int* array,int size)    //重载
	{
		assert(array);
		int *points[3] = {NULL};
		int times[3] = { 0 };
		vector<int> Vector;
		for (int i = 0; i < size; ++i)
		{
			bool check = true;
			for (int j = 0; j < 3; ++j)
			{
				if (times[j] == 0 || *points[j] == array[i])
				{
					times[j]++;
					points[j] = array + i;
					check = false;
					break;
				}
			}
			if (check)
			{
				for (int i = 0; i < 3; ++i)
				{
					--times[i];
				}
			}
		}
		for (int i=0; i < 3; ++i)
			Vector.push_back(*points[i]);
		return Vector;
	}

	void Test()
	{
		vector<int> Vector1 = { 5, 2, 4, 1, 2, 1, 2, 3, 1, 3, 8, 9, 1, 2, 2, 2, 3, 2, 1, 6, 3, 3, 1, 3, 1, 3, 8 };
		vector<int> Vector2 = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 0, 0 };
		int Array[] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 0, 0 };
		//findOverHalfOfArray_1(Array,25);
		//findOverHalfOfArray_2(Array, 25);
		//findOverQuarterThreeNumsOfArray(Vector2);
		findOverQuarterThreeNumsOfArray(Array,11);
	}
}