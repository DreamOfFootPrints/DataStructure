#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;


template<class T>//模版没写一个函数都要去测试一下
class StackWithMin
{
public:
	StackWithMin(){};//将会自动去掉对应的构造函数和析构函数
	virtual ~StackWithMin(){};
	void Push(const T& x);
	void Pop();
	const T& Min()const;//不是栈空间的变量，所以可以直接加引用返回，但是不能改变其的值，所以加const
	T& Top();
	bool Empty() const;
	size_t Size()const;
private:
	stack<T>  StackData;//数据栈，存放栈的所有元素     //使用类模板需要模板参数列表,没有特例话的模版参数
	stack<T>  StackMin;//辅助栈，存放栈中的最小元素
};

template<class T>
void StackWithMin<T>::Push(const T& x)
{
	StackData.push(x);
	if (StackMin.size() == 0 || x < StackMin.top())
		StackMin.push(x);
	else
		StackMin.push(StackMin.top());
}

template<class T>
void StackWithMin<T>::Pop()
{
	assert(StackData.size() > 0 && StackMin.size() > 0);//系统的stack不知道是用链表实现的还是用数组实现的，
														//所以这么写，不知道是和0比较还是和NULL比较
	StackData.pop();
	StackMin.pop();
}


template<class T>
const T& StackWithMin<T>::Min()const
{
	assert(StackData.size() > 0 && StackMin.size() > 0);

	return StackMin.top();
}

template<class T>
T& StackWithMin<T>::Top()
{
	return StackData.top();
}

template<class T>
bool StackWithMin<T>::Empty()const
{
	return StackData.size() == 0;
}





