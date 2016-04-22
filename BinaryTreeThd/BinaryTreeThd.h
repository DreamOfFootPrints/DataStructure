#include<iostream>
using namespace std;



enum PointerTag { THREAD, LINK };//线索化，节点

template <class T>
struct BinaryTreeNodeThd
{
	T _data;                         // 数据
	BinaryTreeNodeThd<T >* _left;   // 左孩子
	BinaryTreeNodeThd<T >* _right;  // 右孩子
	PointerTag   _leftTag;          // 左孩子线索标志
	PointerTag   _rightTag;         // 右孩子线索标志
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
		Node* prev = NULL;//不是上一个出现的节点，而是上一个线索化的节点
		_InOrderThreading(_root, prev);
	}

protected:
	void _InOrderThreading(Node* cur,Node* prev)//现在改变不了未来的事情，但是未来可以坐个时光机去改变过去的事情
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