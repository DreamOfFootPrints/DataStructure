#include<iostream>
using namespace std;
#include<stack>
#include<vector>



bool IsPopOrder(vector<int>pushV, vector<int>popV)
{
	if (pushV.size() != popV.size() || pushV.size() <= 0)
		return false;
	int len = pushV.size();
	int indexPopV = 0;
	stack<int> stackData;
	for (int i = 0; i < len&&indexPopV<len; ++i)
	{
		stackData.push(pushV[i]);
		while (stackData.size() != 0 && stackData.top() == popV[indexPopV])
		{
			stackData.pop();
			indexPopV++;
		}
	}
	if (stackData.empty()&&stackData.size() == 0)
	{
		return true;
	}
	return false;
}