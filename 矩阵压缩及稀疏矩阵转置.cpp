#include"Configer.h"

/*¶Ô³Æ¾ØÕóµÄÑ¹Ëõ*/
//class comPressMatrix
//{
//public:
//	comPressMatrix(vector<vector<int>>& Vector)
//	{
//		int n = Vector.size();
//		_vector.resize(n*(n + 1) / 2);
//		for (int i = 0; i < Vector.size(); ++i)
//		{
//			for (int j = 0; j < i; ++j)
//			{
//				_vector[i*(i + 1) / 2 + j] = Vector[i][j];
//			}
//		}
//	}
//	void uncomPressMatrix(vector<vector<int>>& Vector)
//	{
//		for (int i = 0; i < Vector.size(); ++i)
//		{
//			for (int j = 0; j < Vector.size(); ++j)
//			{
//				if (i >= j)
//					Vector[i][j] = _vector[i*(i + 1) / 2 + j];
//				else
//					Vector[i][j] = _vector[j*(j + 1) / 2 + i];
//			}
//		}
//	}
//private:
//	vector<int> _vector;
//};
//
//
//void main()
//{
//	vector<vector<int>> Vector = { { 0, 1, 1, 1 }, { 1, 0, 1, 1 }, { 1, 1, 0, 1 }, { 1, 1, 1, 0 } };
//	vector<vector<int>> VectorDst = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };
//	comPressMatrix test(Vector);
//	test.uncomPressMatrix(VectorDst);
//}

/*Ï¡Êè¾ØÕóµÄ²Ù×÷*/
struct Node
{
	Node(int r = 0,int c = 0,int v = 0)
		:row(r), col(c), value(v)
	{}
	int row;
	int col;
	int value;
};

class SpareMatrix
{
public:
	SpareMatrix(vector<vector<int>>& Vector)
		:row(Vector.size()), col(Vector[0].size())
	{
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (Vector[i][j] != 0)
				{
					_vector.push_back(Node(i, j, Vector[i][j]));
				}
			}
		}
	}
	void uncompressSpareMatrix(vector<vector<int>>& Vector)
	{
		int count = 0;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (count < _vector.size() && i == _vector[count].row && j == _vector[count].col)
				{
					Vector[i][j] = _vector[count].value;
					count++;
				}
				else
					Vector[i][j] = 0;
			}
		}
	}

	void transportMatrix1()    //×ªÖÃ1
	{
		vector<Node> V;
		int count = _vector.size();
		for (int i = 0; i < col; ++i)
		{
			for (int j = 0; j < count; j++)
			{
				if(_vector[j].col == i)
				V.push_back(Node(_vector[j].col, _vector[j].row,_vector[j].value));
			}
		}
		_vector = V;
		std::swap(row, col);
	}

	void transportMatrix2()    //×ªÖÃ2
	{
		vector<int> rowCount(col), rowStart(col);
		vector<Node> V(_vector.size());
		for (int i = 0; i < _vector.size(); ++i)
		{
			rowCount[_vector[i].col]++;
		}
		for (int i = 1; i < col; ++i)
		{
			rowStart[i] = rowCount[i - 1] + rowStart[i - 1];
		}

		for (int i = 0; i < _vector.size(); ++i)
		{
			int index = rowStart[_vector[i].col]++;
			V[index].row = _vector[i].col;
			V[index].col = _vector[i].row;
			V[index].value = _vector[i].value;
		}
		_vector = V;
		std::swap(row, col);
	}
private:
	vector<Node> _vector;
	int row;
	int col;
};


void main()
{
	vector<vector<int>> V = 
							{ { 0, 0, 1, 0, 0 },
							{ 2, 2, 0, 0, 0 },
							{ 3, 0, 0, 0, 3 },
							{ 4, 0, 4, 0, 0 } };
	vector<vector<int>> VDst =
							{ { -1, -1, -1, -1, -1 },
							{ -1, -1, -1, -1, -1 },
							{ -1, -1, -1, -1, -1 },
							{ -1, -1, -1, -1, -1 } };
	SpareMatrix S(V);
	S.transportMatrix1();
	S.transportMatrix2();
	S.uncompressSpareMatrix(VDst);
}