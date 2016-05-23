#include<iostream>
#include<assert.h>
using namespace std;


void PrintArrray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}



//计数排序
void CountSort(int arr[], int size)
{
	assert(arr);
	
	int min = arr[0], max = arr[0];//统计最大和最小的数
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	int range = max - min + 1;//开空间的大小
	int* count = new int[range]();

	memset(count, 0, sizeof(int)*range);
	//统计次数
	for (int i = 0; i < size; i++)
	{
		count[arr[i] - min]++;
	}
	
	size_t index = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]-- != 0)
		{
			arr[index++] = i + min;
		}
	}
}



//基数排序

//获取最大的位数
int GetMaxRadix(int arr[], int size)
{
	int radix = 1;	//	至少有一位
	int max = 10;
	for (int i = 0; i < size; i++)
	{
		while (arr[i]>=max)
		{
			++radix;
			max *= 10;
		}
	}
	return radix;
}


void LSDSort(int arr[], int size)
{
	assert(arr);

	int maxRadix = GetMaxRadix(arr, size);
	int count[10] = { 0 };
	int start[10] = { 0 };
	int* bucket = new int[size];
	//有点像矩阵的那一块
	int radix = 1;
	for (int i = 0; i < maxRadix; ++i)//控制位数
	{
		memset(count, 0, sizeof(int) * 10);


		for (int j = 0; j < size; ++j)//统计对应的每次的低位相同的数字出现的次数
		{
			int num = (arr[j] / radix) % 10;//依次获取每一位的数字
			count[num]++;
		}
		start[0] = 0;//用来标记每相同低位的值到底有多少个，然后进行直接定位
		int index = 1;
		while (index < 10)
		{
			start[index] = start[index - 1] + count[index - 1];
			++index;
		}
		for (int k = 0; k < size; ++k)
		{
			int num = (arr[k] / radix) % 10;
			//关键
			bucket[start[num]++] = arr[k];//通过辅助的数组start直接进行定位
		}
		radix *= 10;
		memcpy(arr, bucket, sizeof(int)*size);

	}
	delete[] bucket;
}