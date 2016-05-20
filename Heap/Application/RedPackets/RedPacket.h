#include<iostream>
#include<assert.h>
#include<time.h>
#include<vector>
using namespace std;


#define N 100000
#define K 100


void AdjustDown(int* pKArray, size_t root, size_t size)
{
	size_t parent = root;
	size_t child = root * 2 - 1;
	while (child < size)
	{
		if (child + 1 < size&&pKArray[child + 1] < pKArray[child])
		{
			++child;
		}
		if (pKArray[parent] > pKArray[child])
		{
			std::swap(pKArray[parent], pKArray[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}



void GetTopK(const vector<int>& moneys, int n, int k)
{
	assert(n > k);
	int* topKArray = new int[k];
	for (size_t i = 0; i < k; ++i)
	{
		topKArray[i] = moneys[i];
	}
	//½¨Ð¡¸ù¶Ñ
	for (int i = (k - 2) / 2; i >= 0; --i)
	{
		AdjustDown(topKArray, 0, k);
	}
	for (size_t i = 0; i < k; ++i)
	{
		cout << topKArray[i] << " ";
	}
	cout << endl;
	delete[] topKArray;
}




void GreatRedPacket(vector<int>& moneys)
{
	srand(time(0));
	moneys.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		moneys.push_back(rand() % 1000);
	}

	for (int j = N - K; j < N; ++j)
	{
		moneys[j] = rand()%N;
	}

}