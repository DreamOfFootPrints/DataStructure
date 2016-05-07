#include"BinaryTreeThd.h"


void Test1()
{
	int a1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTreeThd<int> t1(a1, 10, '#');
	cout << endl;
}

int main()
{
	Test1();
	//Test2();
	system("pause");
	return 0;
}