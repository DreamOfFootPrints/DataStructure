#include"BSTree.h"



void Test1()
{
	BSTree<int, int> t;
	t.Insert(5, 1);
	t.Insert(3, 1);
	t.Insert(4, 1);
	t.Insert(1, 1);
	t.Insert(7, 1);
	t.Insert(8, 1);
	t.Insert(2, 1);
	t.Insert(6, 1);
	t.Insert(0, 1);
	t.Insert(9, 1);
	t.Inorder_NonR();


	cout << t.Find(5) << endl;
	cout << t.Find(10) << endl;
	cout << t.Find_R(5) << endl;
	cout << t.Find_R(10) << endl;

	t.Insert_R(10, 1);
	cout << t.Find_R(10) << endl;
	t.Remove_R(10);
	cout << t.Find_R(10) << endl;
	/*t.Remove_R(10);
	t.Remove_R(1);
	t.Remove_R(2);
	t.Remove_R(3);
	t.Remove_R(4);
	t.Remove_R(5);
	t.Remove_R(6);
	t.Remove_R(7);
	t.Remove_R(8);
	t.Remove_R(9);
	t.Remove_R(0);
	t.Remove_R(10);*/
	//cout << t._root << endl;
	t.Remove(10);//测试Remove的技巧，删除全部的情况，涉及到所有的情况
	t.Remove(1);
	t.Remove(2);
	t.Remove(3);
	t.Remove(4);
	t.Remove(5);
	t.Remove(6);
	t.Remove(7);
	t.Remove(8);
	t.Remove(9);
	t.Remove(0);
	t.Remove(10);
	cout << t._root << endl;



}

int main()
{
	Test1();
	system("pause");
	return 0;
}