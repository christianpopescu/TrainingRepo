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
	std::vector<Adjacency> adjList;
};

Vertex vert[3000];

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
		vert[i].key = INT_MAX/4;
		vert[i].inQueue = true;
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
	std::priority_queue<Vertex*, std::vector<Vertex*>, CompareVertex> q;
	for (int i = 0; i < numberOfVertex; i++)
	{
		q.push(&vert[i]);
	}
	while (!q.empty())
	{
		Vertex* vv = q.top();
		int u = vv->id;
		q.pop();
		vert[u].inQueue = false;
		sum += vert[u].key;
		for (int i = 0; i < vert[u].adjList.size(); i++)
		{
			int indexV = vert[u].adjList[i].vertexId;
			if ((vert[indexV].inQueue) &&
				(vert[u].adjList[i].weight < vert[indexV].key))
			{
				vert[indexV].key = vert[u].adjList[i].weight;
				vert[indexV].predId = u;
			}
		}
	} 
	cout << sum;
	return 0;
}

