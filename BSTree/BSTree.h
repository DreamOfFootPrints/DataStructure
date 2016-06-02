#include<iostream>
using namespace std;
#include<stack>


template<class K,class V>
struct BSTNode
{
	BSTNode<K, V>* _left;
	BSTNode<K, V>* _right;
	K _key;
	V _value;
public:
	BSTNode(const K& key, const V& value)
		:_left(NULL)
		, _right(NULL)
		, _key(key)
		, _value(value)
	{}
};

template<class K,class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:
	BSTree()
		:_root(NULL)
	{}
public://增删查改的非递归写法
	bool Insert(const K& key, const V& value)//返回值设计成bool防冗余
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			return true;
		}
		Node* cur = _root;
		Node* parent = NULL;//记录cur的上一个节点
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
			else
			{
				return false;
			}
		}
		if (parent->_key > key)
		{
			parent->_left = new Node(key, value);
		}
		else
		{
			parent->_right = new Node(key, value);
		}
		return true;
	}

	bool Remove(const K& key)
	{
		if (_root == NULL)
			return false;
		if (_root->_left == NULL&&_root->_right == NULL)//是叶子节点或者根节点
		{
			if (_root->_key == key)
			{
				delete _root;
				_root = NULL;
				return true;
			}
			else
			{
				return false;
			}
		}
		Node* parent = NULL;
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
			else//相等的情况
			{
				Node* del = cur;
				if (cur->_left == NULL)//节点这有左子树或者右子树
				{
					if (parent == NULL)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left == cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
			
				}
				else if (cur->_right == NULL)
				{
					if (parent == NULL)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
				}
				else
				{//找到最左的节点，替换法删除
					parent = cur;
					Node* firstLeft = cur->_right;
					while (firstLeft->_left != NULL)
					{
						parent = firstLeft;
						firstLeft = firstLeft->_left;
					}
					std::swap(cur->_key, firstLeft->_key);
					std::swap(cur->_value, cur->_value);
					del = firstLeft;
					if (parent->_left == firstLeft)
					{
						parent->_left = firstLeft->_right;//因为为右子树的最左节点，所以没有左节点
					}
					else
					{
						parent->_right = firstLeft->_right;
					}
					
				}
				delete del;
				return true;
			}
		}
		return false;
	}

	Node* Find(const K& key)//不能该key,改key后整体会乱
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
				return cur;
		}
		return NULL;
	}
public:
	Node* Find_R(const K& key)
	{
		return _Find_R(_root, key);
	}
	bool Insert_R(const K& key, const V& value)
	{
		return _Insert_R(_root, key, value);
	}
	bool Remove_R(const K& key)
	{
		return _Remove_R(_root, key);
	}

protected://增删查改的递归写法，Remove和Insert巧用引用
	Node* _Find_R(Node* root, const K& key)
	{
		if (root == NULL)
		{
			return NULL;
		}
		if (root->_key == key)
		{
			return root;
		}
		if (root->_key > key)
		{
			return _Find_R(root->_left, key);
		}
		else
		{
			return _Find_R(root->_right, key);
		}
		return NULL;
	}


	bool _Insert_R(Node*& root, const K& key, const V& value)
	{
		if (root == NULL)
		{
			root = new Node(key, value);
			return true;
		}
		if (root->_key > key)
		{
			return _Insert_R(root->_left, key, value);
		}
		else if (root->_key < key)
		{
			return _Insert_R(root->_right, key, value);
		}
		else
		{
			return false;
		}
	}
	bool  _Remove_R(Node*& root, const K& key)
	{
		if (root == NULL)
		{
			return false;
		}
		if (root->_key > key)//有的时候条件判断的顺序要变通一下，突出重点，而不是一味的按顺序
		{
			return _Remove_R(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _Remove_R(root->_right, key);
		}
		else
		{
			Node* del = root;
			if (root->_left == NULL)
			{
				root = root->_right;//root指针，而root->_right是将指针的值赋值给他，所以后面delete del是没有什么问题的
			}
			else if (root->_right == NULL)
			{
				root = root->_left;
			}
			else
			{
				Node* firstLeft = root->_right;//寻找右子树的最左的叶子节点，或者寻找左子树的最右的叶子节点
				while (firstLeft->_left != NULL)
				{
					firstLeft = firstLeft->_left;
				}
				std::swap(root->_key, firstLeft->_key);
				std::swap(root->_value, firstLeft->_value);
				return _Remove_R(root->_right, key);//只能写这种写法，是因为firstLeft的有节点可能存在，不能简单的置为NULL	
			}										//del = firstLeft;这种也是不对的因为firstLeft这个时候可能是有右节点的
			delete del;
			del = NULL;//delet和NULL搭配使用
			return true;
		}		
		return false;

	}


public:
	void Inorder_NonR()//方便测试
	{
		if (_root == NULL)
			return;
		Node* cur = _root;
		stack<Node*> s;
		while (cur||!s.empty())
		{
			while (cur)
			{
				s.push(cur);//注意stack并不影响本来的数据结构
				cur = cur->_left;
			}
			Node* top = s.top();//其实不用在判断一次!s.empty(),因为肯定不为NULL
			s.pop();
			cout << top->_key << " ";
			if (top->_right != NULL)//这个判断可以没有
			{
				cur = top->_right;
			}
		}
	}
protected:
public:
	Node* _root;
};