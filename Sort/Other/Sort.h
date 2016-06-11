#include<iostream>
using namespace std;



void PrintArrray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}



//一。比较排序
//1.插入排序
//（1）直接插入排序
void InsertSort(int arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;

	for (int i =0; i < size-1; i++)
	{
		int end = i;//一个有序序列的结尾
		int tmp = arr[i+1];
		while (end >= 0 && arr[end]>tmp)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = tmp;
	}
}


//（2）希尔排序--插入排序的优化
void ShellSort(int arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;
	int gap = size;

	while (gap > 1)
	{
		gap = gap / 3 + 1;//保证当gap《3时，gap的值转换为1
		for (int i = 0; i < size - gap; ++i)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0 && arr[end]>tmp)//几个不同的区间同时控制，而不是控制完一个区间，再控制下一个区间
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = tmp;
		}
	}
}


//1、选择排序
//（1）选择排序
void SelectSort(int* arr, int size)
{
	if (arr == NULL&&size <= 0)
		return;

	for (int i = 0; i < size; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		std::swap(arr[minIndex], arr[i]);
	}

}

//优化
void SelectSort_OP(int* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		for (int i = left; i <= right; i++)
		{
			if (arr[i] < arr[left])
			{
				std::swap(arr[i], arr[left]);
			}
			if (arr[i] > arr[right])
			{
				std::swap(arr[i], arr[right]);
			}
		}
		left++;
		right--;
	}
}

//堆排序
void AdjustDown(int arr[],int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if ((child + 1 < size)&&(arr[child + 1] > arr[child]))
		{
			child++;
		}

		if (arr[child]>arr[parent])
		{
			std::swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;

	for (int i =  (size - 2) / 2;i>=0; i--)//从后向前建堆
	{
		AdjustDown(arr, size, i);
	}

	for (int i = 0; i < size; i++)
	{
		std::swap(arr[0], arr[size-1-i]);//最后一个位置的下标
		AdjustDown(arr, size - 1 - i, 0);//数据的个数，注意这里是size-1-i,因为已经发生了一次交换
	}
}


//3.交换排序
//（1）冒泡排序
void BubbleSort(int arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
	}

}

//优化一：内层优化
void BubbleSort_OP1(int arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;

	for (int i = 0; i < size - 1; i++)
	{
		int flag = -1;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				flag = j;
			}
		}
		if (flag == -1)
			break;
	}
}

//优化二：记录最后一次发生交换的位置
void BubbleSort_OP2(int arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;

	int lastSwapPos = size - 1;//最后一个发生交换的位置，下面由这句话控制i < end
	while (lastSwapPos > 0)
	{
		int end = lastSwapPos;
		for (int i = 0; i < end; i++)//注意这里是<不是<=，因为下面是arr[i]和arr[i+1]比较
		{
			if (arr[i] > arr[i + 1])
			{
				lastSwapPos = i;
				std::swap(arr[i], arr[i + 1]);
			}
		}
		if (lastSwapPos == end)
		{
			break;
		}
	}
}

//优化三：每个区间遍历两次[left,right]
void BubbleSort_OP3(int arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;

	int left = 0;
	int right = size - 1;
	
	while (left < right)
	{
		int lastSwapPos = right;

		for (int i = 0; i < lastSwapPos; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				right = i;
				std::swap(arr[i], arr[i + 1]);
			}
		}
		if (lastSwapPos == right)
			break;

		lastSwapPos = left;
		for (int i = right; i > lastSwapPos; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				left = i;
				std::swap(arr[i], arr[i - 1]);
			}
		}
		if (lastSwapPos == left)
			break;
	}
}

