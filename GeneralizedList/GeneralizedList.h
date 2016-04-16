#include<iostream>
#include<assert.h>
using namespace std;


enum Type
{
	HEAD,
	VALUE,
	SUB
};

struct GeneralizedNode
{
public:
	GeneralizedNode(Type type = HEAD, int value = 0)
		:_type(type)
		, _next(NULL)
	{
		if (_type == VALUE)
		{
			_value = value;
		}
		else if (_type == SUB)
		{
			_subLink = NULL;
		}
	}
public:
	Type _type;
	GeneralizedNode* _next;
	union
	{
		int _value;
		GeneralizedNode* _subLink;
	};
};



class Generalized
{
public:
	Generalized()
		:_head(NULL)
	{}

	Generalized(const char* str)
		:_head(NULL)
	{
		_head = _GreateList(str);
	}
	Generalized(const Generalized& g)
	{
		_head = _Copy(g._head);
	}
	//Generalized& operator=(const Generalized& g)//传统写法
	//{
	//	if (this != &g)
	//	{
	//		GeneralizedNode* tmp = _Copy(g._head);
	//		_Destory(_head);
	//		_head = tmp;
	//	}
	//	return *this;
	//}

	Generalized& operator=(Generalized g)//现代写法
	{
		std::swap(this->_head, g._head);
		return *this;
	}


	~Generalized()
	{
		_Destory(_head);
	}
public:

	void Print()
	{
		_Print(_head);
		cout << endl;  
	}
	size_t Size()
	{
		return _Size(_head);
	}
	size_t Depth()
	{
		return _Depth(_head);
	}
protected:
	GeneralizedNode* _GreateList(const char*& str)
	{
		assert(*str == '(');
		++str;
		GeneralizedNode* head = new GeneralizedNode(HEAD);
		GeneralizedNode* cur = head;
		while (*str)
		{
			if (_IsValue(*str))
			{
				cur->_next = new GeneralizedNode(VALUE, *str);
				cur = cur->_next;
				++str;
			}
			else if (*str == '(')
			{
				GeneralizedNode* subNode = new GeneralizedNode(SUB);
				cur->_next = subNode;
				cur = cur->_next;
				subNode->_subLink = _GreateList(str);
			}
			else if (*str == ')')
			{
				++str;
				return head;
			}
			else
			{
				++ str;
			}
			
		}
		cout << "广义表字符串错误" << endl;
		assert(false);
		return head;
	}

	bool _IsValue(char ch)
	{
		if ((ch >= '0'&&ch <= '9')
			|| (ch >= 'a'&&ch <= 'z')
			|| (ch >= 'A'&&ch <= 'Z'))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	void _Print(GeneralizedNode* head)
	{
		GeneralizedNode* cur = head;
		while (cur)
		{
			if (cur->_type == HEAD)
			{
				cout << "(";
			}
			else if (cur->_type == VALUE)
			{
				cout << (char)cur->_value;
				if (cur->_next)
				{
					cout << ",";
				}
			}
			else
			{
				_Print(cur->_subLink);
				if (cur->_next)
				{
					cout << ",";
				}
			}
			cur = cur->_next;
		}
		cout << ")";
	}
	size_t _Size(GeneralizedNode* head)
	{
		size_t size = 0;
		GeneralizedNode* cur = head;
		while (cur)
		{
			if (cur->_type == VALUE)
			{
				++size;
			}
			else if (cur->_type == SUB)
			{
				size += _Size(cur->_subLink);
			}
			cur = cur->_next;
		}
		return size;
	}

	size_t _Depth(GeneralizedNode* head)
	{
		int depth = 1;
		GeneralizedNode* cur = head;
		while (cur)
		{
			if (cur->_type == SUB)
			{
				size_t subDepth = _Depth(cur->_subLink);
				if (subDepth + 1 > depth)
				{
					depth = subDepth + 1;
				}
			}
			cur = cur->_next;
		}
		return depth;
	}
	GeneralizedNode* _Copy(GeneralizedNode* head)
	{
		GeneralizedNode* cur = head->_next;
		GeneralizedNode* newHead = new GeneralizedNode(HEAD);
		GeneralizedNode* newCur = newHead;
		while (cur)
		{
			if (cur->_type == VALUE)
			{
				newCur->_next = new GeneralizedNode(VALUE, cur->_value);
				newCur = newCur->_next;
			}
			else if (cur->_type == SUB)
			{
				newCur->_next = new GeneralizedNode(SUB);
				newCur = newCur->_next;
				newCur->_subLink = _Copy(cur->_subLink); 
			}
			cur = cur->_next;
		}
		return newHead;
	}

	void _Destory(GeneralizedNode* head)
	{
		GeneralizedNode* cur = head;
		
		while (cur)
		{
			GeneralizedNode* del = cur;
			cur = del->_next;
			if (del->_type == SUB)
			{
				_Destory(del->_subLink);
				delete del;
			}
		}
	}

protected:
	GeneralizedNode* _head;
};


