bool IsTwoPower(int a)
{
	return !(a&(a - 1));
}

int Average(int a, int b)
{
	return (a&b) + ((a^b)>>1);
}

int Add(int a, int b)
{
	if (b == 0)
		return a;
	int sum, tmp;
	sum = a^b;
	tmp = (a&b) << 1;
	return Add(sum, tmp);
}

void Swap(int a, int b)
{
	cout << "Before Swap a = " << a << "  b = " << b << endl;
	a = a^b;
	b = a^b;
	a = a^b;
	cout << "After Swap a = " << a << "  b = " << b << endl;
}

#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
int MiddleOfThree(int a, int b, int c)
{
	int t1, t2, t3;
	t1 = Max(a, b);
	t2 = Max(a, c);
	t3 = Max(b, c);
	cout << "中间的数为 :  " << endl;
	return Min(t1, Min(t2, t3));
}

int MaxOfTwo(int a, int b)
{
	cout << "较大数为： ";
	return (a + b + abs(a - b)) >> 1;
}
int MinOfTwo(int a, int b)
{
	cout << "较小数为：";
	return (a + b - abs(a - b)) >> 1;
}

	

