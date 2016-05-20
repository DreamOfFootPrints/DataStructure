#include<iostream>
using namespace std;



void AdjustDown(int* a, size_t size, size_t root)
{
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child]>a[parent])
		{
			std::swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, size_t size)
{
	//见堆
	for (int i = (size-2) / 2; i >= 0; --i)
	{
		AdjustDown(a, size, i);
	}
	for (size_t i = 0; i < size; ++i)
	{
		std::swap(a[0], a[size - i - 1]);//最后一个数的下标
		AdjustDown(a, size - i - 1, 0);//个数
	}
}