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
		//����ڽڵ� д��������������
		struct _Acc//�������������� �ź�_Next��������
		{
			//��̬�������Բ�ͨ�����������ͨ�������Ϳ��Ե���
			typedef _Node*& _Nodepref;//���ָ�������
			typedef _Ty& _Vref;
			static _Nodepref _Next(_Nodeptr _P)//�൱�ڷ���_P��ָ�ĺ��
			{return _P->_Next;}
			static _Nodepref _Prev(_Nodeptr _P)
			{return _P->_Prev;}
			static _Vref _Value(_Nodeptr _P)
			{return _P->_Value;}
		};
	public:
		explicit list() :_Head(_Buynode()), _Size(0)//���캯�� ��ʾ��
		{}
		//�൱������Ĵ���
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
			_Nodeptr _S = _Buynode(_Head,_Acc::_Prev(_Head));//�൱��д��1  2 
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
		//������ָ��
		_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0)
		{
			//����һ��ָ��ָ�򿪱ٵ�_Node
			_Node* _S = (_Node*)malloc(sizeof(_Node));
			_Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;
			_Acc::_Prev(_S) = _Parg != 0 ? _Parg : _S;
			//_S�ĺ�̲�����_S��_Next()����ô
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
	list<int> mylist;//������������������
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);

}