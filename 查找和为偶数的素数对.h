/*寻找素数对*/
int* findPrime(int num)
{
	int* arr = new int[num + 1]();
	arr[1] = 1;
	for (int i = 2; i < num; ++i)
	{
		if (arr[i] == 1)
			continue;
		for (int j = i + i; j <= num; j += i)
		{
			arr[j] = 1;
		}
	}

	return arr;
}

void main()
{
	int* ptr = findPrime(1000);
	int num, count = 0;
	cin >> num;
	for (int i = 1; i < num; ++i)
	{
		if (ptr[i] == 0 && ptr[num - i] == 0)
		{
			cout << i << "+" << num - i << "=" << num << endl;
			count++;
		}
	}
	if (ptr[num / 2] == 0)
		++count;
	cout << "共 " << count / 2 << " 对" << endl;

	delete[] ptr;
}