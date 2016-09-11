/*寻找素数*/
void findPrime(int num)
{
	int* arr = new int[num + 1]();
	for (int i = 2; i < num; ++i)
	{
		if (arr[i] == 1)
			continue;
		for (int j = i + i; j <= num; j += i)
		{
			arr[j] = 1;
		}
	}
	int count = 0;
	for (int i = 1; i <= num; ++i)
	{
		if (arr[i] == 0)
		{
			cout << i << " ";
			if (++count % 10 == 0)
				cout << endl;
		}

	}
	delete[] arr;
}