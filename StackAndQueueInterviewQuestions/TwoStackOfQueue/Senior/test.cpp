#include"TwoStackOfQueue.h"

void Test1()
{
	TwoStackOfQueue<int> q;
	q.Push(1);
	q.Pop();
	q.Push(2);
	q.Pop();
	q.Push(3);
	q.Push(4);
	q.Push(5);
	q.Push(6);
	cout << q.Front() << endl;
	cout << q.Back() << endl;
	q.Front() = 10;
	cout << q.Front() << endl;
	//q.Back() = 10;
}

int main()
{
	Test1();
	system("pause");
	return 0;
}