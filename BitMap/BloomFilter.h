#pragma once
#include"Common.h"
#include"BitMap.h"




template<class K = string,
class HashFunc1 = __HashFunc1<K>,
class HashFunc2 = __HashFunc2<K>,
class HashFunc3 = __HashFunc3<K>,
class HashFunc4 = __HashFunc4<K>,
class HashFunc5 = __HashFunc5<K>
>

class BloomFilter
{
public:
	BloomFilter(size_t size)//注意声明顺序
		:_capacity(_GetNextPrime(size))
		,_bm(_capacity)
	{}


	void Set(const K& key)
	{
		size_t index1 = HashFunc1()(key);
		size_t index2 = HashFunc2()(key);
		size_t index3 = HashFunc3()(key);
		size_t index4 = HashFunc4()(key);
		size_t index5 = HashFunc5()(key);

		_bm.Set(index1%_capacity);
		_bm.Set(index2%_capacity);
		_bm.Set(index3%_capacity);
		_bm.Set(index4%_capacity);
		_bm.Set(index5%_capacity);

	}

	bool Test(const K& key)
	{
		size_t index1 = HashFunc1()(key);
		if (!_bm.Test(index1%_capacity))
		{
			return false;
		}

		size_t index2 = HashFunc2()(key);
		if (!_bm.Test(index2%_capacity))
		{
			return false;
		}

		size_t index3 = HashFunc3()(key);
		if (!_bm.Test(index3%_capacity))
		{
			return false;
		}

		size_t index4 = HashFunc4()(key);
		if (!_bm.Test(index4%_capacity))
		{
			return false;
		}
		
		size_t index5 = HashFunc5()(key);
		if (!_bm.Test(index5%_capacity))
		{
			return false;
		}

		return true;
	}


	void Resize(size_t size)
	{
		_bm._a.resize((size >> 5) + 1);
	}



private:
	size_t _capacity;
	BitMap _bm;

};



void TestBloomFilter()
{
	BloomFilter<> bf(100);
	bf.Set("C语言");
	bf.Set("Java");
	bf.Set("PHP");
	bf.Set("JS");
	bf.Set("C++");
	
	cout << "Is Exists?" << bf.Test("Java1") << endl;
	cout << "Is Exists?" << bf.Test("Java2") << endl;
	cout << "Is Exists?" << bf.Test("Java") << endl;
	cout << "Is Exists?" << bf.Test("C语言1") << endl;
	cout << "Is Exists?" << bf.Test("C++") << endl;

	//Reset不能踢，因为有可能影响其他人的判断

}

