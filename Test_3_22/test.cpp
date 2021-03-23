#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>

using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = new char[strlen(s.m_data) + 1];
		strcpy(m_data, s.m_data);
	}
	~String()
	{
		delete[]m_data;
		m_data = nullptr;
	}
private:
	char* m_data;
};
void main()
{
	String s("abcd");
}

//定位new

/*
void* operator new(size_t sz,void* ptr,int pos)
{
	return &((int*)ptr)[pos];
}
class Test
{
public:
	Test(int data = 0) :m_data(data)
	{
		cout << "Create Test Obj." << m_data << endl;
	}
	~Test()
	{
		cout << "Free Test Obj." << endl;
	}
private:
	int m_data;
};
void main()
{
	Test ptr[10];
	new(ptr, 5)Test(200);

	//int ptr[10] = { 0 };
	//new(ptr, 5)int(100);
}
/*
//操作符new和delete
void* operator new(size_t sz)
{
	void* ptr = malloc(sz);
	return ptr;
}
void operator delete(void* ptr)
{
	free(ptr);
}
class Test
{
public:
	Test(int data = 0) :m_data(data)
	{
		cout << "Create Test Obj." <<m_data<<endl;
	}
	~Test()
	{
		cout << "Free Test Obj." << endl;
	}
private:
	int m_data;
};
void main()
{
	Test *pt = new Test(100);//()是用来写值的   
	delete  pt;
}

/*
//delete和new操作符
class Test
{
public:
	Test(int data = 0) :m_data(data)
	{
		cout << "Create Test Obj." << endl;
	}
	~Test()
	{
		cout << "Free Test Obj." << endl;
	}
private:
	int m_data;
};
void main()
{
	Test *pt = new Test[10];   //这里是创建10个 则必须有初始赋值
	delete [10]pt;
}

/*
class Stu
{
public:
	Stu(char* name, int age)
	{
		m_name = (char*)malloc(strlen(name) + 1);
		assert(m_name != NULL);
		strcpy(m_name, name);
		this->age = age;
	}
private:
	char* m_name;
	int age;
};
void main()
{
	Stu s("abc", 20);
}
*/