#include"TwoStackOfQueue.h"


void Test1()
{
	TwoStackOfQueue < int> q;
	q.Push(1);
	q.Push(2);
	q.Pop();
	cout<<q.Front()<<endl;
	cout << q.Back() << endl;
	if (!q.Empty())
	{
		cout << "pass" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	cout << q.Size() << endl;
	cout << endl;
}

int main()
{
	Test1();
	system("pause");
	return 0;
}