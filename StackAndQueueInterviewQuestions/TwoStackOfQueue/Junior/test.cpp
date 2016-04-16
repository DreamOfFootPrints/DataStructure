#include"TwoStackOfQueue.h"

void Test1()
{
	TwoStackOfQueue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Print();
}

void Test2()
{
	TwoStackOfQueue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Pop();
	q.Pop();
	q.Print();
}

void Test3()
{
	TwoStackOfQueue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	cout << q.Front() << endl;
	cout << q.Back() << endl;
	q.Front() = 55;
	cout << q.Front() << endl;
	//q.Back() = 10;
	cout << q.Back() << endl;
	cout << q.Size() << endl;
	if (!q.Empty())
	{
		cout << "pass" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}

void Test4()
{
	TwoStackOfQueue<int> q;
	q.Push(1);
	q.Push(2);
	q.Front() = 10;
	cout << q.Front() << endl;
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