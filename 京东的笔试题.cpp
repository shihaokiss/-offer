#include<iostream>
#include<assert.h>
using namespace std;

/*2016�꾩�����߱�����*/
/*��������*/
//1 2 3 
//���Ϊ��3
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



/*�� 2 ���Ƶ� N-1 ���Ƶĸ���λ֮�͵�ƽ����*/
// 5 �� 2 ����Ϊ 1010�� 3 ����Ϊ 12, 4 ����Ϊ 11 
// ���Ϊ�� 7/3
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