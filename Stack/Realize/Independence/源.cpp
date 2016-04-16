#include"Stack.h"


void Test1()
{
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	while (!s1.Empty())
	{
		cout << s1.Top() << " ";
		s1.Pop();
	}
}



void Test2()
{
	Stack<int> s1;
	if (s1.Empty())
	{
		cout << "pass" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	if (s1.Empty())
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
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	s1.Top() = 10;
	cout << s1.Size() << endl;
	while (!s1.Empty())
	{
		cout << s1.Top() << endl;
		s1.Pop();
	}
	cout << s1.Size() << endl;
}

int main()
{
	Test1();
	//Test2();
	//Test3();
	system("pause");
	return 0;
}