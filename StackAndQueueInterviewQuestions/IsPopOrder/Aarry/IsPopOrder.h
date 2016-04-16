#include<iostream>
#include<stack>
using namespace std;



bool g_InvalidInput = false;
bool IsPopOrder(const int dataPush[], const int dataPop[], int length1,int length2)
{
	if (dataPush == NULL || dataPop == NULL || length1!=length2||length1<=0)
	{
		g_InvalidInput = true;
		return false;
	}
	int length = length1;
	const int* cur = dataPop;
	stack<int> stackData;
	for (int i = 0; i < length; ++i)
	{
		stackData.push(dataPush[i]);
		while (stackData.size()!=0&&stackData.top() == *cur)
		{
			stackData.pop();
			cur++;
		}
	}
	if (stackData.empty()&&stackData.size() == 0)
		return true;
	return false;
}