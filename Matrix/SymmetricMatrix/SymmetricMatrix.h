#pragma once
#include<iostream>
#include<assert.h>
using namespace std;


template<class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(T* a, size_t size)
		:_a(new T[size*(size+1)/2])
		, _size(size*(size+1)/2)
	{
		assert(a);
		size_t index = 0;
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = 0; j < size; ++j)
			{
				if (i >= j)
				{
					_a[index++] = a[i*size + j];
				}
				else
				{
					break;
				}
			}
		}
	}
	T& Access(size_t i, size_t j)
	{
		if (i < j)
		{
			swap(i, j);//上三角形转换为下三角形
		}
		return _a[i*(*+1) / 2 + j];
	}

protected:
	T* _a;
	size_t _size;
};

