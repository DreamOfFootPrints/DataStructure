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
public://��ɾ��ĵķǵݹ�д��
	bool Insert(const K& key, const V& value)//����ֵ��Ƴ�bool������
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			return true;
		}
		Node* cur = _root;
		Node* parent = NULL;//��¼cur����һ���ڵ�
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
		if (_root->_left == NULL&&_root->_right == NULL)//��Ҷ�ӽڵ���߸��ڵ�
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
			else//��ȵ����
			{
				Node* del = cur;
				if (cur->_left == NULL)//�ڵ���������������������
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
				{//�ҵ�����Ľڵ㣬�滻��ɾ��
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
						parent->_left = firstLeft->_right;//��ΪΪ������������ڵ㣬����û����ڵ�
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

	Node* Find(const K& key)//���ܸ�key,��key���������
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

protected://��ɾ��ĵĵݹ�д����Remove��Insert��������
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
		if (root->_key > key)//�е�ʱ�������жϵ�˳��Ҫ��ͨһ�£�ͻ���ص㣬������һζ�İ�˳��
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
				root = root->_right;//rootָ�룬��root->_right�ǽ�ָ���ֵ��ֵ���������Ժ���delete del��û��ʲô�����
			}
			else if (root->_right == NULL)
			{
				root = root->_left;
			}
			else
			{
				Node* firstLeft = root->_right;//Ѱ���������������Ҷ�ӽڵ㣬����Ѱ�������������ҵ�Ҷ�ӽڵ�
				while (firstLeft->_left != NULL)
				{
					firstLeft = firstLeft->_left;
				}
				std::swap(root->_key, firstLeft->_key);
				std::swap(root->_value, firstLeft->_value);
				return _Remove_R(root->_right, key);//ֻ��д����д��������ΪfirstLeft���нڵ���ܴ��ڣ����ܼ򵥵���ΪNULL	
			}										//del = firstLeft;����Ҳ�ǲ��Ե���ΪfirstLeft���ʱ����������ҽڵ��
			delete del;
			del = NULL;//delet��NULL����ʹ��
			return true;
		}		
		return false;

	}


public:
	void Inorder_NonR()//�������
	{
		if (_root == NULL)
			return;
		Node* cur = _root;
		stack<Node*> s;
		while (cur||!s.empty())
		{
			while (cur)
			{
				s.push(cur);//ע��stack����Ӱ�챾�������ݽṹ
				cur = cur->_left;
			}
			Node* top = s.top();//��ʵ�������ж�һ��!s.empty(),��Ϊ�϶���ΪNULL
			s.pop();
			cout << top->_key << " ";
			if (top->_right != NULL)//����жϿ���û��
			{
				cur = top->_right;
			}
		}
	}
protected:
public:
	Node* _root;
};