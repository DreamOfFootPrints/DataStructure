#pragma once
#include<iostream>
using namespace std;



enum Status
{
	EXIST,
	DELETE,
	EMPTY,
};


template<class K>
class HashTaable
{
public:
	HashTaable()
		:_tables(NULL)
		, _status(NULL)
		, _size(0)
		, _capacity(0)
	{}

	HashTaable(size_t size)
		:_tables(new K[size])
		, _status(new Status[size])
		, _size(0)
		, _capacity(size)
	{
		//for (_status, EMPTY, sizeof(_status)*_size);//ö�����Ͳ�����memsete��Ϊmemset�ǰ��ֽڴ���
		for (size_t i = 0; i < _capacity; ++i)
		{
			_status[i] = EMPTY;
		}
	}

	bool Insert(const K& key)
	{
		if (_size == _capacity)
		{
			cout << "Full" << endl;
			return false;
		}

		size_t index = _HashFunc(key);
		//����̽��
		while (_status[index] == EXIST)
		{
			if (_status[index] == key)
			{
				return false;
			}
			++index;
			if (index == _capacity)
			{
				index = 0;
			}
		}
		_status[index] = EXIST;
		_tables[index] = key;
		++_size;
		return true;
	}

	bool Find(const K& key)
	{
		if (_Find == -1)
		{
			return false;
		}
		return true;
	}

	bool Remove(const K& key)
	{
		int index = _Find(key);
		if (index!=-1)
		{
			_status[index] = DELETE;
			return true;
		}
		return false;
	}

	void PrintTable()
	{
		for (size_t i = 0; i < _capacity; ++i)
		{
			if (_status[i] == EXIST)
			{
				printf("[%d];E->%d", i, _tables[i]);
				cout << endl;
			}
			else if (_status[i]==DELETE)
			{
				printf("[%d];D->%d", i, _tables[i]);
				cout << endl;
			}
			else
			{
				printf("[%d];N", i);
				cout << endl;
			}
		}
	}


protected:
	size_t _HashFunc(const K& key)//��ϣ����
	{
		return key%_capacity;
	}

	int _Find(const K& key)
	{
		size_t index = _HashFunc(key);//Ĭ�Ϲ�ϣ����һ�����п����λ�õ�
		while (_status[index] != EMPTY)
		{
			if (_tables[index] == key&&_status[index] != DELETE)
			{
				return index;
			}
			++index;
			if (index == _capacity)
			{
				index = 0;
			}
		}
		return -1;
	}



protected:
	K* _tables;
	rsize_t _size;
	Status* _status;//״̬����
	size_t _capacity;
};