#pragma once
#include<iostream>
#include<string>
using namespace std;

//添加增容

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
		//for (_status, EMPTY, sizeof(_status)*_size);//枚举类型不能用memsete因为memset是按字节处理
		for (size_t i = 0; i < _capacity; ++i)//若用memset则里面为随机值
		{
			_status[i] = EMPTY;
		}
	}

	~HashTaable()
	{
		if (_tables)
		{
			delete[] _tables;
			delete[] _status;
			_tables = NULL;
			_status = NULL;
		}
	}


	bool Insert(const K& key)
	{
		/*if (_size == _capacity)
		{
			cout << "Full" << endl;
			return false;
		}*/

		_CheckCapacity();

		size_t index = _HashFunc(key);
		//线性探测
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
		if (_Find(key) == -1)
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


	void Swap(HashTaable<K>& ht)
	{
		std::swap(_tables, ht. _tables);
		std::swap(_size, ht._size);
		std::swap(_status, ht._status);
		std::swap(_capacity, ht._capacity);
	}


protected:
	size_t _HashFunc(const K& key)//哈希函数
	{
		return key%_capacity;
	}

	int _Find(const K& key)
	{
		size_t index = _HashFunc(key);//默认哈希表中一定是有空余的位置的
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

	void _CheckCapacity()
	{
		if (_size * 10 >= _capacity * 7)
		{
			/*K* tmpTables = new int[2 * _capacity];
			K* tmpStatus = new Status[2 * _capaci



			ty];
			for (size_t i = 0; i < _capacity;++i)
			{

			}*/
			HashTaable<K> tmp(2 * _capacity);
			for (size_t i = 0; i < _capacity; ++i)
			{
				if (_status[i] == EXIST)//状态为删除时不用管
				{
					tmp.Insert(_tables[i]);
				}
			}
			this->Swap(tmp);//冲突改变，相对位置改变
		}
	}



protected:
	K* _tables;
	rsize_t _size;
	Status* _status;//状态数组
	size_t _capacity;
};