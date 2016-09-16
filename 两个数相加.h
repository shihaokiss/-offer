/*不用加减乘除做加法*/
int myAdd(int a, int b)
{
	int left, right;
	while (a)
	{
		left = a, right = b;
		a = (left&right) << 1;
		b = left^right;
	}
	return b;
}

int main()
{
	cout << myAdd(111111111,22222222) << endl;
	return 0;
}