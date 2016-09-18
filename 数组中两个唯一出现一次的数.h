/*数组中两个唯一出现一次的数字(其他都出现偶数次)*/
void findOnce(int* arr, int size, int* a, int* b)
{
	if (arr == NULL)
		return;
	*a = 0, *b = 0;
	int tmp = 0;
	for (int i = 0; i < size; ++i)
	{
		tmp ^= arr[i];
	}
	int index = 0x00000001;            //将最低不同的位统计出来
	for (int i = 0; i < 31; ++i)
	{
		if (index & tmp)
			break;
		else
			index <<= 1;
	}

	for (int i = 0; i < size; ++i)
	{
		arr[i] & index ? (*a ^= arr[i]) : (*b ^= arr[i]);
	}
}


void main()
{
	int arr[] = { 2, 4, 3, 6, 3, 2, 5, 5, 6, 4, 100, 200, 100, 201 };
	int result[2];
	findOnce(arr, sizeof(arr) / sizeof(int), result, result + 1);
	cout << result[0] << " " << result[1] << endl;
}