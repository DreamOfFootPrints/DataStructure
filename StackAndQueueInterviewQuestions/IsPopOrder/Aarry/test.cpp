#include"IsPopOrder.h"

void Test1()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 4, 5, 3, 2, 1 };
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	if (IsPopOrder(arr1, arr2, len1, len2))
	{
		cout << "pass" << endl;
	}
	else
	{
		cout << "flase" << endl;
	}
}


void Test2()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 4, 3, 5, 1, 2 };
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	if (IsPopOrder(arr1, arr2, len1, len2))
	{
		cout << "pass" << endl;
	}
	else
	{
		cout << "flase" << endl;
	}
}

int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}