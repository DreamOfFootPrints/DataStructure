#include"HuffmanTree.h"



void Test1()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	HuffmanTree<int> t(arr, len);
}

int main()
{
	Test1();
	system("pause");
	return 0;
}