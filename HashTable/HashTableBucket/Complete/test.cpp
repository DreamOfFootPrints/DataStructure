#include"HashTableBucket.h"

//���Ի������ܣ��Ƿ���Ա���ͨ��
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
	dict.Insert("Tom", "��ķ");
	dict.Insert("Jack", "�ܿ�");
	dict.Insert("Peter", "����");
	dict.Insert("ɾ��", "delete�� remove�� erase");
	dict.PrintTables();
	cout << dict.Find("ɾ��")->_value << endl;
	dict.Remove("Tom");
	dict.PrintTables();

}
void TestDict2()
{
	HashTableBucket<string, vector<string>> dict;

	vector<string> v;
	v.push_back("delete");
	v.push_back("remove");
	dict.Insert("ɾ��", v);

	HashTableNode<string, vector<string>>* ret = dict.Find("ɾ��");
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
	dict.Insert("Tom", "��ķ");
	dict.Insert("Jack", "�ܿ�");
	dict.Insert("Peter", "����");
	dict.Insert("ɾ��", "delete�� remove�� erase");
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
	Test3();//���Կ������캯����operator=����������
	system("pause");
	return 0;
}