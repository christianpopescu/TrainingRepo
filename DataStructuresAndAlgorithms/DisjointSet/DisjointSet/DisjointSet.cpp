// DisjointSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
struct node
{
	int id;
	node* parent;
	int rank;
};

struct edge
{
	node* firstNode;
	node* secondNode;
	int weight;
};

std::vector<node> graphNodeList;

std::vector<edge> graphEdgeList;

bool CompareEdge(edge& first, edge& second)
{
	if (first.weight < second.weight) return true;
	return false;
}

void MakeSet(node & x)
{
	x.parent = &x;
	x.rank = 0;
}

node* FindSet(node& x)
{
	if (x.parent != &x) 
		x.parent = FindSet((*x.parent));
	return x.parent;
}

void Link(node& x, node& y)
{
	if (x.rank > y.rank)
		y.parent = &x;
	else
	{
		x.parent = &y;
		if (x.rank == y.rank)
			y.rank++;
	}
}

void Union(node& x, node& y)
{
	Link(*(FindSet(x)), *(FindSet(y)));
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	graphNodeList.reserve(n);
	//prepare nodes
	for (int i = 0; i < n; i++)
	{
		node x;
		x.id = i+1;
		graphNodeList.push_back(x);
	}

	graphEdgeList.reserve(m);
	for (int i = 0; i < m; i++)
	{
		int xx, yy, rr;
		std::cin >> xx >> yy >> rr;
		edge e;
		e.firstNode = &graphNodeList[xx-1];
		e.secondNode = &graphNodeList[yy-1];
		e.weight = rr;
		graphEdgeList.push_back(e);

	}
	std::sort(graphEdgeList.begin(), graphEdgeList.end(), CompareEdge);

//	std::vector<edge> mst;
	int sum = 0;
	for (int i = 0; i < n; i++)
		MakeSet(graphNodeList[i]);
	for (int j = 0; j < m; j++)
	{
		if (FindSet(*(graphEdgeList[j].firstNode)) != FindSet(*(graphEdgeList[j].secondNode)))
		{
//			mst.push_back(graphEdgeList[j]);
			sum += graphEdgeList[j].weight;
			Union(*(graphEdgeList[j].firstNode), *(graphEdgeList[j].secondNode));
		}
	}
	
	std::cout << sum;

	return 0;
}

