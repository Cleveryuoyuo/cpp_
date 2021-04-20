#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<list>
#include<functional>
#include<vector>
using namespace std;

//ʹ��list����vector�еĺ���ʱ�򣬵���ǰ����Ϲؼ���
//ʵ��vector
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
iv.resize(3);//��size �������3��
iv.reserve(8);//capacity �������8��

cout << "size =" << iv.size() << endl;
cout << "capacity =" << iv.capacity() << endl;
}
/*
void main()
{
int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int n = sizeof(ar) / sizeof(ar[0]);
vector<int> iv(ar, ar + n);
cout << "size = " << iv.size() << endl; //����
cout << "capacity = " << iv.capacity() << endl;//����
}
/*
void main()
{
vector<int> iv;
vector<int> iv1(10);//��ʼ��10��0
for (auto & e : iv1)
cout << e << " ";
cout << endl;
vector<int>::iterator it = iv1.begin();
//�����������ú�����ǿ��Խ����ɱ������в���
while (it != iv1.end())
{
cout << *it << "";
++it;
}
cout << endl;
}


//ʵ��list
/*
void main()
{
//ʹ������ĺ���ʱ��ǰ��ü���list
int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int br[10] = { 12, 23, 34, 45, 56, 67, 78, 89, 90 ,100};
list<int> list1(ar, ar + 10);
list<int> list2(br, br + 10);

cout << "empty = " << list1.empty() << endl;//����
cout << "size = " << list1.size() << endl;//��Ԫ�ظ���
cout << "front = " << list1.front() << endl;//�ҵ�һ��Ԫ��

list1.insert(list1.begin(), 12345);//�ڿ�ʼǰ�����12345
for (auto & e : list1)
cout << e << " ";
cout << endl;
list1.insert(list1.begin(), 10, 123);//�ڿ�ʼǰ�����10��123
for (auto & e : list1)
cout << e << " ";
cout << endl;
list1.insert(list1.begin(), list2.begin(),list2.end());
//�ڿ�ʼǰ�� ����list��begin��end��Ԫ��
for (auto & e : list1)
cout << e << " ";
cout << endl;
list1.swap(list2);//����list1��list2
for (auto & e : list1)
cout << e << " ";
cout << endl;
}

/*
void main()
{
int ar[10] = { 1, 2, 3, 4, 5, 6, 7 };
list<int> list1(ar, ar + 10);//7֮��û�У��Զ���Ϊ0
list<int>::iterator it = list1.begin();
while (it != list1.end())
{
cout << *it << " ";
++it;
}
cout << endl;
list<int>::reverse_iterator rit = list1.rbegin();
//��β��ӡ
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

list<int>::iterator it = list1.begin();//�õ�������ӡlist
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
//���ֳ�ʼ������
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