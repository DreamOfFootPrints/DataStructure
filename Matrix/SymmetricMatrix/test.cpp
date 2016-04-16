#include"SymmetricMatrix.h"


void Test1()
{
	int a[5][5] = 
	{
		{0,1,2,3,4},
		{1,0,1,2,3},
		{2,1,0,1,2},
		{3,2,1,0,1},
		{4,3,2,1,0}
	};
	SymmetricMatrix<int> sm((int*)a, 5);
	cout << endl;
}


int main()
{
	Test1();
	system("pasue");
	return 0;
}