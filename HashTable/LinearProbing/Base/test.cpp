#include"HashTable.h"


void Test1()
{
	HashTaable<int> ht1(10);
	ht1.Insert(89);
	ht1.Insert(18);
	ht1.Insert(49);
	ht1.Insert(58);
	ht1.Insert(9);
	ht1.PrintTable();

}


int main()
{
	Test1();
	system("pause");
	return 0;
}