#pragma once
#include<iostream>
#include<assert.h>
using namespace std;



template<class T>
class Stack
{
public:
	Stack();
	~Stack();

public:
	void Push(const T& s);
	void Pop();
	size_t Size();
	bool Empty();
	T& Top();//Ҫ�޸ģ����Դ����ã����������ķǻ������ͣ�����Ӧ��������ʱ������Ч�ʵͣ�����string��������ָ��
protected:
	void _CheckCapacity();
protected:
	T* _a;//ʵ�ֶ�̬��ջ
	size_t _top;
	size_t _capacity;

};


template<class T>//��סд��
Stack<T>::Stack()
	:_a(NULL)
	, _top(0)
	, _capacity(0)
{}


template<class T>
Stack<T>::~Stack()//ע��~��λ��
{
	if (_a != NULL)
	{
		delete[] _a;
	}
}


template<class T>
void Stack<T>::_CheckCapacity()
{
	if (_a == NULL)
	{
		_capacity = 3;
		_a = new T[_capacity];
		return;
	}
	if (_top == _capacity)
	{
		_capacity = 2 * _capacity;
		T* tmp = new T[_capacity];//����malloc��free����Ϊnew��delete������캯������������
		for (size_t i = 0; i < _top; i++)//��memcpy����ǰ����������
		{
			tmp[i] = _a[i];
		}
		delete[] _a;
		_a = tmp;
	}
}


template<class T>
void Stack<T>::Push(const T& x)
{
	_CheckCapacity();
	_a[_top++] = x;
}


template<class T>
void Stack<T>::Pop()
{
	assert(_top > 0);//����ʽ���
	assert(_a != NULL);
	--_top;
}


template<class T>
size_t Stack<T>::Size()
{
	return _top;
}

template<class T>
bool Stack<T>::Empty()
{
	return _top == 0;
}


template<class T>
T& Stack<T>::Top()
{
	return _a[_top - 1];//����_a[--top]
}