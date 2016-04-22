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
	BinaryTree(const BinaryTree<T>& t)
	{
		_root = _Copy(t._root);
	}
	//BinaryTree<T>& operator=(const BinaryTree<T>& t)//��ͳд��
	//{
	//	if (this != &t)
	//	{
	//		Node* tmp = _Copy(t._root);
	//		_Destroy(_root);
	//		_root = tmp;
	//	}
	//	return *this;
	//}

	BinaryTree<T>& operator=(BinaryTree<T> t)//�ִ�д��
	{
		std::swap(this->_root, t._root);//t����д��.����д��_>,û�����ش˲�����
		return *this;
	}

	~BinaryTree()
	{
		_Destroy(_root);
		_root = NULL;
	}

	//ǰ��ķǵݹ����
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

	//�ǵݹ��������
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

	//��������ķǵݹ�д��
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
				prev = top;//��һ���ڵ�
			}
			else//����else�Ǵ����
			{
				cur = top->_right;
			}
		}
		cout << endl;

	}

	//��õ�K��Ľڵ���
	//����һ���ǵ�һ���K�㣬�ǵڶ����k-1�㣬�ǵ�k-1��ĵ�1��
	//size_t GetKLevel(int k)
	//{
	//	return _GetKLevel(_root, k);
	//}
	//����������ϸδʵ��
	/*size_t GetKLevel(int k)
	{
		size_t Ksize = 0;
		_GetKLevel(_root, k, Ksize);;
		return Ksize;
	}*/
	//��������
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
	//����һ��
	//size_t _GetKLevel(Node* root, int k)
	//{
	//	if (root == NULL)
	//		return 0;
	//	if (k == 1)//��������
	//	{
	//		return 1;
	//	}
	//	return _GetKLevel(root->_left, k - 1) + _GetKLevel(root->_right, k - 1);
	//}
	//��������
	void _GetKLevel(Node* root, int k, size_t level, size_t& kSize)//ע������level����&,��kSize������
	{
		if (root == NULL)
			return;
		if (level == k)
		{
			++kSize;
			return;
		}
		_GetKLevel(root->_left, k, level + 1, kSize);//ע��������+1
		_GetKLevel(root->_right, k, level + 1, kSize);

	}


protected:
	Node* _root;
};











