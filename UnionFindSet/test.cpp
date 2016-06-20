#include"UnionFindSet.h"






//≤‚ ‘UnionFindSet
void TestUnionFindSet()
{
	UnionFindSet ufs(10);
	ufs.Union(0,6);
	ufs.Union(0, 7);
	ufs.Union(0, 8);
	ufs.Union(1, 4);
	ufs.Union(1, 9);
	ufs.Union(2, 3);
	ufs.Union(2, 5);
	ufs.Print();
	size_t root1 = ufs.FindRoot(4);
	size_t root2 = ufs.FindRoot(8);
	ufs.Union(root2, root1);
}


//≤‚ ‘Frind∫Ø ˝
void TestFriends()
{
	const int N = 5;
	const int M = 3;
	int r[N][M] = {{1, 2}, { 2, 3 }, { 4, 5 }};
	cout << Friends(N, M, r);
	cout << endl;
}




int main()
{
	//TestUnionFindSet();
	TestFriends();
	system("pause");
	return 0;
}