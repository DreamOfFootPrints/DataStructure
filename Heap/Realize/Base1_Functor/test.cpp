#include"Heap.h"

void Test1()
{
	//int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	//Heap<int> hp1(a, sizeof(a) / sizeof(int));
	//hp1.Push(20);
	//cout << endl;
}


void Test2()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	//Heap<int,Greater<int>> hp1(a, sizeof(a) / sizeof(int));
	//Heap<int,Greater> hp1(a, sizeof(a) / sizeof(int));//这种写法是错误的，编译不通过
	Heap<int> hp1(a, sizeof(a) / sizeof(int));
	hp1.Push(20);
	cout << endl;
}

int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}