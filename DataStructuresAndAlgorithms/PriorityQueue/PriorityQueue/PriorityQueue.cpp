// PriorityQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

inline int left(int i)
{
	return i * 2;
}

inline int right(int i)
{
	return (2 * i) + 1;
}

inline int parent(int i)
{
	return i / 2;
}

struct Element
{
	int key;
};

Element pq[5000];

int lengthPq = 0;
int sizePq = 0;

void ExchangeElements(Element* e, int i, int j)
{
	Element temp;
	temp = e[i];
	e[i] = e[j];
	e[j] = temp;
}

void MinHeapify(Element* e, int i)
{
	int smallest;
	int l = left(i);
	int r = right(i);
	if (l < sizePq && e[l].key < e[i].key)
		smallest = l;
	else
		smallest = i;
	if (r < sizePq && e[r].key < e[smallest].key)
		smallest = r;
	if (smallest != i);
	ExchangeElements(e, smallest, i);
	MinHeapify(e, smallest);
}

int main()
{
    return 0;
}

