#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<list>
#include<functional>
#include<vector>
using namespace std;

//使用list或者vector中的函数时候，得在前面加上关键字
//实验vector
void main()
{
	vector<int> iv(5, 1);

	iv.reserve(100); //
	for (int i = 1; i <= 100; ++i)
	{
		iv.push_back(i);
		cout << "capacity = " << iv.capacity() << " ";
	}
	cout << endl;
}

/*
void main()
{
vector<int> iv;
iv.push_back(1);
iv.push_back(2);
iv.push_back(3);
iv.push_back(4);
iv.push_back(5);
iv.push_back(6);
iv.push_back(7);

cout << "size = " << iv.size() << endl;
iv.resize(3);//将size 个数变成3个
iv.reserve(8);//capacity 容量变成8个

cout << "size =" << iv.size() << endl;
cout << "capacity =" << iv.capacity() << endl;
}
/*
void main()
{
int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int n = sizeof(ar) / sizeof(ar[0]);
vector<int> iv(ar, ar + n);
cout << "size = " << iv.size() << endl; //个数
cout << "capacity = " << iv.capacity() << endl;//容量
}
/*
void main()
{
vector<int> iv;
vector<int> iv1(10);//初始化10个0
for (auto & e : iv1)
cout << e << " ";
cout << endl;
vector<int>::iterator it = iv1.begin();
//迭代器的作用好像就是可以将类变成变量进行操作
while (it != iv1.end())
{
cout << *it << "";
++it;
}
cout << endl;
}


//实验list
/*
void main()
{
//使用链表的函数时候，前面得加上list
int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int br[10] = { 12, 23, 34, 45, 56, 67, 78, 89, 90 ,100};
list<int> list1(ar, ar + 10);
list<int> list2(br, br + 10);

cout << "empty = " << list1.empty() << endl;//判满
cout << "size = " << list1.size() << endl;//判元素个数
cout << "front = " << list1.front() << endl;//找第一个元素

list1.insert(list1.begin(), 12345);//在开始前面插入12345
for (auto & e : list1)
cout << e << " ";
cout << endl;
list1.insert(list1.begin(), 10, 123);//在开始前面插入10个123
for (auto & e : list1)
cout << e << " ";
cout << endl;
list1.insert(list1.begin(), list2.begin(),list2.end());
//在开始前面 插入list的begin到end的元素
for (auto & e : list1)
cout << e << " ";
cout << endl;
list1.swap(list2);//交换list1和list2
for (auto & e : list1)
cout << e << " ";
cout << endl;
}

/*
void main()
{
int ar[10] = { 1, 2, 3, 4, 5, 6, 7 };
list<int> list1(ar, ar + 10);//7之后没有，自动补为0
list<int>::iterator it = list1.begin();
while (it != list1.end())
{
cout << *it << " ";
++it;
}
cout << endl;
list<int>::reverse_iterator rit = list1.rbegin();
//倒尾打印
while (rit != list1.rend())
{
cout << *rit << " ";
++rit;
}
cout << endl;
}
/*
void main()
{
int ar[10] = { 1, 2, 3, 4, 5, 6, 7 };
list<int> list1(ar,ar+10);
for (auto & e : list1)
cout << e << " ";
cout << endl;

list<int>::iterator it = list1.begin();//用迭代器打印list
while (it != list1.end())
{
cout << *it << ". ";
++it;
}
cout << endl;
}

/*
void main()
{
//各种初始化函数
int ar[10] = { 1, 2, 3, 4, 5, 6, 7 };
list<int> list1;
list<int> list2(10);
list<int> list3(10,5);
list<int> list4(ar,ar+6);
list<int> list5(list4);
list<int> list6(list5.begin(),list5.end());

for (auto & e : list1)//2 3 4 5 6
{
cout << e << " ";
}
cout << endl;
}