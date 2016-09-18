/*数组中和为 key 的一对数*/
void findPair(int *arr, int size, int key)
{
	if (arr == NULL)
		return;
	int *begin = arr, *end = arr + size - 1;
	while (begin < end)
	{
		if (*begin + *end == key)
		{
			cout << "<" << *begin << "," << *end << ">" << " ";
			begin++;
			end--;
		}

		else
		{
			*begin + *end > key ? --end : ++begin;
		}
	}
	cout << endl;
}


int main()
{int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	
	findPair(arr, 16, 20);
	return 0;
}

/*数组中和为 key 的连续整数序列 <版本一>*/
void show(int* begin, int* end)
{
	while (begin != end)
	{
		cout << *begin++ << " ";
	}
	cout << *begin << endl;
}

void findOrder(int* arr, int size, int key)
{
	if (arr == NULL)
		return;
	int *begin = arr, *end = arr + 1;
	int sum = *begin + *end;
	while (begin != end)
	{
		if (sum == key)
		{
			show(begin, end);
			sum = sum - *begin;
			begin++;
			if (++end != arr + size)
				sum += *end;
			else
				break;
		}
		else
		{
			if (sum > key)
			{
				sum -= *begin;
				++begin;
			}
			else
			{
				if (++end != arr + size)
					sum += *end;
				else
					break;
			}
		}
	}
}

void main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	findOrder(arr, 16, 15);
}

/*数组中和为 key 的连续整数序列 <版本二>*/
void show(int begin, int end)
{
	for (int i = begin; i <= end; ++i)
		cout << i << " ";
	cout << endl;
}
void findOrder(int key)
{
	if (key < 3)
		return;
	int begin = 0, end = 1, middle = (key + 1) / 2, num = begin + end;
	while (begin < middle)
	{
		if (num == key)
		{
			show(begin, end);
			end++;
			num += end;
		}
		else if (num < key)
		{
			end++;
			num += end;
		}
		while (num > key)
		{
			num -= begin;
			begin++;
		}
	}
}

int main()
{
	findOrder(150);
	return 0;
}.h