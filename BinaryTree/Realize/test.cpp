#include"BinaryTree.h"


void Test1()
{
	int a1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> t1(a1, 10, '#');
	t1.PrevOrder();
	t1.Inorder();
	cout << "t1.Size:" << t1.Size() << endl;
	cout << "t1.Depth:" << t1.Depth() << endl;
	cout << "t1.leafSize" << t1.LeafSize() << endl;
	t1.LeveOrder();
}

int main()
{
	Test1();
	system("pause");
	return 0;
}