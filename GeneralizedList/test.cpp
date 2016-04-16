#include"GeneralizedList.h"

void Test1()
{
	Generalized g1("()");
	g1.Print();
	Generalized g2("(a,b)");
	g2.Print();
	Generalized g3("(a,b,(c,d))");
	g3.Print();
	Generalized g4("(a,b,(c,d),(e,(f),h))");
	g4.Print();
	cout << "g4.Size():" << g4.Size() << endl;
	cout << "g4.Dopth():" << g4.Depth() << endl;
	Generalized g5(g4);
	g5.Print();
	g3 = g4;
	g3.Print();
}




int main()
{
	Test1();
	system("pause");
	return 0;
}