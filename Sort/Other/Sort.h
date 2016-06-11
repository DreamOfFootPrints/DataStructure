#include<iostream>
using namespace std;



void PrintArrray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}



//һ���Ƚ�����
//1.��������
//��1��ֱ�Ӳ�������
void InsertSort(int arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;

	for (int i =0; i < size-1; i++)
	{
		int end = i;//һ���������еĽ�β
		int tmp = arr[i+1];
		while (end >= 0 && arr[end]>tmp)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = tmp;
	}
}


//��2��ϣ������--����������Ż�
void ShellSort(int arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;
	int gap = size;

	while (gap > 1)
	{
		gap = gap / 3 + 1;//��֤��gap��3ʱ��gap��ֵת��Ϊ1
		for (int i = 0; i < size - gap; ++i)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0 && arr[end]>tmp)//������ͬ������ͬʱ���ƣ������ǿ�����һ�����䣬�ٿ�����һ������
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = tmp;
		}
	}
}


//1��ѡ������
//��1��ѡ������
void SelectSort(int* arr, int size)
{
	if (arr == NULL&&size <= 0)
		return;

	for (int i = 0; i < size; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		std::swap(arr[minIndex], arr[i]);
	}

}

//�Ż�
void SelectSort_OP(int* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		for (int i = left; i <= right; i++)
		{
			if (arr[i] < arr[left])
			{
				std::swap(arr[i], arr[left]);
			}
			if (arr[i] > arr[right])
			{
				std::swap(arr[i], arr[right]);
			}
		}
		left++;
		right--;
	}
}

//������
void AdjustDown(int arr[],int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if ((child + 1 < size)&&(arr[child + 1] > arr[child]))
		{
			child++;
		}

		if (arr[child]>arr[parent])
		{
			std::swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int* arr, int size)
{
	if (arr == NULL || size <= 0)
		return;

	for (int i =  (size - 2) / 2;i>=0; i--)//�Ӻ���ǰ����
	{
		AdjustDown(arr, size, i);
	}

	for (int i = 0; i < size; i++)
	{
		std::swap(arr[0], arr[size-1-i]);//���һ��λ�õ��±�
		AdjustDown(arr, size - 1 - i, 0);//���ݵĸ�����ע��������size-1-i,��Ϊ�Ѿ�������һ�ν���
	}
}


//3.��������
//��1��ð������
void BubbleSort(int arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
	}

}

//�Ż�һ���ڲ��Ż�
void BubbleSort_OP1(int arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;

	for (int i = 0; i < size - 1; i++)
	{
		int flag = -1;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				flag = j;
			}
		}
		if (flag == -1)
			break;
	}
}

//�Ż�������¼���һ�η���������λ��
void BubbleSort_OP2(int arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;

	int lastSwapPos = size - 1;//���һ������������λ�ã���������仰����i < end
	while (lastSwapPos > 0)
	{
		int end = lastSwapPos;
		for (int i = 0; i < end; i++)//ע��������<����<=����Ϊ������arr[i]��arr[i+1]�Ƚ�
		{
			if (arr[i] > arr[i + 1])
			{
				lastSwapPos = i;
				std::swap(arr[i], arr[i + 1]);
			}
		}
		if (lastSwapPos == end)
		{
			break;
		}
	}
}

//�Ż�����ÿ�������������[left,right]
void BubbleSort_OP3(int arr[], int size)
{
	if (arr == NULL || size <= 0)
		return;

	int left = 0;
	int right = size - 1;
	
	while (left < right)
	{
		int lastSwapPos = right;

		for (int i = 0; i < lastSwapPos; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				right = i;
				std::swap(arr[i], arr[i + 1]);
			}
		}
		if (lastSwapPos == right)
			break;

		lastSwapPos = left;
		for (int i = right; i > lastSwapPos; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				left = i;
				std::swap(arr[i], arr[i - 1]);
			}
		}
		if (lastSwapPos == left)
			break;
	}
}

