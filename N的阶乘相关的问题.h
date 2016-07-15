#include"Configer.h"

namespace stepMultiply
{
	/*计算出N的阶乘中的末尾 0 的个数*/
	/*方式一*/
	void nStepMultiply(int Num)
	{
		int result = 1, tmp, Nums = 0;
		while (Num--)
			result *= (Num+1);
		tmp = result;
		while (tmp)
		{
			if (tmp % 5 == 0)
			{
				tmp /= 5;
				Nums++;
			}

			else
				break;
		}
		cout << "N! 结果为 :" << result << endl << "零的个数为：" << Nums << endl;
	}

	/*方式二：不用计算阶乘的结果直接求得*/
	void nStepMultiply2(int Num)
	{
		int result = 0;
		while (Num)
		{
			result += Num / 5;
			Num /= 5;
		}
		cout << result << endl;
	}

	/*计算出N的阶乘中的末尾二进制1的位置*/
	void positionOfLastOne(int Num)
	{
		int result = 1;
		while (Num)
		{
			result += Num / 2;
			Num /= 2;
		}
		cout << "The Last One In Num Position is :" << result << endl;
	}
}