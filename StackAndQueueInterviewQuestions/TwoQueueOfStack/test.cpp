#include"TwoQueueOfStack.h"


void Test1()
{
	TwoQueueOfStack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Pop();
	s.Top() = 10;
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	cout << s.Size() << endl;
	cout << s.Empty() << endl;
}

int main()
{
	Test1();
	system("pause");
	return 0;
}