#include<iostream>
#include<queue>
#include<assert.h>
using namespace std;



template<class T>
class TwoQueueOfStack
{
public:
	TwoQueueOfStack(){};
	~TwoQueueOfStack(){};
public:
	void Push(const T& x);
	void Pop();
	T& Top();
	bool Empty()const;
	size_t Size()const;
protected:
	void Data1ToData2();
	void Data2ToData1();
private:
	queue<T> queueData1;
	queue<T> queueData2;
};


template<class T>
void TwoQueueOfStack<T>::Data1ToData2()
{
	while (!queueData1.empty())
	{
		queueData2.push(queueData1.front());
		queueData1.pop();
	}
}

template<class T>
void TwoQueueOfStack<T>::Data2ToData1()
{
	while (!queueData2.empty())
	{
		queueData1.push(queueData2.front());
		queueData2.pop();
	}
}



template<class T>
void  TwoQueueOfStack<T>::Push(const T& x)
{
	if (!queueData1.empty())
	{
		queueData1.push(x);
	}
	queueData2.push(x);
}


template<class T>
void  TwoQueueOfStack<T>::Pop()
{
	if (!queueData1.empty())
	{
		while (queueData1.size() != 1)
		{
			queueData2.push(queueData1.front());
			queueData1.pop();
		}
		queueData1.pop();
	}
	else 
	{
		assert(!queueData2.empty());
		while (queueData2.size()!=1)
		{
			queueData1.push(queueData2.front());
			queueData2.pop();
		}
		queueData2.pop();
	}
}

template<class T>
T& TwoQueueOfStack<T>::Top()
{
	if (!queueData1.empty())
	{
		return queueData1.back();
	}
	else
	{
		assert(!queueData2.empty());
		return queueData2.back();
	}
}



template<class T>
bool TwoQueueOfStack<T>::Empty()const
{
	return queueData1.empty() || queueData2.empty();
}

template<class T>
size_t TwoQueueOfStack<T>::Size()const
{
	return queueData1.size() + queueData2.size();
}
