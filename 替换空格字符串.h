#pragma once
#include"Configer.h"

namespace String
{
	/*利用 %20 替换 空格*/
	void ReplaceBlankSpace(char* arr)
	{
		if (arr)
		{
			int count = 0;
			int lenth = strlen(arr);
			for (int i = 0; i < lenth;++i)
			if (arr[i] == ' ')
				count++;
			char*before = arr+lenth, *behind = arr+lenth+2*count;
			while (before != behind)
			{
				if (*before != ' ')
				{
					*behind-- = *before--;
				}				
				else
				{
					*behind-- = '0';
					*behind-- = '2';
					*behind-- = '%';
					before--;
				}
			}
		}
	}

	/*合并两个有序的数组,时间复杂度O(N)/空间复杂度O(1) */
	void ArrayMerage(vector<int>& Vector1, vector<int>& Vector2)
	{
		int index_1_before = Vector1.size() - 1, index_2 = Vector2.size() - 1;
		int sum = Vector1.size() + Vector2.size();
		int index_1_behind = sum - 1;
		Vector1.resize(sum);
		while (index_2 >= 0 && index_1_before >= 0)

			Vector1[index_1_behind--] = Vector1[index_1_before] > Vector2[index_2] ? \
			Vector1[index_1_before--] : Vector2[index_2--];
		while (index_2 >= 0)
			Vector1[index_1_behind--] = Vector2[index_2--];
	}

	void Show(vector<int>& Vector)
	{
		for (int i = 0; i<Vector.size(); ++i)
			cout << Vector[i] << " ";
		cout << endl;
	}

	void Test()
	{
		vector<int> Vector1 = { 0, 2, 4, 6, 8 };
		vector<int> Vector2 = { -10, -9, -8, -7, -6 };
		Show(Vector1);
		ArrayMerage(Vector1, Vector2);
		Show(Vector1);

	}
}

