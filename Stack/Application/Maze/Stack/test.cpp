#include"Maze.h"

#define N 10

void Test1()
{
	int a[N][N] = { 0 };
	GetMaze((int*)a, N);
	PrintMaze((int*)a, N);
	stack<Pos> paths;
	Pos entry = { 2,0 };//�������
	cout << "�Ƿ���ͨ·��" << SearchMazeSize((int*)a, N, entry, paths) << endl;
	cout << endl;
	PrintMaze((int*)a, N);
}

int main()
{
	Test1();
	system("pause");
	return 0;
}