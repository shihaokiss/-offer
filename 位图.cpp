#include"Configer.h"
#include"Hash×Ö·û´®º¯Êý.h"
class BitMap
{
public:
	BitMap()
	{
		_bitMap.resize((0xffffffff >> 5) + 1);
	}
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

struct _Fun1
{
	size_t operator()(const string& str)
	{
		return BKDRHash(str.c_str());
	}
};
struct _Fun2
{
	size_t operator()(const string& str)
	{
		return SDBMHash(str.c_str());
	}
};
struct _Fun3
{
	size_t operator()(const string& str)
	{
		return RSHash(str.c_str());
	}
};
struct _Fun4
{
	size_t operator()(const string& str)
	{
		return APHash(str.c_str());
	}
};
struct _Fun5
{
	size_t operator()(const string& str)
	{
		return JSHash(str.c_str());
	}
};
struct _Fun6
{
	size_t operator()(const string& str)
	{
		return DEKHash(str.c_str());
	}
};

template<class Fun1 = _Fun1,
		 class Fun2 = _Fun2,
		 class Fun3 = _Fun3, 
		 class Fun4 = _Fun4,
		 class Fun5 = _Fun5, 
		 class Fun6 = _Fun6>
class Bloom
{
public:
	Bloom(vector<string>& V = vector<string>())
	{
		
		for (int i = 0; i < V.size(); ++i)
		{
			SetBitMap(V[i]);
		}
	}
	void SetBitMap(const string& str)
	{
		value[0] = _Fun1()(str);
		value[1] = _Fun2()(str);
		value[2] = _Fun3()(str);
		value[3] = _Fun4()(str);
		value[4] = _Fun5()(str);
		value[5] = _Fun6()(str);
		for (int i = 0; i < 6; ++i)
		{
			_bitMap.SetBitMap(value[i]);
		}
	}

	bool Check(const string& str)
	{
		value[0] = _Fun1()(str);
		value[1] = _Fun2()(str);
		value[2] = _Fun3()(str);
		value[3] = _Fun4()(str);
		value[4] = _Fun5()(str);
		value[5] = _Fun6()(str);
		return _bitMap.Find(value[0]) && _bitMap.Find(value[1]) &&
			_bitMap.Find(value[2]) && _bitMap.Find(value[3]) &&
			_bitMap.Find(value[4]) && _bitMap.Find(value[5]);
	}
private:
	BitMap _bitMap;
	size_t value[6];
};


int main()
{
	vector<string> Vector = { "Ê¯ºÀ", "aaaaa", "bbbbbb", "ccccccc", "dddddddd" };
	Bloom<> b(Vector);
	cout << b.Check("aaaaa") << endl;
	cout << b.Check("aaaaaa") << endl;
	cout << b.Check("Ê¯ºÀ") << endl;
	cout << b.Check("Ê¯ºÀa") << endl;
	b.SetBitMap("Ê¯ºÀa");
	cout << b.Check("Ê¯ºÀa") << endl;
	cout << b.Check("Íõ°Ëµ°") << endl;
	return 0;
}
