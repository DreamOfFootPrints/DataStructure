#include<iostream>
using namespace std;
#include<stack>


enum Type
{
	OP_NUM,
	OP_SYMBOL,
	ADD,
	SUB,
	MUL,
	DIV
};


struct Cell
{
	Type _type;
	int _num;
};


int RPNCount(Cell a[], size_t size)
{
	stack<int> s;
	for (size_t i = 0; i < size; ++i)
	{
		if (a[i]._type == OP_NUM)
		{
			s.push(a[i]._num);
		}
		else
		{
			int right = s.top();
			s.pop();
			int left = s.top();
			s.pop();	//��һ�������п�����ɱ��������Լ�һЩ�жϣ���ֹ�������
			switch (a[i]._num)//˼����Ϊʲô����a[i]._type
			{
			case ADD:
			{
				s.push(left + right);
				break;
			}

			case SUB:
			{
				s.push(left - right);
				break;
			}	
			case MUL:
			{
				s.push(left*right);
				break;
			}	
			case DIV:
			{
				s.push(left / right);
				break;
			}
			default:
			{
				cout << "Invalid OP_SYMBOL" << endl;
				exit(-1);
				break;
			}
			}
		}
	}
	return s.top();
}

