#include<iostream>
#include<assert.h>
using namespace std;

/*2016年京东在线笔试题*/
/*看烽火对数*/
//1 2 3 
//结果为：3
int Answer(int num, int*arr)
{
	int count = 0;
	int Max;
	for (int i = 0; i < num - 1; ++i)
	{
		count++;
		Max = i + 1;
		for (int j = i + 1; j < num; ++j)
		{
			if (arr[j] > arr[Max])
			{
				Max = j;
				count++;
			}
		}
	}
	cout << endl << count << endl;

	return 0;
}



int main()
{
	int num;
	cout << "Please input mountain numbers :";
	cin >> num;
	assert(num >= 3 && num <= 1000000);
	cout << endl << "Please input mountain height:";
	int* arr = new int[num];
	for (int i = 0; i < num; ++i)   //initalize data
		cin >> arr[i];
	Answer(num, arr);
	delete[] arr;
	return 0;
}



/*从 2 进制到 N-1 进制的各个位之和的平均数*/
// 5 的 2 进制为 1010， 3 进制为 12, 4 进制为 11 
// 结果为： 7/3
int sum(int num, int bit)
{
	int sum = 0, count = 0;
	while ((num -= bit) > 0)
	{
		++sum;
		if (++count % bit == 0)
		{
			sum -= (bit - 1);
		}
	}
	sum = sum + num + bit;
	return sum;
}

int main()
{
	int num;
	cout << "Please input num:";
	cin >> num;
	assert(num >= 1 && num <= 5000);
	cout << "input successful!" << endl;

	int count = 0;
	for (int i = 2; i < num; ++i)
		count += sum(num, i);
	cout << count << "/" << num-2 << endl;
}