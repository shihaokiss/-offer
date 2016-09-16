/*不用乘除不用循环 求 1 - 100 的和*/
/*方法一: 静态成员变量*/
class A
{
public:
	A()
	{
		num++;
		sum += num;
	}
	static int getSum()
	{
		return sum;
	}
private:
	static int num;
	static int sum;
};
int A::num = 0;
int A::sum = 0;

int main()
{
	A* ptr = new A[100];
	cout << A::getSum() << endl;
	delete[] ptr;
}

/*方法二: 继承 + 递归*/
class A;
A* _array[2];
class A
{
public:
	virtual int Add(int n)
	{
		return 0;
	}
};
class B :public A
{
public:
	virtual int Add(int n)
	{
		return _array[!!(n - 1)]->Add(n - 1) + n;
	}
};

int main()
{
	A a;
	B b;
	_array[0] = &a;
	_array[1] = &b;
	cout << _array[1]->Add(100) << endl;
	return 0;
}

/*方法三: 递归*/
int Add(int n)
{
	if (n == 0)
		return 0;
	else
		return Add(n - 1) + n;
}

int main()
{
	cout << Add(100) << endl;
	return 0;
}

/*方法四: 函数指针*/
typedef int (*Fun)(int);

int _Add(int n)
{
	return 0;
}

int Add(int n)
{
	static Fun f[2] = { _Add, Add };
	return f[!!(n-1)](n-1) + n;
}

int main()
{
	cout << Add(100) << endl;
	return 0;
}

/*方法五: 模板*/
template<int n>
struct Add
{
	enum{N = Add<n-1>::N + n};
};

template<>
struct Add<1>
{
	enum{ N = 1};
};

int main()
{
	cout << Add<100>::N << endl;
	return 0;
}