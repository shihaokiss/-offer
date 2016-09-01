int SnackMatrix(int N)
{
	int num = 1, circle = (N+1) / 2 ;
	vector<vector<int>> Vector(N);
	for (int i = 0; i < N; ++i)
	{
		Vector[i].resize(N);
	}
	for (int i = 0; i < circle; ++i)
	{
		int grep = N - 2 * i - 1, j = 0;
		while (grep - j)
		{
			Vector[i][i+j] = num++;
			j++;
		}
		j = 0;
		while (grep - j)
		{
			Vector[i+j][i + grep] = num++;
			j++;
		}
		j = grep;
		while (j)
		{
			Vector[i + grep][i+j] = num++;
			j--;
		}
		j = grep;
		while (j)
		{
			Vector[i+j][i] = num++;
			j--;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << Vector[i][j] << " ";
		cout << endl;
	}
	return 0;
}