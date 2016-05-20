#include"HeapSort.h"

void Test1()
{
	int a[] = { 10, 11, 12, 14, 12, 1, 2, 3, 4, 15, 19 };
	int len = sizeof(a) / sizeof(a[0]);
	HeapSort(a, len);
	for (size_t i = 0; i < len; ++i)
	{
		cout << a[i] << " ";
	}
}

int main()
{
	Test1();
	system("pause");
	return 0;
}