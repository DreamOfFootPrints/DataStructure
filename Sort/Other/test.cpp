#include"Sort.h"



void TestInsertSort()
{
	int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1 ,0};
	int len = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, len);
	PrintArrray(arr, len);
}


void TestShellSort()
{
	int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, len);
	PrintArrray(arr, len);
}

void TestSelectSort()
{
	//int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int arr[] = { 3, 2, 4, 6, 7, 13, 23, 67, 34, 25, 16 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//SelectSort(arr, len);
	SelectSort_OP(arr, len);
	PrintArrray(arr, len);
}


void TestBubbleSort()
{
	//int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int arr[] = { 3, 2, 4, 6, 7, 13, 23, 67, 34, 25, 16 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//BubbleSort(arr, len);
	//BubbleSort_OP1(arr, len);
	//BubbleSort_OP2(arr, len);
	BubbleSort_OP3(arr, len);
	PrintArrray(arr, len);
}


void TestHeapSort()
{
	int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	//int arr[] = { 3, 2, 4, 6, 7, 13, 23, 67, 34, 25, 16 };
	int len = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, len);
	PrintArrray(arr, len);
}


int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestBubbleSort();
	TestHeapSort();
	system("pause");
	return 0;
}