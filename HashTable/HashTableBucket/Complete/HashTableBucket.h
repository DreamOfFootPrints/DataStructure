#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class K>
struct DefaultHashFuncer
{
	size_t operator()(const K& key)
	{
		return key;
	}
};


template<>
struct DefaultHashFuncer <string>
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



template<class K, class V>
struct HashTableNode
{
public:
	K _key;
	V _value;
	HashTableNode<K, V>* _next;
public:
	HashTableNode(const K& key, const V& value)
		:_key(key)
		, _value(value)
		, _next(NULL)
	{}
};


template<class K, class V, class HashFuncer = DefaultHashFuncer<K>>
class HashTableBucket
{
	typedef HashTableNode<K, V> Node;
public:
	HashTableBucket()
		:_size(0)
	{}


	HashTableBucket(const HashTableBucket<K, V, HashFuncer>& ht)
	{
		_tables.resize(ht._tables.size());
		for (int i = 0; i < ht._tables.size(); ++i)
		{
			Node* cur = ht._tables[i];
			while (cur)
			{
				Insert(cur->_key, cur->_value);
				cur = cur->_next;
			}
		}
	}


	HashTableBucket<K, V, HashFuncer>& operator=(HashTableBucket<K, V, HashFuncer> ht)
	{
		_tables.swap(ht._tables);
		std::swap(_size, ht._size);
		return *this;
	}


	~HashTableBucket()
	{
		_Clear();
		_size = 0;
	}


	HashTableBucket(const HashTableBucket<K,V, HashFuncer>& ht)
	{
		_tables.resize(ht._tables.size());
		for (int i = 0; i < ht._tables.size(); ++i)
		{
			Node* cur = ht._tables[i];
			while (cur)
			{
				Insert(cur->_key, cur->_value);
				cur = cur->_next;
			}
		}
	}


	HashTableBucket<K, V, HashFuncer>& operator=(HashTableBucket<K, V, HashFuncer> ht)
	{
		_tables.swap(ht._tables);
		std::swap(_size, ht._size);
		return *this;
	}

	~HashTableBucket()
	{
			_Clear();
			_size = 0;
	}

	bool Insert(const K& key, const V& value)
	{
		//检查负载因子是否需要扩张
		
		_CheckExpand();
		size_t index = _HashFunc(key);
		//检查是否存在
		Node* begin = _tables[index];
		while (begin)
		{
			if (begin->_key == key)
			{
				return false;
			}
			begin = begin->_next;
		}
		//头插
		Node* tmp = new Node(key, value);
		tmp->_next = _tables[index];
		_tables[index] = tmp;
		++_size;
		return true;
	}

	Node* Find(const K& key)
	{
		size_t index = _HashFunc(key);
		Node* cur = _tables[index];
		while (cur)
		{
			if (cur->_key == key)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return NULL;
	}
	bool Remove(const K& key)
	{
		size_t index = _HashFunc(key);
		Node* cur = _tables[index];
		Node* prev = NULL;
		//1。空
		while (cur)
		{
			if (cur->_key == key)
			{
				break;
			}
			prev = cur;
			cur = cur->_next;
		}

		if (cur)
		{
			if (cur == _tables[index])
			{
				_tables[index] = cur->_next;
			}
			else
			{
				prev->_next = cur->_next;
			}
			delete cur;
			return true;
		}
		return false;
	}
	void PrintTables()
	{
		for (size_t i = 0; i < _tables.size(); ++i)
		{
			printf("Tables[%d]->", i);
			Node* cur = _tables[i];
			while (cur)
			{
				cout << cur->_key << "->";
				cur = cur->_next;
			}
			cout << "NULLL" << endl;
		}
		cout << endl;
	}


protected:
	size_t _HashFunc(const K& key)
	{
		
		return HashFuncer()(key) % _tables.size();
	}

	void _CheckExpand()
	{
		//素数表


		//负载因子到1，进行扩容
		if (_size == _tables.size())
		{
			size_t newSize = _GetNextPrime(_size);
			if (newSize == _size)
			{
				return;
			}
			vector<Node*> newTables;
			newTables.resize(newSize);
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* tmp = cur;
					cur = cur->_next;
					size_t index = _HashFunc(tmp->_key);
					tmp->_next = newTables[index];
					newTables[index] = tmp;
					_tables[i] = NULL;
				}
			}
			_tables.swap(newTables);
		}
	}

	size_t _GetNextPrime(size_t size)
	{
		const int _PrimeSize = 28;
		static const unsigned long _PrimeList[_PrimeSize] =
		{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
		};
		//可以设置一个静态的index	
		for (size_t i = 0; i < _PrimeSize; ++i)
		{
			if (_PrimeList[i] > _size)
			{
				return _PrimeList[i];
			}
		}
		return _PrimeList[_PrimeSize - 1];
	}


	void _Clear()
	{
		for (int i = 0; i < _tables.size(); ++i)
		{
			Node* cur = _tables[i];
			while (cur)
			{
				Node* del = cur;
				cur = cur->_next;
				delete del;
			}
			_tables[i] = NULL;
		}
	}

protected:
	vector<Node*> _tables;
	size_t _size;
};