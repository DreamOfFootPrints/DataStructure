#include"Queue.h"


void Test1()
{
	Queue<int> q1;
	q1.Push(1);
	q1.Pop();
	cout << q1.Empty() << endl;
	cout << q1.Size() << endl;
	q1.Push(1);
	q1.Push(2);
	cout << q1.Front() << endl;
	cout << q1.Back() << endl;

}

int main()
{
	Test1();
	system("pause");
	return 0;
}