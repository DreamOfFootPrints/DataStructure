#include"SparseMatirx.h"

void  SparseMatrixTest()
{
	int a[6][5]=
	{
		{1,0,3,0,5},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{2,0,4,0,6},
		{0,0,0,0,0},
		{0,0,0,0,0}
	};
	SparseMatrix<int> _sa((int*)a, 6, 5, 0);
	cout << endl;
	_sa.Display();
	/*SparseMatrix<int> sm1 = _sa.Transport();
	sm1.Display();*/
	SparseMatrix<int> sm2 = _sa.FastTransport();
	sm2.Display();
}

int main()
{
	SparseMatrixTest();
	system("pause");
	return 0;
}