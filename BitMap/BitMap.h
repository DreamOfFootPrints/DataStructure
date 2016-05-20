#pragma once
#include<vector>
#include"Common.h"



class BitMap
{

public:
	BitMap(size_t size)
		:_size(0)
	{
		//_a.resize(size / 32 + 1);//��ʵ/�ǽ�����������Ľ�����������ȽϺ�
		_a.resize((size >> 5) + 1);
	}

	void Set(size_t x)//����
	{
		size_t index = x>>5;
		size_t num = x % 32;
		if (!(_a[index] & (1 << num)))
		{
			++_size;//_size��ֵ�ĺ���Ϊλͼ���Լ��洢�����ݸ���
			_a[index] |= (1 << num);
		}
	}

	void Reset(size_t x)//�Ƴ�
	{
		size_t index = x >> 5;
		size_t num = x % 32;
		_a[index] &= (~(1 << num));
	}

	bool Test(size_t x)
	{
		size_t index = x >> 5;
		size_t num = x % 32;
		return (_a[index] & (1 << num))!=0;
	}

	size_t Size()
	{
		return _size;
	}

protected:
	vector<size_t> _a;
	size_t _size;
};





void TestBitMap()
{
	BitMap bm(100);
	bm.Set(5);
	bm.Set(4);
	cout << "Is 4 Exists?" << bm.Test(4) << endl;
	cout << "Is 5 Exists?" << bm.Test(5) << endl;
	cout << "Is 6 Exists?" << bm.Test(6) << endl;
	bm.Reset(5);
	cout << "Is 5 Exists?" << bm.Test(5) << endl;

}
