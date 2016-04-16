#include<iostream>
#include<vector>//动态顺序表
using namespace std;



template<class T>
struct Triple
{
public:
	Triple(int row=0,int col=0,const T& value=T())
		:_row(row)
		, _col(col)
		, _value(value)
	{}
public:
	int _row;
	int _col;
	T _value;
};

template<class T>
class SparseMatrix
{
public:
	SparseMatrix(T* a, int m, int n, const T& invalid)//非法值
		:_rows(m)
		, _columns(n)
		, _invalid(invalid)
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (a[i*n + j] != invalid)
				{
				/*	Triple<T> t(i, j, a[i*n + j]);
					_a.push_back(t);*/
					//或者写成下面这样
					_a.push_back(Triple<T>(i, j, a[i*n + j]));
				}
			}
		}
	}

	SparseMatrix()
		:_columns(0)
		, _rows(0)
		, _invalid(0)
	{}
	
public:


	void Display()//打印
	{
		size_t index = 0;
		for (int i = 0; i < _rows; ++i)
		{
			for (int j = 0; j < _columns; ++j)
			{
				if (index < _a.size()
					&&_a[index]._row == i
					&&_a[index]._col == j)
				{
					cout << _a[index++]._value << " ";
				}
				else
				{
					cout << _invalid << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	SparseMatrix<T> Transport()//转置
	{
		SparseMatrix<T> tmp;
		tmp._invalid = _invalid;
		tmp._columns = _rows;
		tmp._rows = _columns;
		tmp._a.reserve(_a.size());
		for (size_t i = 0; i < _columns; ++i)
		{
			size_t index = 0;
			while (index < _a.size())
			{
				if (_a[index]._col == i)
				{
					Triple<T> tp;
					tp._row = _a[index]._col;
					tp._col = _a[index]._row;
					tp._value = _a[index]._value;
					tmp._a.push_back(tp);
				}
				++index;
			}
		}
		return tmp;
	}

	SparseMatrix<T>  FastTransport()//快速转置
	{
		SparseMatrix<T> tmp;
		tmp._invalid = _invalid;
		tmp._columns = _rows;
		tmp._rows = _columns;
		//tmp._a.reserve(_a.size());
		tmp._a.resize(_a.size());
		int* rowCount = new int[_columns];
		int* rowStarts = new int[_columns];
		memset(rowCount, 0, sizeof(int)*_columns);
		memset(rowStarts, 0, sizeof(int)*_columns);
		size_t index = 0;
		while (index < _a.size())
		{
			rowCount[_a[index]._col]++;
			index++;
		}
		rowStarts[0] = 0;
		for (size_t i = 1; i < _columns; ++i)
		{
			rowStarts[i] = rowStarts[i - 1] + rowCount[i - 1];
		}
		index = 0;
		while (index < _a.size())
		{
			int& rowStart = rowStarts[_a[index]._col];//一定要加引用，后面才可以++
			Triple<T> tp;
			tp._row = _a[index]._col;
			tp._col = _a[index]._row;
			tp._value = _a[index]._value;
			tmp._a[rowStart++] = tp; 
			++index;
		}
		delete[] rowStarts;
		delete[] rowCount;
		return tmp;
	}
protected:
	vector<Triple<T>> _a;
	size_t _rows;
	size_t _columns;
	T _invalid;
};


