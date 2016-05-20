#include"HashTableBucket.h"

//测试基本功能，是否可以编译通过
void Test1()
{
	HashTableBucket<int, char> t1;
	t1.Insert(1, 'a');
	t1.Insert(2, 'b');
	t1.Insert(3, 'c');
	t1.PrintTables();
	//cout << t1.Find(1)->_value << endl;
	t1.Remove(1);
	t1.Remove(2);
	t1.Remove(3);

	t1.PrintTables();
}



void TestDict()
{
	HashTableBucket<string, string> dict;
	dict.Insert("Tom", "汤姆");
	dict.Insert("Jack", "杰克");
	dict.Insert("Peter", "彼特");
	dict.Insert("删除", "delete、 remove、 erase");
	dict.PrintTables();
	cout << dict.Find("删除")->_value << endl;
	dict.Remove("Tom");
	dict.PrintTables();

}
void TestDict2()
{
	HashTableBucket<string, vector<string>> dict;

	vector<string> v;
	v.push_back("delete");
	v.push_back("remove");
	dict.Insert("删除", v);

	HashTableNode<string, vector<string>>* ret = dict.Find("删除");
	ret->_value.push_back("erase");

	vector<string>& words = ret->_value;
	for (size_t i = 0; i < words.size(); ++i)
	{
		cout << words[i] << endl;
	}
}

void Test3()
{
	HashTableBucket<string, string> dict;
	dict.Insert("Tom", "汤姆");
	dict.Insert("Jack", "杰克");
	dict.Insert("Peter", "彼特");
	dict.Insert("删除", "delete、 remove、 erase");
	dict.PrintTables();
	cout << endl;

	HashTableBucket<string, string> dict1(dict);
	dict1.PrintTables();
	HashTableBucket<string, string> dict2;
	dict2 = dict;
	dict2.PrintTables();
	

}

int main()
{
	//Test1();
	//TestDict1();
	//TestDict2();
	Test3();//测试拷贝构造函数、operator=和析构函数
	system("pause");
	return 0;
}