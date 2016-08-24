#include"Configer.h"

class unionset
{
public:
	unionset(int size = 0)
	{
		_unionset.resize(size, -1);
	}
	void Merge(int index1, int index2)
	{
		int root1 = FindAncestor(index1);
		int root2 = FindAncestor(index2);
		_unionset[root1] += _unionset[root2];
		_unionset[root2] = root1;
	}
	int FindAncestor(int index)
	{
		while (_unionset[index] >= 0)
		{
			index = _unionset[index];
		}
		return index;
	}
	bool IsOneSet(int index1,int index2)
	{
		int root1 = FindAncestor(index1);
		int root2 = FindAncestor(index2);
		return root1 == root2;
	}
private:
	vector<int> _unionset;
};

int main()
{
	unionset u(10);
	u.Merge(0, 6);
	u.Merge(0, 7);
	u.Merge(0, 8);
	u.Merge(1, 4);
	u.Merge(1, 9);
	u.Merge(2, 3);
	u.Merge(2, 5);
	
	u.Merge(0, 1);

	cout << u.IsOneSet(9, 3) << endl;
}