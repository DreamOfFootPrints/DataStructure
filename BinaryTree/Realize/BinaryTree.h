#pragma once
#include<iostream>
#include<queue>
using namespace std;


template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	T _data;

	BinaryTreeNode(const T& x)//ģ�澡����&,����Ч�ʸߣ�����һЩ���ⲻ�����õ�����������������캯�������治�ı��const
		:_data(x)
		, _left(NULL)
		, _right(NULL)
	{}
};


//size_t size = 0;


template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;//�����򱣻�����һ����Ҳ������Node�ֲ���
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(const T* a, size_t size, const T& invalid)//Ϊʲô���ܼ�����
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

	size_t Size()//�ڵ����
	{
		return _Size(_root);
	}
	size_t Depth()
	{
		return _Depth(_root);
	}
	//����һ��
	//size_t LeafSize()
	//{
	//	return _LeafSize(_root);
	//}
	//��������
	/*size_t LeafSize()
	{
	return _LeafSize(_root);
	}*/
	//��������
	/*size_t LeafSize()
	{
	return _LeafSize(_root);
	}*/
	//�����ģ�
	size_t LeafSize()
	{
		size_t size = 0;
		_LeafSize(_root, size);
		return size;
	}
	//�������
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
	BinaryTree(const BinaryTree<T>& t);
	BinaryTree<T>& operator=(const BinaryTree<T>& t);
	~BinaryTree()
	{

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
	//����һ
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
	//��������

	//������:�����ⶨ��һ��ȫ�ֵ�size,�漰�̰߳�ȫ������
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
	//	return size;//���������仰��Ҫ��Ȼ���Ϊ0
	//}
	//�����ģ�
	size_t _LeafSize(Node* root, size_t& size)
	{
		if (root == NULL)
			return 0;
		if (root->_left == NULL&&root->_right == NULL)
		{
			++size;
		}
		_LeafSize(root->_left, size);
		_LeafSize(root->_right, size);

	}
protected:
	Node* _root;
};











