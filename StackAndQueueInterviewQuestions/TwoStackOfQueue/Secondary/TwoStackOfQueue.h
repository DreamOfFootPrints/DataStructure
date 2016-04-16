#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

template<class T>
class TwoStackOfQueue
{
public:
	TwoStackOfQueue(){};
	~TwoStackOfQueue(){};
public:
	void Push(const T& x);
	void Pop();
	T& Front();//×¢ÒâÐ´·¨
	const T& Back();
	bool Empty()const;
	size_t Size()const;
public:
	void PushToPop();
	void PopToPush();
private:
	stack<T> stackPush;
	stack<T> stackPop;
};


template<class T>
void TwoStackOfQueue<T>::PushToPop()
{
	while (!stackPush.empty())
	{
		stackPop.push(stackPush.top());
		stackPush.pop();
	}
}


template<class T>
void TwoStackOfQueue<T>::PopToPush()
{
	while (!stackPop.empty())
	{
		stackPush.push(stackPop.top());
		stackPop.pop();
	}
}


template<class T>
void TwoStackOfQueue<T>::Push(const T& x)
{
	if (stackPush.empty())
	{
		PopToPush();
	}
	stackPush.push(x);
}

template<class T>
void TwoStackOfQueue<T>::Pop()
{
	if (stackPop.empty())
	{
		PushToPop();
	}
	stackPop.pop();
}


template<class T>
T& TwoStackOfQueue<T>::Front()
{
	if (stackPop.empty())
	{
		assert(!stackPush.empty());
		PushToPop();
	}
	return stackPop.top();
}

template<class T>
const T& const TwoStackOfQueue<T>::Back()
{
	if (stackPush.empty())
	{
		assert(!stackPop.empty());
		PopToPush();
	}
	return stackPush.top();
}


template<class T>
bool TwoStackOfQueue<T>::Empty()const
{
	if (stackPush.empty())
	{
		return stackPop.empty();
	}
	return stackPush.empty();
}


template<class T>
size_t TwoStackOfQueue<T>::Size()const
{
	if (stackPush.empty())
	{
		return stackPop.size();
	}
	return stackPush.size();
}










