#pragma once 
#include<iostream>
using namespace std;



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
		if (_PrimeList[i] > size)
		{
			return _PrimeList[i];
		}
	}
	return _PrimeList[_PrimeSize - 1];
}



template<class T>
size_t BKDRHash(const T *str)
{
	register size_t hash = 0;
	while (size_t ch = (size_t)*str++)
	{
		hash = hash * 131 + ch;       
	}
	return hash;
}


template<class K>
struct __HashFunc1
{
	size_t operator()(const K& key)
	{
		return BKDRHash(key.c_str());
	}
};





/// @brief SDBM Hash Function  
/// @detail 本算法是由于在开源项目SDBM（一种简单的数据库引擎）中被应用而得名，它与BKDRHash思想一致，只是种子不同而已。  
template<class T>
size_t SDBMHash(const T *str)
{
	register size_t hash = 0;
	while (size_t ch = (size_t)*str++)
	{
		hash = 65599 * hash + ch;
		//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
	}
	return hash;
};



template<class K>
struct __HashFunc2
{
	size_t operator()(const K& key)
	{
		return SDBMHash(key.c_str());
	}
};




template<class T>
size_t RSHash(const T *str)
{
	register size_t hash = 0;
	size_t magic = 63689;
	while (size_t ch = (size_t)*str++)
	{
		hash = hash * magic + ch;
		magic *= 378551;
	}
	return hash;
}

template<class K>
struct __HashFunc3
{
	size_t operator()(const K& key)
	{
		return RSHash(key.c_str());
	}
};



template<class T>
size_t APHash(const T *str)
{
	register size_t hash = 0;
	size_t ch;
	for (long i = 0; ch = (size_t)*str++; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
		}
	}
	return hash;
}


template<class K>
struct __HashFunc4
{
	size_t operator()(const K& key)
	{
		return APHash(key.c_str());
	}
};



template<class T>
size_t JSHash(const T *str)
{
	if (!*str)        
		return 0;
	register size_t hash = 1315423911;
	while (size_t ch = (size_t)*str++)
	{
		hash ^= ((hash << 5) + ch + (hash >> 2));
	}
	return hash;
}


template<class K>
struct __HashFunc5
{
	size_t operator()(const K& key)
	{
		return JSHash(key.c_str());
	}
};




