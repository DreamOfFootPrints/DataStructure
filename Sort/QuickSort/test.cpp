#include"QuickSort.h"


void TestPart1()
{
	int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	//int arr[] = { 3, 2, 4, 6, 7, 13, 23, 67, 34, 25, 16 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//SelectSort(arr, len);
	//QuickSort_Insett(arr, 0, len - 1);
	QuickSort_NonR(arr, 0, len - 1);
	PrintArrray(arr, len);
}

int main()
{
	TestPart1();
	system("pause");
	return 0;
}