#include"StaticOneArrayOfTwoStack.h"



void Test1()
{
	StaticOneArrayOfTwoStack<int> a;
	a.Stack1Push(1);
	//a.Stack1Push(2);
	//a.Stack1Push(3);
	//a.Stack1Push(4);
	//a.Stack1Push(5);
	//a.Stack1Pop();
	//cout << a.Stack1Top() << endl;
	if (!a.Stack1Empty())
	{
		cout << "pass" << endl;
	}
	else
	{
		cout << "false" << endl;
	}


}


void Test2()
{
	StaticOneArrayOfTwoStack<int> a;
	a.Stack1Push(1);
	a.Stack1Push(2);
	a.Stack1Push(3);
	a.Stack1Push(4);
	a.Stack1Push(5);
	a.Stack1Pop();
	cout << a.Stack1Top() << endl;
	cout << a.Stack1Size() << endl;
	if (!a.Stack1Empty())
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
	StaticOneArrayOfTwoStack<int> a;
	a.Stack2Push(1);
	a.Stack2Pop();
	//a.Stack2Top();
	cout << a.Stack2Empty() << endl;
	cout << true << endl;
	cout << a.Stack2Size() << endl;
}

void Test4()
{
	StaticOneArrayOfTwoStack<int> a;
	a.Stack1Push(1);
	a.Stack1Push(1);
	a.Stack1Push(1);
	cout << endl;
	a.Stack2Push(1);
	a.Stack2Push(1);


}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();
	system("pause");
	return 0;
}