#include"NotCompareSort.h"



void Test1()
{
	//int arr[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int arr[] = { 3, 2, 4, 6, 7, 13, 23, 67, 34, 25, 16 };
	int len = sizeof(arr) / sizeof(arr[0]);

	//CountSort(arr, len);
	LSDSort(arr, len);
	PrintArrray(arr, len);
}

int main()
{
	Test1();
	system("pause");
	return 0;
}