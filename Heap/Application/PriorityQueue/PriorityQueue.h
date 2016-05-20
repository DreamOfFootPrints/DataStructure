#include"Heap.h"



template<class T,template<class> class Compare=Less>
class PriorityQueue
{
public:
	void Push(const T& x)
	{
		_hp.Push(x);
	}

	void Pop()
	{
		_hp.Pop();
	}
	
	T& Top()
	{
		return Top();
	}

	size_t Size()
	{
		return _hp.Size();
	}

	bool Empty()
	{
		return _hp.Empty();
	}

protected:
	Heap<T, Compare> _hp;
};


 