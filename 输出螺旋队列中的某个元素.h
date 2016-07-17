#include"Configer.h"

namespace spiralMatrix
{
	/*内螺旋：（从内圈往外圈依次增大）*/
	int printfSpiralMatrix(int x,int y)
	{
		int Max = abs(x) > abs(y) ? abs(x) : abs(y);
		int Result;
		if (Max == x)          // x 正半轴
		{
			if (Max == -y)     //会突变
				Result = pow((Max * 2 + 1), 2);
			else
				Result = pow((Max * 2 - 1), 2) + Max + y;
		}
		else if (Max == -x)    // x 负半轴
			Result = pow((Max * 2 - 1), 2) + 5 * Max - y;
		else if (Max == y)     // y 正半轴
			Result = pow((Max * 2 - 1), 2) + 3 * Max - x;
		else                   // y 负半轴
			Result = pow((Max * 2 - 1), 2) + 7 * Max + x;
		return Result;
	}
	void Test()
	{
		int x, y;
		while (1)
		{
			cout << "Please Input Position (x,y):" << endl;
			cin >> x >> y;
			cout << printfSpiralMatrix(x, y) << endl;
		}
	}



	/*外螺旋：（从外圈往内圈一次增大）*/
#define SIZE 5
	void showSpiralMatrix(int array[][SIZE])
	{
		int x, y, times = 0;
		for (int size = SIZE; size >= 1; size -= 2)
		{
			cout << "The " << times + 1 << " circle" << endl;
			x = y = times++;
			if (size == 1)
			cout << array[x][y];
			for (int i = 0; i < size - 1; i++)
			{
				cout << array[x][y] << " ";
				y++;
			}
			for (int i = 0; i < size - 1; i++)
			{
				cout << array[x][y] << " ";
				x++;
			}
			for (int i = 0; i<size - 1; i++)
			{
				cout << array[x][y] << " ";
				y--;
			}
			for (int i = 0; i<size - 1; i++)
			{
				cout << array[x][y] << " ";
				x--;
			}
			cout << endl;
		}
	}
	

	void Test2()
	{
		int a[][SIZE] = { { 1,2,3,4,5 }, { 16,17,18,19,6 }, 
						  { 15,24,25,20,7 }, { 14,23,22,21,8 }, 
						  { 13,12,11,10,9 } };
		showSpiralMatrix(a);
	}


}