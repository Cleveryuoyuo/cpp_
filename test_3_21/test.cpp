#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*
class Test
{
	friend class Stu; // ��Ԫ��
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
//ͳ�Ƹ���
class Test
{
public:
	Test()
	{
		m_count++;
	}
	~Test()//��ΪT1�г�Ա������ȡ��
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
//��̬����
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
	static int m_value;//������ĳһ���࣬���ж�����
};

int Test::m_value = 0;

void main()
{
	Test t1;
	Test t2;
}
*/