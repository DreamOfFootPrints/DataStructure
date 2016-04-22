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


void Test2()
{
	int a1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> t1(a1, 10, '#');
	t1.PrevOrder();
	BinaryTree<int> t2(t1);
	t2.PrevOrder();
	BinaryTree<int> t3;
	t3 = t2;
	t3.PrevOrder();
}

void Test3()
{

	int a1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> t1(a1, 10, '#');
	t1.PrevOrder();
	t1.PrevOrder_NonR();
	t1.InOrder_NonR();
	t1.PosOrder_NonR();
	cout << t1.GetKLevel(3) << endl;
}



int main()
{
	//Test1();
	//Test2();
	Test3();
	system("pause");
	return 0;
}