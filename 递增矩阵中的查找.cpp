int arr[][5] = { { 0, 1, 2, 3, 4 }, { 5, 6, 7, 8, 9 }, { 10, 11, 12, 13, 14 },
{ 15, 16, 17, 18, 19 }, { 20, 21, 22, 23, 24 } };
bool FindInMatrixFromTopRightCorner(int(*Matrix)[5], int Row, int Find)
{
	int i = 0, j = 4, tmp = Matrix[0][4];
	while (i <= 4)
	{
		if (Find > Matrix[i][j])
			i++;
		else if (Find == tmp)
		{
			cout << "Row : " << i << endl << "Line : " << j << endl;
			return true;
		}

		else
		{
			while (j >= 0)
			{
				if (Find < Matrix[i][j])
					--j;
				else if (Find == Matrix[i][j])
				{
					cout << "Row : " << i << endl << "Line : " << j << endl;;
					return true;
				}
				else
					return false;
			}
			return false;
		}
	}
	return false;
}

bool FidnInMatrixFromBottomLeftCorner(int(*Matrix)[5], int Row, int Find)
{
	int i = Row - 1, j = 0;
	while (i >= 0)
	{
		if (Find < Matrix[i][j])
			i--;
		else if (Find == Matrix[i][j])
		{
			cout << "Row : " << i << endl << "Line : " << j << endl;
			return true;
		}
		else
		{
			while (j <= 4)
			{
				if (Find > Matrix[i][j])
					j++;
				else if (Find == Matrix[i][j])
				{
					cout << "Row : " << i << endl << "Line : " << j << endl;
					return true;
				}
				else
					return false;
			}
			return false;
		}
	}
	return false;
}