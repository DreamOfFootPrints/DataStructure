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
	size_t operator()(const string& str)
	{
		size_t value = 0;
		for (size_t i = 0; i < str.size(); ++i)
		{
			value += str[i];
		}
		return value;
	}
};

template<class K, class V>
struct KeyValue
{
public:
	K _key;
	V _value;
public:
	KeyValue(const K& key=K(), const V& value=V())
		:_key(key)
		, _value(value)
	{}

};




template<class K,class V,class HashFuncer=DefaulstHashFuncer<K>>
class HashTaable
{
	typedef KeyValue<K,V> KV;
public:
	HashTaable()
		:_tables(NULL)
		, _status(NULL)
		, _size(0)
		, _capacity(0)
	{}

	HashTaable(size_t size)
		:_tables(new KV[size])
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


	bool Insert(const K& key,const V& value)
	{
		/*if (_size == _capacity)
		{
			cout << "Full" << endl;
			return false;
		}*/

		_CheckCapacity();

		int i = 1;
		size_t index = _HashFuncO(key);
		//����̽��
		while (_status[index] == EXIST)
		{
			if (_tables[index]._key == key)
			{
				return false;
			}
			index = _HashFunc(index, i++);
		}
		_status[index] = EXIST;
		_tables[index]._key = key;
		_tables[index]._value = value;
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
				cout << _tables[i]._key << endl;
			}
			else if (_status[i]==DELETE)
			{
				printf("[%d];D->", i);
				cout << _tables[i]._key;
			}
			else
			{
				printf("[%d];N", i);
				cout << endl;
			}
		}
	}

	



	void Swap(HashTaable<K,V>& ht)
	{
		std::swap(_tables, ht. _tables);
		std::swap(_size, ht._size);
		std::swap(_status, ht._status);
		std::swap(_capacity, ht._capacity);
	}


protected:
	size_t _HashFuncO(const K& key)
	{
		HashFuncer hf;
		return hf(key) % _capacity;
	}

	size_t _HashFunc(size_t prevHash,int i)//��ϣ����
	{
		return (prevHash + 2 * i - 1) % _capacity;
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
			HashTaable<K,V> tmp(2 * _capacity);
			for (size_t i = 0; i < _capacity; ++i)
			{
				if (_status[i] == EXIST)//״̬Ϊɾ��ʱ���ù�
				{
					tmp.Insert(_tables[i]._key,_tables[i]._value);
				}
			}
			this->Swap(tmp);//��ͻ�ı䣬���λ�øı�
		}
	}



protected:
	KV* _tables;
	size_t _size;
	Status* _status;//״̬����
	size_t _capacity;
};


