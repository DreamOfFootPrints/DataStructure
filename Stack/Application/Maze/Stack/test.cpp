#include"Maze.h"

#define N 10

void Test1()
{
	int a[N][N] = { 0 };
	GetMaze((int*)a, N);
	PrintMaze((int*)a, N);
	stack<Pos> paths;
	Pos entry = { 2,0 };//入口坐标
	cout << "是否有通路？" << SearchMazeSize((int*)a, N, entry, paths) << endl;
	cout << endl;
	PrintMaze((int*)a, N);
}

int main()
{
	Test1();
	system("pause");
	return 0;
}