#include"RBTree.h"


void TestRBTree()
{
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int len = sizeof(arr) / sizeof(arr[0]);
	RBTree<int, int> t;
	for (int i = 0; i < len; i++)
	{
		t.Insert(arr[i], i);
		t.InOrder_NonR();
		cout << "Is?" << t.Check() << endl;
	}
	
}


int main()
{
	TestRBTree();
	system("pause");
	return 0;
}