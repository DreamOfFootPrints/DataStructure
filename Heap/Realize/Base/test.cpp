#include"Heap.h"

void Test1()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	Heap<int> hp1(a, sizeof(a) / sizeof(int));
	hp1.Push(20);
	cout << endl;
}

int main()
{
	Test1();
	system("pause");
	return 0;
}