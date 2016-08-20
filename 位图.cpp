#include"Configer.h"

class BitMap
{
public:
	BitMap(vector<size_t>& V)
	{
		size_t Max = V[0];
		for (int i = 0; i < V.size(); ++i)
		{
			if (V[i] > Max)
			{
				Max = V[i];
			}
		}
		_bitMap.resize((Max >> 5) + 1);
		for (int i = 0; i < V.size(); ++i)
		{
			SetBitMap(V[i]);
		}
	}

	void SetBitMap(size_t i)
	{
		size_t index = i >> 5;
		char bit = i % 32;
		_bitMap[index] |= (0x00000001 << bit);
	}
	void ReMove(size_t i)
	{
		size_t index = i >> 5;
		char bit = i % 32;
		_bitMap[index] &= (~(0x00000001 << bit));
	}
	bool Find(size_t i)
	{
		size_t index = i >> 5;
		char bit = i % 32;
		return _bitMap[index] & (0x00000001 << bit);
	}
private:
	vector<size_t> _bitMap;
};


//int main()
//{
//	vector<size_t> Vector = { 0, 33, 65, 97 };
//	BitMap b(Vector);
//	for (int i = 0; i < 100; ++i)
//	{
//		if (b.Find(i))
//		{
//			cout << i << " is in bitMap" << endl;
//		}
//		else
//		{
//			cout << i << " not in bitMap" << endl;
//		}
//	}
//	return 0;
//}
