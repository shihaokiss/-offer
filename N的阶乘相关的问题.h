#include"Configer.h"

namespace stepMultiply
{
	/*�����N�Ľ׳��е�ĩβ 0 �ĸ���*/
	/*��ʽһ*/
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
		cout << "N! ���Ϊ :" << result << endl << "��ĸ���Ϊ��" << Nums << endl;
	}

	/*��ʽ�������ü���׳˵Ľ��ֱ�����*/
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

	/*�����N�Ľ׳��е�ĩβ������1��λ��*/
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