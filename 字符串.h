/*字符串的反转*/
void _reverse(char *begin, char *end)
{
	if (begin == NULL || end == NULL)
		return;
	else
	{
		while (begin < end)
		{
			std::swap(*begin, *end);
			begin++;
			end--;
		}
	}
}

char* reverse(char* arr)
{
	if (arr == NULL)
		return NULL;
	else
	{
		char *begin = arr, *end = arr;
		while (*begin != '\0')
		{
			if (*begin == ' ')
			{
				begin++;
				end++;
			}
			else if (*end == ' ' || *end == ',' || *end == '\0')
			{
				if (*end == ',')
					end++;
				_reverse(begin, end - 1);
				begin = end;
			}
			else
			{
				end++;
			}
		}
		_reverse(arr, begin - 1);
		return arr;
	}
}

void main()
{
	char arr[] = "Our eyes do not show a lack of beauty,but a lack of observation.";
	reverse(arr);
	cout << arr << endl;
}

/*字符串的旋转*/
char* strReverse(char* arr, int n)
{
	if (arr == NULL)
		return NULL;
	int size = strlen(arr);
	if (n > size)
		return NULL;
	char* p = arr + size - 1;
	_reverse(arr, arr + n - 1);
	_reverse(arr + n, p);
	_reverse(arr, p);
	return arr;
}

void main()
{
	char arr[] = "hello world";
	for (int i = 0; i < 10; ++i)
		cout << strReverse(arr, 1) << endl;
	return;
}