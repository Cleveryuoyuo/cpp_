#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//��ģ��
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
void SeqList<Type>::push_back(const Type& x)//�������Լ�����������������
{
	assert(!full());//�ж��ǲ������ˣ�����������
	base[size++] = x;
}
void main()
{
	SeqList<int>mylist(10);//�����Ͳ���int
	SeqList<char>youlist(5);//����char
}

/*
//ģ��
//�����ͬ���͵Ľ�������Ҫ���������ͺ�

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