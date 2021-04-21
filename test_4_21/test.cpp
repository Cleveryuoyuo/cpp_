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
	cout<< endl;
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


/////////////////////////////////////////////////////////////////////////
/*
//修建一个list表
//总体上，三个类，1.list 2.迭代器 3.Node用来涵括list成员的创建
namespace ghc
{
	template<class _Ty>
	class list;

	template<class _Ty>
	class List_iterator;

	template<class _Ty>
	class Node
	{
		//因为在后面会用到Node，则需要引入友元类
		friend class list<_Ty>;
		friend class List_iterator<_Ty>;
	public:
		Node() :_val(_Ty()), _next(nullptr), _prev(nullptr)
		{}
		Node(const _Ty& val, Node* next = nullptr, Node*prev = nullptr)
			:_val(val), _next(next), _prev(prev)
		{}
		~Node()
		{}
	private:
		Node* _next;
		Node* _prev;
		_Ty _val;
	};

	template<class _Ty>
	class List_iterator
	{
		typedef List_iterator<_Ty> self;
	public:
		List_iterator(Node<_Ty>* _P) :_Ptr(_P)
		{}
	public:
		_Ty& operator*()
		{
			return _Ptr->_val;
		}
		self& operator++()//后置++
		{
			_Ptr = _Ptr->_next;
			return *this;
		}
		self operator++(int)//前置++
		{
			self tmp(*this);
			++*this;
			return tmp;
		}
		self& operator--()
		{
			_Ptr = _Ptr->_prev;
			return *this;
		}
		bool operator!=(const self& it)
		{
			return (_Ptr != it._Ptr);
		}
		Node<_Ty>* _Mynode()
		{
			return _Ptr;
		}
	private:
		Node<_Ty>* _Ptr;
	};



	template<class _Ty>
	class list
	{
	public:
		typedef List_iterator<_Ty> iterator;
		typedef iterator _IT;
	public:
		//三种构造函数 应对不同的参数
		list():_Size(0) 
		{
			CreateHead();
		}
		list(int n, const _Ty&value = T())
		{
			CreateHead();
			while (--n)
			{
				insert(begin(), value);
			}
		}
		list(_IT _first, _IT _last)
		{
			CreateHead();
			while (_first != _last)
			{
				push_back(*_first);
				++_first;
			}
		}

		// 拷贝
		list<_Ty>& operator=(list<_Ty>& lt)
		{
			if (this != &lt)
			{
				//重新构造一个tmp
				list<_Ty> tmp(lt.begin(), lt.end()); 
				swap(_Head, tmp._Head);
			}
			return *this;
		}
		~list()
		{
			clear();
			delete _Head;
			_Head = nullptr;
		}
		
	public:
		iterator begin()
		{
			return iterator(_Head->_next);
		}
		iterator end()
		{
			return iterator(_Head);
		}
	public:// 各个函数的实现
		size_t size()const 
		{
			return _Size;
		}
		bool empty()const
		{
			return size() == 0;
		}
		_Ty& front()
		{
			return *begin();
		}

		void clear()
		{
			erase(begin(), end());
		}
		void swap(list& lt1, list& lt2) //有问题，不会了
		{
			lt1= lt2;
		}
	public:
		iterator insert(iterator _P, const _Ty &x)
		{
			Node<_Ty>* _S = new Node<_Ty>(x);
			Node<_Ty>* cur = _P._Mynode();
			_S->_next = cur;
			_S->_prev = cur->_prev;
			_S->_next->_prev = _S;
			_S->_prev->_next = _S;
			_Size++;
			return iterator(_S);
		}
		iterator erase(_IT _P)
		{
			Node<_Ty>* cur = _P._Mynode();
			Node<_Ty>* next_node = cur->_next;
			cur->_next->_prev = cur->_prev;
			cur->_prev->_next = cur->_next;
			delete cur;
			_Size--;
			return iterator(next_node);
		}
		iterator erase(_IT _first, _IT _last)
		{
			while (_first != _last)
			{
				_first = erase(_first);
			}
			return _IT(_last);
		}
	protected:
		void CreateHead()
		{
			_Head = new Node<_Ty>;
			_Head->_next = _Head;
			_Head->_prev = _Head;
		}
	private:
		Node<_Ty>* _Head;
		size_t _Size;
	};
}

void main()
{
	ghc::list<int> mylist(10, 2);
	ghc::list<int> youlist;   //list<int> youlist = mylist

	youlist = mylist;

	ghc::list<int>::iterator it = youlist.begin();
	while (it != youlist.end())
	{
		cout << *it << " ";
		++it; //it++
	}
	cout << endl;
}
*/
