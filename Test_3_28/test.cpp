#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//类模板
template<class Type>
class SeqList
{
public:
	SeqList(int zs = 8)
	{
		capacity = sz > 8 ? sz : 8;
		base = new Type[8];
		assert(base != NULL);
		size = 0;
	}
	~SeqList()
	{
		delete[]base;
		base = nullptr;
		capacity = size = 0;
	}
public:
	void push_back(const Type &x);
private:
	Type *base;
	size_t capacity;
	size_t size;
};
template<class Type>
void SeqList<Type>::push_back(const Type& x)//得先在自己的类里面声明函数
{
	assert(!full());//判断是不是满了，满了在扩容
	base[size++] = x;
}
void main()
{
	SeqList<int>mylist(10);//传类型参数int
	SeqList<char>youlist(5);//类型char
}

/*
//模板
//如果不同类型的交换，需要引用两个就好

template<class Type1,class Type2>
void Swap(Type1 &a, Type2 &b)
{
	Type1 tmp = a;
	a = b;  //int = double
	b = tmp;
}

void main()
{
	int a = 1;
	double b = 8.3;
	Swap(a,b);
}

/*
template<class Type>
void Swap(Type& a, Type& b)
{
	Type tmp = a;
	a = b;
	b = tmp;
}

void main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);
	double c = 12.34;
	double d = 23.45;
	Swap(c, d);
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
}
*/