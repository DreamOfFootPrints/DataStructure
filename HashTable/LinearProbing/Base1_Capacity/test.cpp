#include"HashTable.h"


void Test1()
{
	HashTaable<int> ht1(10);
	ht1.Insert(1);
	ht1.Insert(2);
	ht1.Insert(3);
	ht1.Insert(4);
	ht1.Insert(5);
	ht1.Insert(6);
	ht1.Insert(7);
	ht1.Insert(8);

	ht1.Insert(89);
	ht1.Insert(18);
	ht1.Insert(49);
	ht1.Insert(58);
	ht1.Insert(9);
	ht1.PrintTable();
	//ht1.Remove(8);
	ht1.Remove(9);
	ht1.PrintTable();
	if (ht1.Find(8))
		cout << "pass" << endl;
	else
		cout << "false" << endl;


}


int main()
{
	Test1();
	system("pause");
	return 0;
}