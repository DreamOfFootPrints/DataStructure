#include<iostream>
#include<assert.h>
using namespace std;


void PrintArrray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}



//��������
void CountSort(int arr[], int size)
{
	assert(arr);
	
	int min = arr[0], max = arr[0];//ͳ��������С����
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	int range = max - min + 1;//���ռ�Ĵ�С
	int* count = new int[range]();

	memset(count, 0, sizeof(int)*range);
	//ͳ�ƴ���
	for (int i = 0; i < size; i++)
	{
		count[arr[i] - min]++;
	}
	
	size_t index = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]-- != 0)
		{
			arr[index++] = i + min;
		}
	}
}



//��������

//��ȡ����λ��
int GetMaxRadix(int arr[], int size)
{
	int radix = 1;	//	������һλ
	int max = 10;
	for (int i = 0; i < size; i++)
	{
		while (arr[i]>=max)
		{
			++radix;
			max *= 10;
		}
	}
	return radix;
}


void LSDSort(int arr[], int size)
{
	assert(arr);

	int maxRadix = GetMaxRadix(arr, size);
	int count[10] = { 0 };
	int start[10] = { 0 };
	int* bucket = new int[size];
	//�е���������һ��
	int radix = 1;
	for (int i = 0; i < maxRadix; ++i)//����λ��
	{
		memset(count, 0, sizeof(int) * 10);


		for (int j = 0; j < size; ++j)//ͳ�ƶ�Ӧ��ÿ�εĵ�λ��ͬ�����ֳ��ֵĴ���
		{
			int num = (arr[j] / radix) % 10;//���λ�ȡÿһλ������
			count[num]++;
		}
		start[0] = 0;//�������ÿ��ͬ��λ��ֵ�����ж��ٸ���Ȼ�����ֱ�Ӷ�λ
		int index = 1;
		while (index < 10)
		{
			start[index] = start[index - 1] + count[index - 1];
			++index;
		}
		for (int k = 0; k < size; ++k)
		{
			int num = (arr[k] / radix) % 10;
			//�ؼ�
			bucket[start[num]++] = arr[k];//ͨ������������startֱ�ӽ��ж�λ
		}
		radix *= 10;
		memcpy(arr, bucket, sizeof(int)*size);

	}
	delete[] bucket;
}