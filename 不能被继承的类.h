/*不能被继承下去的类 B*/
template<class T>
class A
{
	friend T;
private:
	A()
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
};

class B :virtual public A<B>
{
public:
	B()
	{
		cout << "B" << endl;
	}
	~B()
	{
		cout << "~B" << endl;
	}
};


void main()
{
	B b;
}