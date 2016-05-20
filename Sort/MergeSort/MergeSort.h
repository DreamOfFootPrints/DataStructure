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

void _MergeSort(int arr[], int* tmp, int left, int right);//��������Ļ���
void _Merge(int arr[], int* tmp, int begin1, int end1, int begin2, int end2);//��������


void MergeSort(int arr[], int size)
{
	assert(arr);
	int* tmp = new int[size]();
	_MergeSort(arr, tmp, 0, size - 1);//[left,right]
}



void _MergeSort(int arr[], int* tmp, int left, int right)
{
	if (left < right)//gap=2���������кϲ�����tmp��
	{
		int mid = left + (right - left) / 2;
		_MergeSort(arr, tmp, left, mid);
		_MergeSort(arr, tmp, mid + 1, right);
		_Merge(arr, tmp, left, mid, mid + 1, right);
		for (int i = left; i <= right; i++)
		{
			arr[i] = tmp[i];
		}
	}
}


void _Merge(int arr[], int* tmp, int begin1, int end1, int begin2, int end2)
{
	int index = begin1;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}
}



