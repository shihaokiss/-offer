/*ջ֡��Ӧ��һ*/


/*ʹ��ջ֡������ʹ���������쳣*/ 
void fun()
{
	while (1)
	{
		Sleep(1000);
		cout << "hello world" << endl;
	}
}
int add(int a, int b)
{
	int c = 0;
	c = a + b;
	int* p = (int*)(&c) + 4;    //vs2013 ���� 4 
	*p = (int)fun;
	return c;
}

int main()
{
	int a = 10;
	int b = 20;
	int ret = add(a, b);
	return 0;
}

/*����ջ֡�����Ըı� main �еı���*/

int fun()
{
	int tmp = 0;
	int*p = &tmp + 3;        //vs 2013 �����Ǽ� 3 ����� 
	int*p1 = (int*)(*p);
	*(p1 - 2) = 100;
	return 0;
}
int main()
{
	int a = 10;
	fun();
	cout << a << endl;
	return 0;
}