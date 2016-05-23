#pragma once
#include<iostream>
#include"Heap.h"
using namespace std;


template<class T>
struct HuffmanNode
{
	
	HuffmanNode<T>* _left;
	HuffmanNode<T>* _right;
	T _weight;//Ȩֵ
public:
	HuffmanNode(const T& w)
		:_weight(w)
		, _left(NULL)
		, _right(NULL)
	{}
};



template<class T>
class HuffmanTree
{
	typedef HuffmanNode<T> Node;
public:
	HuffmanTree()
		:_root(NULL)
	{}

	HuffmanTree(const T* a, size_t size)
	{
		_root = _GreatTree(a, size);
	}

	void GenerateHuffmanCode();//��ʲô����ô��


protected:
	Node* _GreatTree(const T* a, size_t size)
	{
		struct Compare//����С����
		{
			bool operator()(const Node* l, const Node* r)
			{
				return l->_weight < r->_weight;
			}
		};

		Heap<Node*,Compare> minHeap;//������ǽڵ㣬������T���͵ľ��������,��Ϊ����ô�ڵ�ժ�������ǲ��Ǻ������û����
		
		for (size_t i = 0; i < size; i++)
		{
			minHeap.Push(new Node(a[i]));
		}

		while (minHeap.Size()>1)//����ʹ��minHeap.Empty()����Ϊ��������ԣ���ʣ��ֻ��һ���������
		{
			Node* left = minHeap.Top();
			minHeap.Pop();
			Node* right = minHeap.Top();
			minHeap.Pop();
			
			Node* parent = new Node(left->_weight + right->_weight);
			parent->_left = left;
			parent->_right = right;
			minHeap.Push(parent);
		}
		
		return minHeap.Top();
	}
protected:
	Node* _root;
};