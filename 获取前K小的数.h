#include"Configer.h"

namespace SmallK
{
	/*利用multiset*/
	typedef multiset<int, greater<int>> inset;
	typedef multiset<int, greater<int>>::iterator setIterator;

	void GetFirstKSmall(vector<int>& Vector, int K)
	{
		if (Vector.size() < K || Vector.size() == 0)
			return;
		inset Inset;
		vector<int>::iterator It = Vector.begin();
		for (; It != Vector.end(); ++It)       /*获取前K大的数*/
		{
			if (Inset.size() < K)
				Inset.insert(*It);
			else
			{
				if (*It < *Inset.begin())
				{
					Inset.erase(Inset.begin());
					Inset.insert(*It);
				}
			}
		}

		/*输出前K大的数*/
		cout << "前K小的数为:" << endl;
		setIterator Iterator = Inset.begin();
		while (Iterator != Inset.end())
			cout << *Iterator++ << " ";
		cout << endl;
	}

	void Test()
	{
		vector<int> Vector;
		for (int i = 0; i < 100; ++i)
			Vector.push_back(rand() % 100);
		GetFirstKSmall(Vector, 6);
	}
	/*利用堆*/


}
