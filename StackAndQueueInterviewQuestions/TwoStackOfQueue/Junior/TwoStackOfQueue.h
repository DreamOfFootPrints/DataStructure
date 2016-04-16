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
	T& Front();//ע��д��
	const T& Back();
	bool Empty()const;
	size_t Size()const;
	void Print();
protected:
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
	stackPush.push(x);
}


template<class T>
void TwoStackOfQueue<T>::Pop()
{
	assert(!stackPush.empty());
	PushToPop();
	stackPop.pop();
	PopToPush();
}

template<class T>
T& TwoStackOfQueue<T>::Front()
{
	assert(!stackPush.empty());
	//PushToPop();
	//T& ret = stackPop.top();//ע�⣬����д���Ǵ���ģ����õĵײ��൱��ָ�룬����ȥ��ʱ��Front�ֻص���ջ�ף�
							//֮���Բ����������ϵͳջ�ĵײ�ʵ������Ϊͨ������ʵ�ֵģ�������ͨ����ʽ�ṹ
	while (stackPush.size() != 1)
	{
		stackPop.push(stackPush.top());
		stackPush.pop();
	}
	T& ret = stackPush.top();//Ҫ�����ã�Ҫ��Ȼ�����Ըı����е�ֵ
	PopToPush();
	return ret;
}


template<class T>
const T& TwoStackOfQueue<T>::Back()
{
	assert(!stackPush.empty());
	return  stackPush.top();
}

template<class T>
bool TwoStackOfQueue<T>::Empty()const
{
	return stackPush.empty();
}

template<class T>
size_t TwoStackOfQueue<T>::Size()const
{
	return stackPush.size();
}

template<class T>
void TwoStackOfQueue<T>::Print()
{
	PushToPop();
	while (!stackPop.empty())
	{
		cout << stackPop.top()<<" ";
		stackPush.push(stackPop.top());
		stackPop.pop();
	}
	cout << endl;
}







 