#pragma once
#include<iostream>
#include<string>
using namespace std;

//�������

enum Status
{
	EXIST,
	DELETE,
	EMPTY,
};

//�º���
template<class K>
struct DefaulstHashFuncer
{
	size_t operator()(const K& key)
	{
		return key;
	}
};



template<>
struct DefaulstHashFuncer <string>
{

	static size_t BKDRHash(const char * str)
	{
		unsigned int seed = 131; // 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}

	size_t operator()(const string& str)
	{
		return BKDRHash(str.c_str());
	}
};




template<class K,class HashFuncer=DefaulstHashFuncer<K>>
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
		for (size_t i = 0; i < _capacity; ++i)//����memset������Ϊ���ֵ
		{
			_status[i] = EMPTY;
		}
	}

	HashTaable(const HashTaable<K, HashFuncer>& ht)
		:_tables(NULL)
		, _status(NULL)
		, _size(0)
		, _capacity(0)
	{
		HashTaable<K, HashFuncer> tmp(ht._capacity);
		for (size_t i = 0; i <ht._capacity; ++i)
		{
			if (ht._status[i] == EXIST)//״̬Ϊɾ��ʱ���ù�
			{
				tmp.Insert(ht._tables[i]);
			}
		}
		this->Swap(tmp);//��ͻ�ı䣬���λ�øı�
	}


	HashTaable<K, HashFuncer>& operator=(HashTaable<K, HashFuncer> ht)
	{
		/*if (this != &ht)
		{
			
		}*/
		this->Swap(ht);
		return *this;
	}



	~HashTaable()
	{
		if (_tables!=NULL)
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
		//����̽��
		while (_status[index] == EXIST)
		{
			if (_tables[index] == key)
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
				printf("[%d];E->", i);
				cout << _tables[i] << endl;
			}
			else if (_status[i]==DELETE)
			{
				printf("[%d];D->", i);
				cout <<_tables[i];
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
	size_t _HashFunc(const K& key)//��ϣ����
	{
		HashFuncer hf;
		return hf(key) % _capacity;

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
				if (_status[i] == EXIST)//״̬Ϊɾ��ʱ���ù�
				{
					tmp.Insert(_tables[i]);
				}
			}
			this->Swap(tmp);//��ͻ�ı䣬���λ�øı�
		}
	}



protected:
	K* _tables;
	rsize_t _size;
	Status* _status;//״̬����
	size_t _capacity;
};


