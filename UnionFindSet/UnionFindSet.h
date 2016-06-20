#include<iostream>]
using namespace std;
#include<assert.h>

class UnionFindSet
{
public:
	UnionFindSet(size_t n)
		:_n(n)
		, _set(new int[n])
	{
		for (size_t i = 0; i < n; ++i)
		{
			_set[i] = -1;
		}
	}
	void Union(int root1, int root2)
	{
		assert(_set[root1]<0);
		assert(_set[root2]<0);
		_set[root1] += _set[root2];
		_set[root2] = root1;
	}
	size_t  FindRoot(int child)
	{
		size_t root = child;
		while (_set[root] >= 0)
		{
			root = _set[root];
		}
		return root;
	}

	void Print()
	{
		for (size_t i = 0; i < _n; i++)
		{
			cout << _set[i] << " ";
		}
		cout << endl;
	}


private:
	size_t _n;
	int* _set;
};




//小米面试题
size_t FindRoot(int* set, int child)//寻找根
{
	int root = child;
	while (set[root] > 0)
	{
		root = set[root];
	}
	return root;
}

//1、强制类型转换
//2、直接传二维n[][3]
int Friends(int n, int m, int r[][3])
{
	//初始化并查集
	int* set = new int[n + 1];
	for (size_t i = 0; i < n + 1; i++)
	{
		set[i] = -1;
	}
	for (size_t i = 0; i < n; ++i)
	{
		int root1 = FindRoot(set,  r[i][0]);
		int root2 = FindRoot(set, r[i][1]);
		if (root1 != root2)
		{
			set[root1] += set[root2];
			set[root2] = root1;
		}
	}
	size_t count = 0;
	for (size_t i = 1; i < n + 1; ++i)
	{
		if (set[i] < 0)
		{
			count++;
		}
	}
	return count;
}



