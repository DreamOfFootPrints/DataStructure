#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
class StaticOneArrayOfTwoStack
{
public:
	StaticOneArrayOfTwoStack(int size = 5);
	~StaticOneArrayOfTwoStack();
public:
	void Stack1Push(const T& x);
	void Stack2Push(const T& x);
	void Stack1Pop();
	void Stack2Pop();
	T& Stack1Top()const;
	T& Stack2Top()const;
	bool Stack1Empty()const;
	bool Stack2Empty()const;
	size_t Stack1Size()const;
	size_t Stack2Size()const;
protected:
	bool _IsFull();//每一个栈都会预留出一个的位置，要不然判断full太麻烦
//private:
public:
	T* _a;
	size_t _size;
	size_t _stack1TopIndex;
	size_t _stack2TopIndex;
	//size_t _stack1Begin;
	//size_t _stack2Begin;
	//size_t _stack1End;
	//size_t _stack2End;
};


template<class T>
StaticOneArrayOfTwoStack<T>::StaticOneArrayOfTwoStack(int size = 5)
	:_a(new int[size])
	, _size(size)
	, _stack1TopIndex(0)
	, _stack2TopIndex(size-1)
{}


template<class T>
StaticOneArrayOfTwoStack<T>::~StaticOneArrayOfTwoStack()
{
	if (_a != NULL)
	{
		delete[] _a;
	}
}


template<class T>
bool StaticOneArrayOfTwoStack<T>::_IsFull()
{
	return _stack2TopIndex - _stack1TopIndex==0;
}

template<class T>
void StaticOneArrayOfTwoStack<T>::Stack1Push(const T& x)
{
	if (_IsFull())
	{
		cout << "Stack1 if full" << endl;
		assert(false);
		return;
	}
	_a[_stack1TopIndex++] = x;
}

template<class T>
void StaticOneArrayOfTwoStack<T>::Stack1Pop()
{
	assert(_stack1TopIndex != 0);
	--_stack1TopIndex;
}

template<class T>
T& StaticOneArrayOfTwoStack<T>::Stack1Top()const
{
	assert(_stack1TopIndex != 0);
	return _a[_stack1TopIndex - 1];
}

template<class T>
bool  StaticOneArrayOfTwoStack<T>::Stack1Empty()const
{
	return _stack1TopIndex == 0;
}

template<class T>
size_t StaticOneArrayOfTwoStack<T>::Stack1Size()const
{
	return (_stack1TopIndex - 0);
}


//////////////////////////////////////
template<class T>
void StaticOneArrayOfTwoStack<T>::Stack2Push(const T& x)
{
	if (_IsFull())
	{
		cout << "Stack1 if full" << endl;
		assert(false);
	}
	_a[_stack2TopIndex--] = x;
}

template<class T>
void StaticOneArrayOfTwoStack<T>::Stack2Pop()
{
	assert(_stack2TopIndex != _size-1);
	++_stack2TopIndex;
}

template<class T>
T& StaticOneArrayOfTwoStack<T>::Stack2Top()const
{
	assert(_stack2TopIndex != _size-1);
	return _a[_stack2TopIndex + 1];
}

template<class T>
bool  StaticOneArrayOfTwoStack<T>::Stack2Empty()const
{
	return _stack2TopIndex == _size-1;
}

template<class T>
size_t StaticOneArrayOfTwoStack<T>::Stack2Size()const
{
	return (_stack2TopIndex - (_size-1));
}






 








