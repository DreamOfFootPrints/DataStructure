#include"StackWithMin.h"


void Test1()
{
	StackWithMin<int > min;
	cout << endl;
}

void Test2()
{
	StackWithMin<int> min;
	min.Push(1);
	min.Pop();
	min.Push(1);
	min.Min();
	cout << min.Top() << endl;
	if (!min.Empty())
	{
		cout << "pass" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

}


void Test3()
{
	StackWithMin<int> min;
	min.Push(1);
	min.Push(2);
	min.Push(1);
	cout << min.Min() << endl;
	min.Pop();
	cout << min.Min() << endl;
}

int main()
{
	//Test1();
	//Test2();
	Test3();
	system("pause");
	return 0;
}