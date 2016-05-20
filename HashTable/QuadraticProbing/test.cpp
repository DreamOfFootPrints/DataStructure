#include"HashTable.h"




//void Test1()
//{
//	HashTaable<int> ht1(10);
//	ht1.Insert(1);
//	ht1.Insert(2);
//	ht1.Insert(3);
//	ht1.Insert(4);
//	ht1.Insert(5);
//	ht1.Insert(6);
//	ht1.Insert(7);
//	ht1.Insert(8);
//
//	ht1.Insert(89);
//	ht1.Insert(18);
//	ht1.Insert(49);
//	ht1.Insert(58);
//	ht1.Insert(9);
//	ht1.PrintTable();
//	//ht1.Remove(8);
//	ht1.Remove(9);
//	ht1.PrintTable();
//	if (ht1.Find(8))
//		cout << "pass" << endl;
//	else
//		cout << "false" << endl;
//
//
//}
//
//
//void Test2()
//{
//	HashTaable<string> ht1(10);//使用仿函数解决这个问题
//	ht1.Insert("小明");
//	ht1.Insert("小军");
//	ht1.Insert("杰克");
//	ht1.Insert("明小");
//
//	ht1.PrintTable();
//}

void Test3()
{
	//key/value  二次探测  == 》字典
	HashTaable<string, string> ht1(13);
	ht1.Insert("peter", "张老师");
	ht1.Insert("jack", "杰克");
	ht1.Insert("rose", "玫瑰");
	ht1.PrintTable();
}


int main()
{
	//Test1();
	//Test2();
	Test3();
	system("pause");
	return 0;
}