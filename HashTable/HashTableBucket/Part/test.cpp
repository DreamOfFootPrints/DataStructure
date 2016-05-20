#include"HashTableBucket.h"



void Test1()
{
	HashTableBucket<int, char> t1;
	t1.Insert(1, 'a');
	t1.Insert(2, 'b');
	t1.Insert(3, 'c');
	//t1.PrintTables();
	//cout << t1.Find(1)->_value << endl;
	t1.Remove(1);
	t1.Remove(2);
	t1.Remove(3);

	//t1.PrintTables();

	for (size_t i = 0; i < 53; ++i)
	{
		char ch= 0;
		t1.Insert(i, ch + i);
	}
	t1.PrintTables();


}


void Test2()
{
	
	
}

int main()
{
	Test1();
	Test2();
	system("pause");
	return 0;
}