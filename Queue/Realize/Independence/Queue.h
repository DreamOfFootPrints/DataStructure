#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

template<class T>
struct Node
{
public:
	Node(const T& x)
		:_data(x)
		,_next(NULL)
	{}
public:
	T _data;
	Node<T>* _next;
};



template<class T>
class Queue
{
public:
	Queue();
	~Queue();//析构函数不能光声明不定义，这样编译不通过,切记
public:
	void Push(const T& x);
	void Pop();
	bool Empty();
	size_t Size();
	T& Front();
	T& Back();
protected:
	void Clear();
protected:
	Node<T>* _head;
	Node<T>* _tail;
	size_t _size;
};


template<class T>
Queue<T>::Queue()
	:_head(NULL)
	, _tail(NULL)
{}


template<class T>
void Queue<T>::Clear()
{
	Node<T>* cur = _head;
	while (cur!=NULL)
	{
		Node<T>* del = cur;
		cur = cur->_next;
		delete del;
	}
	_head = NULL;
	_tail = NULL;
	_size = 0;
}

template<class T>
Queue<T>::~Queue()
{
	Clear();
}

template<class T>
void Queue<T>::Push(const T& x)
{
	if (_head == NULL)
	{
		_head = _tail = new Node<T>(x);
	}
	else
	{
		_tail->_next = new Node<T>(x);
		_tail = _tail->_next;
	}
	++_size;
}


template<class T>
void Queue<T>::Pop()
{
	assert(_head != NULL);
	if (_head == _tail)
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node<T>* del = _head;
		_head = _head->_next;
		delete del;
	}
	--_size;
}


template<class T>
bool Queue<T>::Empty()
{
	return _head == NULL;
}


template<class T>
size_t Queue<T>::Size()
{
	return _size;
}


template<class T>
T& Queue<T>::Front()
{
	assert(_head);
	return _head->_data;
}


template<class T>
T& Queue<T>::Back()
{
	assert(_tail != NULL);
	return _tail->_data;
}
