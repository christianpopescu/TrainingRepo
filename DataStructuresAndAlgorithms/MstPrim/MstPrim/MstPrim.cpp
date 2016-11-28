// MstPrim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <queue>
struct Adjacency
{
	int vertexId;
	int weight;
};

struct Vertex
{
	int id;
	int key;
	int predId;
	bool inQueue;
	int queId;   // pointer to position in key structure
	std::vector<Adjacency> adjList;
};

Vertex vert[3000];



// priority queue structure

inline int left(int i)
{
	return ((i+1) * 2)-1;
}

inline int right(int i)
{
	return (2 * (i+1)) + 1 - 1;
}

inline int parent(int i)
{
	return i / 2;
}

struct Element
{
	int id;
	int key;
};

Element pq[5000];

int lengthPq = 0;
int sizePq = 0;

void ExchangeElements(Element* e, int i, int j)
{
	vert[e[i].key].queId = j;
	vert[e[j].key].queId = i;
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
	if (l < (sizePq-1) && e[l].key < e[i].key)
		smallest = l;
	else
		smallest = i;
	if (r < (sizePq-1) && e[r].key < e[smallest].key)
		smallest = r;
	if (smallest != i)
	{
		ExchangeElements(e, smallest, i);
		MinHeapify(e, smallest);
	}
}

void BuildMinHeap(Element*e, int pLength)
{
	sizePq = pLength;
	for (int i = (pLength / 2) - 1; i >= 0; i--)
		MinHeapify(e, i);
}

Element HeapExtractMin(Element*e)
{
	Element min = e[0];
	e[0] = e[sizePq-1];
	sizePq--;
	MinHeapify(e, 0);
	return min;
}

void HeapDecreaseKey(Element* e, int i, int key)
{
	if (key > e[i].key) return; // nothing to do
	while (i > 0 && e[parent(i)].key > e[i].key)
	{
		ExchangeElements(e, parent(i), i);
		i = parent(i);

	}
}


// graph structure

class CompareVertex
{
public:
	bool operator()(Vertex* leftV, Vertex* rightV)
	{
		return leftV->key > rightV->key;
	}
};


int numberOfVertex = 0;

int main()
{
	using namespace std;
	int n, m;
	cin >> n >> m;
	numberOfVertex = n;
	for (int i = 0; i < numberOfVertex; i++)
	{
		vert[i].id = i;
		vert[i].predId = -1;
		vert[i].key = INT_MAX;
		vert[i].inQueue = true;
		vert[i].queId = i;
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, r;
		cin >> x >> y >> r;
		Adjacency ax;
		ax.vertexId = x - 1;
		ax.weight = r;
		vert[y - 1].adjList.push_back(ax);
		ax.vertexId = y - 1;
		vert[x - 1].adjList.push_back(ax);
	}
	int s;
	cin >> s;
	s--;
	vert[s].key = 0;
	int sum = 0;
	// initialize queue
	//std::priority_queue<Vertex*, std::vector<Vertex*>, CompareVertex> q;
	lengthPq = numberOfVertex;

	for (int i = 0; i < numberOfVertex; i++)
	{
		// add to priority ADT
		//q.push(&vert[i]);
		pq[i].id = i;
		pq[i].key = vert[i].key;
	}
	BuildMinHeap(pq, lengthPq);
	while (sizePq >0)
	{
		Element elem = HeapExtractMin(pq);
		int u = elem.id;
		vert[elem.id].inQueue = false;
		vert[elem.id].key = elem.key;
		sum += elem.key;
		for (int i = 0; i < vert[u].adjList.size(); i++)
		{
			int indexV = vert[u].adjList[i].vertexId;
			if ((vert[indexV].inQueue) &&
				(vert[u].adjList[i].weight < pq[vert[indexV].queId].key))
			{
				pq[vert[indexV].queId].key = vert[u].adjList[i].weight;
				vert[indexV].predId = u;
			}
		}
		if (sizePq >0) BuildMinHeap(pq, sizePq);
	} 
	cout << sum;
	return 0;
}

