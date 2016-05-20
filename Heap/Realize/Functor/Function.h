#include<iostream>
using namespace std;


template<class T>
struct Less
{
	bool operator()(const T& l, const T& r)
	{
		return l < r;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& l, const T& r)
	{
		return l > r;
	}
};


void TestFuner()
{
	Less<int> less;
	cout << less(1, 2) << endl;
}
