#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


namespace ghc
{
	template<class _Ty>
	class list
	{
	public:
		typedef size_t size_type;
	public:
		struct _Node;
		typedef _Node* _Nodeptr;
		struct _Node
		{
			_Nodeptr _Next;
			_Nodeptr _Prev;
			_Ty      _Value;
		};
		//针对于节点 写了三个函数操作
		struct _Acc//定义了三个函数 伺候_Next的三个域
		{
			//静态函数可以不通过对象调动，通过类名就可以调动
			typedef _Node*& _Nodepref;//结点指针的引用
			typedef _Ty& _Vref;
			static _Nodepref _Next(_Nodeptr _P)//相当于返回_P所指的后继
			{return _P->_Next;}
			static _Nodepref _Prev(_Nodeptr _P)
			{return _P->_Prev;}
			static _Vref _Value(_Nodeptr _P)
			{return _P->_Value;}
		};
	public:
		explicit list() :_Head(_Buynode()), _Size(0)//构造函数 显示的
		{}
		//相当于下面的代码
		//explicit list()
		//{
		//	_Head = (_Nodeptr)malloc(sizeof(_Node));
		//	_Head->Next = _Head;
		//	_Head->Prev = _Head;
		//	_Size = 0;
		//}
	public:
		void push_back(const _Ty& x)
		{
			_Nodeptr _S = _Buynode(_Head,_Acc::_Prev(_Head));//相当于写了1  2 
										//_Head->Prev;
			_Acc::_Value(_S) = x;// 3
			_Acc::_Next(_Acc::_Prev(_S)) = _S; // 4
			_Acc::_Prev(_Head) = _S; //5
			++_Size;
			//_Nodeptr _S = _Buynode();
			//_S->_Value = x; 3
			//_S->_Next = _Head;  1
			//_S->_Prev = _Head->_Prev;  2
			//_S->_Prev->_Next = _S; 4
			//_Head->_Prev = _S; 5
			//_Size++;
		}
		void push_front(const _Ty& x)
		{
			_Nodeptr _S = _Buynode(_Acc::_Next(_Head), _Head);
			_Acc::_Value(_S) = x;
			_Acc::_Next(_Acc::_Prev(_S)) = _S;
			_Acc::_Prev(_Acc::_Next(_S)) = _S;
			++_Size;
			//_S->_Prev->_Next = _S;
			//_S->_Next->_Prev = _S;
		}
	protected:
		//购买结点指针
		_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0)
		{
			//创建一个指针指向开辟的_Node
			_Node* _S = (_Node*)malloc(sizeof(_Node));
			_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
			_Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
			//_S的后继不就是_S的_Next()函数么
			//_S->Next = _Narg != 0 ? _Narg : _S;
			//_S->Prev = _Parg != 0 ? _Parg : _S;
			return _S;
		}
	private:
		_Nodeptr _Head;
		size_type _Size;
	};
}

using namespace ghc;
void main()
{
	list<int> mylist;//这个类的类型是整形类
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);

}