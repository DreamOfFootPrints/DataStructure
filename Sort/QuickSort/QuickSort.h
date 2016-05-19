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


//2����������
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


//(1)����������󷭣�С��������ǧ����key����ȷ��λ����

int PartSort1(int arr[], int left, int right)//����keyλ�ö�Ӧ���±�
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

	if (arr[begin]>arr[right])//����Ԫ����ɵ���������
	{
		swap(arr[begin], arr[right]);
		return begin;
	}
	else
	{
		return right;
	}
}

//2���ڿӷ�[left,right]
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


//3.����ɨ�跨
//��˼����ͬ����������Ը����������������Ϊ��ͬ���ű�������
int PartSort3(int arr[], int left, int right)
{
	int key = arr[right];
	int prev = left - 1;//ָ��������ǰһ��λ��
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

//�Ż�������ȡ�з�
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
		std::swap(arr[midIndex], arr[right]);//��������һ��Ҫѡȡ������key
	}
	int key = arr[right];
	int prev = left - 1;//ָ��������ǰһ��λ��
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


//2.���ٵݹ��������ֱ�Ӳ�����������Ż�

void InsertSort(int arr[],int left, int right)//[left,right]
{
	if (arr == NULL || right-left+1<= 0)
		return;

	for (int i = left; i < right; i++)
	{
		int end = i;//һ���������еĽ�β
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


//�ǵݹ�ʵ��
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
		if (right - left < 13)//���и�����13������ѹջ
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