/*携程笔试题*/
int fun()
{
	vector<int> _array;
	string str;
	int sum = 0,pow = 1;
	char ch;
	while ((ch = getchar()) != '\n')
	{
		str += ch;
	}

	string::iterator it = str.end();
	while (1)
	{
		--it;
		if (it == str.begin())
		{
			sum += (*it - '0')*pow;
			_array.push_back(sum);
			break;
		}
		if (*it != ',')
		{
			sum += (*it - '0')*pow;
			pow *= 10;
		}
		else
		{
			_array.push_back(sum);
			sum = 0;
			pow = 1;
		}
	}
	sort(_array.begin(), _array.end());
	return _array[_array.size() - 1] - _array[0];
}

int main()
{
	cout << fun() << endl;
	return 0;
}.