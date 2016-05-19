#include<iostream>
#include<assert.h>
#include<stack>
using namespace std;


int GetMinIndex(int arr[], int left, int right);


void PrintArrray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


//2、快速排序
//[left,right]
int PartSort1(int arr[], int left, int right);
int PartSort2(int arr[], int left, int right);
int PartSort3(int arr[], int left, int right);
int PartSort3_MIN(int arr[], int left, int right);



void QuickSort(int arr[], int left,int right)
{
	assert(arr);
	if (left >= right)
		return;

	int div = PartSort3_MIN(arr, left, right);
	QuickSort(arr, left, div - 1);
	QuickSort(arr, div + 1, right);
}


//(1)大的数据往后翻，小的数据往千帆，key在正确的位置上

int PartSort1(int arr[], int left, int right)//返回key位置对应的下标
{
	int key = arr[right];
	int begin = left;
	int end = right - 1;


	while (begin < end)
	{
		while (begin<end&&arr[begin] <= key)
		{
			++begin;
		}
		while (begin < end&&arr[end]>=key)
		{
			--end;
		}
		if (begin < end)
		{
			swap(arr[begin], arr[end]);
		}
	}

	if (arr[begin]>arr[right])//两个元素组成的区间有序
	{
		swap(arr[begin], arr[right]);
		return begin;
	}
	else
	{
		return right;
	}
}

//2、挖坑法[left,right]
int PartSort2(int arr[], int left, int right)
{
	int key = arr[right];

	while (left < right)
	{ 
		while (left < right&&arr[left] <= key)
		{
			++left;
		}
		if (left < right)
		{
			arr[right--] = arr[left];
		}
		while (left<right&&arr[right]>=key)
		{
			--right;
		}
		if (left < right)
		{
			arr[left++] = arr[right];
		}
	}
	arr[left] = key;
	return left;
}


//3.单向扫描法
//（思想相同但是这个可以给单链表快速排序，因为不同倒着遍历链表）
int PartSort3(int arr[], int left, int right)
{
	int key = arr[right];
	int prev = left - 1;//指向大的数据前一个位置
	int cur = left;
	while (cur < right)
	{
		if (arr[cur] < key&&++prev != cur)
		{
			std::swap(arr[prev], arr[cur]);
		}
		++cur;
	}
	std::swap(arr[++prev], arr[right]);
	return prev;
}

//优化；三数取中法
int GetMinIndex(int arr[], int left, int right)
{
	int mid = left + (right - left) / 2;
	if (arr[left] < arr[mid])
	{
		if (arr[left] < arr[mid])
		{
			return mid;
		}
		else if (arr[left]<arr[right])//left<mid&&right<mid
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else //mid<left
	{
		if (arr[left] < arr[right])
		{
			return left;
		}
		else if (arr[mid] < arr[right])//mid<left&&right<left
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
}


int PartSort3_MIN(int arr[], int left, int right)
{
	int midIndex = GetMinIndex(arr, left, right);
	if (midIndex != right)
	{
		std::swap(arr[midIndex], arr[right]);//快速排序一定要选取左右作key
	}
	int key = arr[right];
	int prev = left - 1;//指向大的数据前一个位置
	int cur = left;
	while (cur < right)
	{
		if (arr[cur] < key&&++prev != cur)
		{
			std::swap(arr[prev], arr[cur]);
		}
		++cur;
	}
	std::swap(arr[++prev], arr[right]);
	return prev;
}


//2.减少递归次数：用直接插入排序进行优化

void InsertSort(int arr[],int left, int right)//[left,right]
{
	if (arr == NULL || right-left+1<= 0)
		return;

	for (int i = left; i < right; i++)
	{
		int end = i;//一个有序序列的结尾
		int tmp = arr[i + 1];
		while (end >= 0 && arr[end]>tmp)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = tmp;
	}
}

void QuickSort_Insett(int arr[], int left, int right)
{
	assert(arr);
	if (left >= right)
		return;

	if (right - left < 13)
	{
		InsertSort(arr, left,right);
	}

	int div = PartSort3_MIN(arr, left, right);
	QuickSort(arr, left, div - 1);
	QuickSort(arr, div + 1, right);
}


//非递归实现
void QuickSort_NonR(int arr[], int left, int right)
{
	assert(arr);
	stack<int> s;

	if (left < right)
	{
		s.push(right);
		s.push(left);
	}
	while (!s.empty())
	{
		left = s.top();
		s.pop();
		right = s.top();
		s.pop();
		if (right - left < 13)//库中给的是13，减少压栈
		{
			InsertSort(arr, left,right);
		}
		else
		{
			int div = PartSort3_MIN(arr, left, right);
			if (left < div - 1)
			{
				s.push(div - 1);
				s.push(left);
			}
			if (div < right)
			{
				s.push(right);
				s.push(div + 1);
			}
		}
	}
}