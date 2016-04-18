#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<stack>

using namespace std;


struct Pos
{
	int _row;
	int _col;
};

void GetMaze(int* a, int n)
{
	assert(a);
	FILE* fout = fopen("MazeMap.txt", "r");
	assert(fout);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; )
		{
			char ch = fgetc(fout);
			if (ch == '1' || ch == '0')
			{
				a[i*n + j] = ch - '0';
				++j;
			}
		}
	}
}


void PrintMaze(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << a[i*n + j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}


bool CheckIsAccess(int* a, int n, const Pos& next)
{
	int  row = next._row;
	int col = next._col;
	if (row >= 0 && row < n
		&&col >= 0 && col < n
		&&a[row*n + col] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SearchMazeSize(int* a, int n, Pos entry, stack<Pos>& paths)
{
	assert(a);
	//Pos cur = entry;
	paths.push(entry);
	while (!paths.empty())
	{
		Pos cur = paths.top();
		a[cur._row*n + cur._col] = 2;
		if (cur._row == n - 1)
		{
			return true;
		}
		Pos next = cur;
		//ио
		next._row--;
		if (CheckIsAccess(a, n, next))
		{
			paths.push(next);
			continue;
		}
		//об
		next = cur;
		next._row++;
		if (CheckIsAccess(a, n, next))
		{
			paths.push(next);
			continue;
		}
		//вС
		next = cur;
		next._col--;
		if (CheckIsAccess(a, n, next))
		{
			paths.push(next);
			continue;
		}
		//ср
		next = cur;
		next._col++;
		if (CheckIsAccess(a, n, next))
		{
			paths.push(next);
			continue;
		}
		a[cur._row*n + cur._col] = 3;
		paths.pop();
	}
	return false;
}
