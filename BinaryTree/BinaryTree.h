#pragma once
#include<iostream>
#include<queue>
#include<stack>
using namespace std;


template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	T _data;

	BinaryTreeNode(const T& x)//模版尽量加&,这样效率高，除了一些故意不加引用的情况，不调拷贝构造函数，里面不改变加const
		:_data(x)
		, _left(NULL)
		, _right(NULL)
	{}
};


//size_t size = 0;


template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;//受类域保护，万一外面也定义了Node分不清
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(const T* a, size_t size, const T& invalid)//为什么不能加引用
	{
		size_t index = 0;
		_root = _GreateTree(a, size, index, invalid);
	}

	void PrevOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	size_t Size()//节点个数
	{
		return _Size(_root);
	}
	size_t Depth()
	{
		return _Depth(_root);
	}
	//方法一：
	//size_t LeafSize()
	//{
	//	return _LeafSize(_root);
	//}
	//方法二：
	/*size_t LeafSize()
	{
	return _LeafSize(_root);
	}*/
	//方法三：
	/*size_t LeafSize()
	{
	return _LeafSize(_root);
	}*/
	//方法四：
	size_t LeafSize()
	{
		size_t size = 0;
		_LeafSize(_root, size);
		return size;
	}
	//层序遍历
	void LeveOrder()
	{
		queue<Node*> q;
		if (_root != NULL)
		{
			q.push(_root);
			while (!q.empty())
			{
				Node* front = q.front();
				cout << front->_data << " ";
				q.pop();
				if (front->_left != NULL)
					q.push(front->_left);
				if (front->_right != NULL)
					q.push(front->_right);
			}
		}
		cout << endl;
	}
	//
	BinaryTree(const BinaryTree<T>& t)
	{
		_root = _Copy(t._root);
	}
	//BinaryTree<T>& operator=(const BinaryTree<T>& t)//传统写法
	//{
	//	if (this != &t)
	//	{
	//		Node* tmp = _Copy(t._root);
	//		_Destroy(_root);
	//		_root = tmp;
	//	}
	//	return *this;
	//}

	BinaryTree<T>& operator=(BinaryTree<T> t)//现代写法
	{
		std::swap(this->_root, t._root);//t必须写成.不能写成_>,没有重载此操作符
		return *this;
	}

	~BinaryTree()
	{
		_Destroy(_root);
		_root = NULL;
	}

	//前序的非递归遍历
	void PrevOrder_NonR()
	{
		stack<Node*> s;
		if (_root != NULL)
		{
			s.push(_root);
		}
		while (!s.empty())
		{
			Node* top = s.top();
			cout << top->_data << " ";
			s.pop();
			if (top->_right!=NULL)
			{
				s.push(top->_right);
			}
			if (top->_left)
			{
				s.push(top->_left);
			}
		}
		cout <<   endl;
	}

	//非递归中序遍历
	void InOrder_NonR()
	{
		Node* cur = _root;
		stack<Node*> s;
		while (cur || !s.empty())
		{
			while (cur!=NULL)
			{
				s.push(cur);
				cur = cur->_left;
			}

			if (!s.empty())
			{
				Node* top = s.top();
				s.pop();
				cout << top->_data << " ";
				cur = top->_right;
			}
		}
		cout << endl;
	}

	//后序遍历的非递归写法
	void PosOrder_NonR()
	{
		Node* cur = _root;
		Node* prev = NULL;
		stack<Node*> s;
		while (cur != NULL || !s.empty())
		{
			while (cur != NULL)
			{
				s.push(cur);
				cur = cur->_left;
			}

			Node* top = s.top();
			if (top->_right == NULL || top->_right == prev)
			{
				cout << top->_data << " ";
				s.pop();
				prev = top;//上一个节点
			}
			else//不加else是错误的
			{
				cur = top->_right;
			}
		}
		cout << endl;

	}

	//获得第K层的节点数
	//方法一：是第一层的K层，是第二层的k-1层，是第k-1层的第1层
	//size_t GetKLevel(int k)
	//{
	//	return _GetKLevel(_root, k);
	//}
	//方法二：详细未实现
	/*size_t GetKLevel(int k)
	{
		size_t Ksize = 0;
		_GetKLevel(_root, k, Ksize);;
		return Ksize;
	}*/
	//方法三：
	size_t GetKLevel(int k)
	{
		size_t kSize = 0;
		size_t level = 1;
		_GetKLevel(_root, k, level, kSize);
		return kSize;
	}


protected:
	Node*  _GreateTree(const T* a, size_t size, size_t& index, const T& invalid)
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

	void _PrevOrder(Node* root)
	{
		if (root == NULL)
			return;
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}

	void _Inorder(Node* root)
	{
		if (root == NULL)
			return;
		_Inorder(root->_left);
		cout << root->_data << " ";
		_Inorder(root->_right);
	}

	size_t _Size(Node* root)
	{
		if (root == NULL)
			return 0;
		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	size_t _Depth(Node* root)
	{
		if (root == NULL)
			return 0;
		int leftDepth = _Depth(root->_left);
		int rightDepth = _Depth(root->_right);
		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	}
	//方法一
	/*size_t _LeafSize(Node* root)
	{
	if (root == NULL)
	return 0;
	if (root->_left == NULL&&root->_right == NULL)
	{
	return 1;
	}
	return _LeafSize(root->_left) + _LeafSize(root->_right);
	}
	*/
	//方法二：

	//方法三:在类外定义一个全局的size,涉及线程安全的问题
	//size_t _LeafSize(Node* root)
	//{
	//	if (root == NULL)
	//		return 0;
	//	if (root->_left == NULL&&root->_right == NULL)
	//	{
	//		++size;
	//		return size;
	//	}
	//	_LeafSize(root->_left);
	//	_LeafSize(root->_right);
	//	return size;//必须加上这句话，要不然结果为0
	//}
	//方法四：
	void _LeafSize(Node* root, size_t& size)
	{
		if (root == NULL)
			return ;
		if (root->_left == NULL&&root->_right == NULL)
		{
			++size;
		}
		_LeafSize(root->_left, size);
		_LeafSize(root->_right, size);

	}

	Node* _Copy(Node* root)
	{
		if (root == NULL)
		{
			return  NULL;
		}
		Node* newRoot = new Node(root->_data);
		newRoot->_left = _Copy(root->_left);
		newRoot->_right = _Copy(root->_right);
		return newRoot;
	}

	void _Destroy(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}
	//方法一：
	//size_t _GetKLevel(Node* root, int k)
	//{
	//	if (root == NULL)
	//		return 0;
	//	if (k == 1)//非子问题
	//	{
	//		return 1;
	//	}
	//	return _GetKLevel(root->_left, k - 1) + _GetKLevel(root->_right, k - 1);
	//}
	//方法三：
	void _GetKLevel(Node* root, int k, size_t level, size_t& kSize)//注意这里level不加&,而kSize加引用
	{
		if (root == NULL)
			return;
		if (level == k)
		{
			++kSize;
			return;
		}
		_GetKLevel(root->_left, k, level + 1, kSize);//注意这里是+1
		_GetKLevel(root->_right, k, level + 1, kSize);

	}


protected:
	Node* _root;
};











