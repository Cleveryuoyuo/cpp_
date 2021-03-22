#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*
class Test
{
	friend class Stu; // 友元类
public:
	Test()
	{
	}
public:
	void show()const
	{
		cout << "This is Test::show()" << endl;
	}
private:
	int m_a = 0;
	int m_b = 0;
};
class Stu
{
public:
	void fun(const Test &t)
	{
		t.show();
	}
public:
	int m_x = 0;
	int m_y = 0;
};

void main()
{
	Test t;
	Stu s;
	s.fun(t);
}

/*
//统计个数
class Test
{
public:
	Test()
	{
		m_count++;
	}
	~Test()//因为T1中成员析构得取消
	{
		m_count--;
	}
public:
	static int GetCount()
	{
		return m_count;
	}
private:
	int m_data;
	static int m_count;
};

int Test::m_count = 0;
void main()
{
	Test t1;
	{
		Test t4;
		Test t5;
	}
	Test t2;
	Test t3;
	cout << "count = " << Test:: GetCount() << endl;
}

/*
//静态对象
class Test
{
public:
	Test() :m_data(0)
	{}
public:
	void fun()
	{
		m_data = 1;
		m_value = 10;
		print();
		show();
	}
	static void show()
	{
		//m_data = 10;
		m_value = 100;
		//fun()
	}

	//const Test * const this
	void print()const
	{
		cout << "This print()" << endl;
	}
private:
	int m_data;
	static int m_value;//不属于某一个类，所有对象共享
};

int Test::m_value = 0;

void main()
{
	Test t1;
	Test t2;
}
*/