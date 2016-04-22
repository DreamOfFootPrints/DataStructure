#include<iostream>
using namespace std;



enum PointerTag { THREAD, LINK };//���������ڵ�

template <class T>
struct BinaryTreeNodeThd
{
	T _data;                         // ����
	BinaryTreeNodeThd<T >* _left;   // ����
	BinaryTreeNodeThd<T >* _right;  // �Һ���
	PointerTag   _leftTag;          // ����������־
	PointerTag   _rightTag;         // �Һ���������־
public:
	BinaryTreeNodeThd(const T& x)
		:_data(x)
		,_left(NULL)
		, _right(NULL)
		, _leftTag(LINK)
		, _rightTag(LINK)
	{}

};


template<class T>
class BinaryTreeThd
{
	typedef BinaryTreeNodeThd<T> Node;
public:
	BinaryTreeThd(const T* a, size_t size, const T& invalid)
	{
		size_t index = 0;
		_root = _GreateTree(a, size, index, invalid);
	}
protected:
	Node* _GreateTree(const T* a, size_t size, size_t& index, const T& invalid)
	{
		Node* root = NULL;
		if (index < size&&a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _GreateTree(a, size, ++index, invalid);
			root->_right = _GreateTree(a, size, ++index, invalid);
		}
		return root;
	}

	void InOrderThreading()
	{
		Node* prev = NULL;//������һ�����ֵĽڵ㣬������һ���������Ľڵ�
		_InOrderThreading(_root, prev);
	}

protected:
	void _InOrderThreading(Node* cur,Node* prev)//���ڸı䲻��δ�������飬����δ����������ʱ���ȥ�ı��ȥ������
	{
		if (cur == NULL)
		{
			return;
		}
		_InOrderThreading(cur->_left, prev);
		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}
		if (prev&&prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		prev = cur;
		_InOrderThreading(cur->_right, prev);
	}
private:
	Node* _root;

};