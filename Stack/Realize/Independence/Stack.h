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
	T& Top();//要修改，所以传引用，而且其他的非基本类型，不加应用生成临时变量，效率低，例如string，和智能指针
protected:
	void _CheckCapacity();
protected:
	T* _a;//实现动态的栈
	size_t _top;
	size_t _capacity;

};


template<class T>//记住写法
Stack<T>::Stack()
	:_a(NULL)
	, _top(0)
	, _capacity(0)
{}


template<class T>
Stack<T>::~Stack()//注意~的位置
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
		T* tmp = new T[_capacity];//不用malloc和free是因为new和delete会调构造函数和析构函数
		for (size_t i = 0; i < _top; i++)//用memcpy有身前拷贝的问题
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
	assert(_top > 0);//防御式编程
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
	return _a[_top - 1];//不能_a[--top]
}