#pragma once
#include<iostream>
using namespace std;
#include<stack>

enum Colour
{
	RED,
	BLACK
};

template<class K,class V>
struct RBTreeNode
{
public:
	
	Colour _col;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	K _key;
	V  _value;
public:
	RBTreeNode(const K& key = K(), const V& value = V())
		:_col(RED)//ðȻ����ڽڵ㣬�������ڽڵ�Ĳ�ƽ��
		,_left()
		, _right(NULL)
		, _parent(NULL)
		, _key(key)
		, _value(value)
	{}
};


template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(NULL)
	{}

	bool Insert(const K& key, const V& value)//BSTree��AVLTree��ʵ������ʹ�õݹ���д��RBTreeʹ�õݹ���д�൱�鷳�����Ƽ�
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			_root->_col = BLACK;
			return true;
		}
		Node* parent = _root;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key>key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else//������
			{
				return false;
			}
		}
		if (parent->_key < key)//�Ȳ����ڵ��ڣ�Ҫ��Ȼ�Ƚ��鷳,���ǵ������ܶ�
		{
			cur = new Node(key, value);
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			cur = new Node(key, value);
			parent->_left = cur;
			cur->_parent = parent;
		}
		//����
		while (cur != _root&&parent->_col == RED)//��һ��������֤parent���ڣ�
		{										//�ڶ�����������֤grantfather����
			Node* grandFather = parent->_parent;
			if (parent == grandFather->_left)
			{
				//1�����1
				Node* uncle = grandFather->_right;
				if (uncle&&uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandFather->_col = RED;
					cur = grandFather;
					parent = cur->_parent;
				}
				else //���2�����3
				{
					//���2
					/*	if (parent->_left == cur)
						{
						parent->_col = BLACK;
						grandFather->_col = RED;
						RotateR(parent);
						}
						else
						{
						RotateL(parent);
						}*/
					if (parent->_right == cur)
					{
						RotateL(parent);
					}
					parent->_col = BLACK;
					grandFather->_col = RED;
					RotateR(grandFather);
					break;
				}
			
			}
			else//�������游���� parent=grandfather->_right
			{
				Node* uncle = grandFather->_left;
				if (uncle&&uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandFather->_col = RED;
					cur = grandFather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
					}
					parent->_col = BLACK;
					grandFather->_col = RED;
					RotateL(grandFather);
					break;
				}
			}
			
		}
		_root->_col = BLACK;
		return true;
	}
	
	
	bool Check()
	{
		int blackNum = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++blackNum;
			cur = cur->_left;
		}
		int curBlackNum = 0;
		return _Check(_root, blackNum, curBlackNum);
	}


	void InOrder_NonR()
	{
		if (_root == NULL)
			return;
		Node* cur = _root;
		stack<Node*> s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top();
			cout << top->_key << " ";
			s.pop();
			if (top->_right != NULL)
			{
				cur = top->_right;
			}
		}
		cout << endl;
	}

protected:
	bool _Check(Node* root, int blackNum, int curBlackNum)
	{
		if (root == NULL)
			return true;
		if (root->_col == BLACK)
		{
			++curBlackNum;
		}
		else
		{
			if (root-> _parent&&root->_parent->_col == RED)
			{
				cout << "��ǰ�ڵ�����ĸ��ڵ㶼�Ǻ�ɫ" << root->_key << endl;
				return false;
			}
		}
		if (root->_left == NULL&&root->_right == NULL)
		{
			if (curBlackNum == blackNum)
			{
				return true;
			}
			else
			{
				cout << "��ɫ�ڵ�������ǲ���ȵ�" << root->_key << endl;
				return false;
			}
		}
		return _Check(root->_left, blackNum, curBlackNum) && _Check(root->_right, blackNum, curBlackNum);
	}

	//��ת�Ĵ���ʽ�����֣���1��������parent���������isRotate,(2)ֱ����һ��С���жϣ�Ȼ��ֱ�Ӵ���->left
	void RotateR(Node*& parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		subL->_right = parent;
		subL->_parent = parent->_parent;
		parent->_parent = subL;
		
		parent = subL;
		if (parent->_parent == NULL)
		{
			_root = parent;
		}
		else
		{
			Node* ppNode = parent->_parent;
			if (ppNode->_key > parent->_key)
			{
				ppNode->_left = parent;
			}
			else
			{
				ppNode->_right = parent;
			}
		}
	}


	void RotateL(Node*& parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		subR->_parent = parent->_parent;
		parent->_parent = subR;
		parent = subR;
		if (parent->_parent == NULL)
		{
			_root = parent;
		}
		else
		{
			Node* ppNode = parent->_parent;
			if (ppNode->_key < parent->_key)
			{
				ppNode->_right = parent;
			}
			else
			{
				ppNode->_left = parent;
			}
		}
	}
private:
public:
	Node* _root;
};

