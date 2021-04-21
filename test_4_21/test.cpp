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


/////////////////////////////////////////////////////////////////////////
/*
//�޽�һ��list��
//�����ϣ������࣬1.list 2.������ 3.Node��������list��Ա�Ĵ���
namespace ghc
{
	template<class _Ty>
	class list;

	template<class _Ty>
	class List_iterator;

	template<class _Ty>
	class Node
	{
		//��Ϊ�ں�����õ�Node������Ҫ������Ԫ��
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
		self& operator++()//����++
		{
			_Ptr = _Ptr->_next;
			return *this;
		}
		self operator++(int)//ǰ��++
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
		//���ֹ��캯�� Ӧ�Բ�ͬ�Ĳ���
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

		// ����
		list<_Ty>& operator=(list<_Ty>& lt)
		{
			if (this != &lt)
			{
				//���¹���һ��tmp
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
	public:// ����������ʵ��
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
		void swap(list& lt1, list& lt2) //�����⣬������
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
