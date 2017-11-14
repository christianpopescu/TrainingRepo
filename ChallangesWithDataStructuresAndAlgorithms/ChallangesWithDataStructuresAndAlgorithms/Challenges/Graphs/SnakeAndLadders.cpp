#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "..\..\DataStructuresAndAlgorithms\Dijkstra.cpp"
using namespace std;



class SnakeAndLadders
{
	public:
	static int main() {
		
		int t;
		cin >> t;
		vector<Dijkstra*> vD;
		for (int i = 0; i < t; i++)
		{
			Dijkstra* d = new Dijkstra(100);
			for (int j = 1; j < 100; j++)
			{
				Dijkstra::Vertex v;
				Dijkstra::edgeFromVertex efv;
				v.id = j;
				efv.destination = j + 1;
				efv.weight = 1;
				v.adjList.push_back(efv);
				v.precedent = 0;
				v.distanceFromPrecedent = 0;
				v.distanceFromSource = 0;
				d->vertexList[j] = v;
			}
			vD.push_back(d);
		}

		for (int k = 0; k < t; k++)
		{
			int n;
			// ----------- ladders
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				int source, destination;
				cin >> source >> destination;
				vD[k]->AddEdge(source, destination, 0);
			}
			
			int m;
			// ---------- snakes
			cin >> m;
			for (int i = 0; i < m; i++)
			{
				int source, destination;
				cin >> source >> destination;
				vD[k]->AddEdge(source, destination, 0);
			}
		}

		for (int k = 0; k < t; k++)
		{
			vD[k]->ComputeSingleSourceAlgorithm(1);
			list<Dijkstra::PathElement> lpe = vD[k]->GetPath(1, 100);

		}
		/* Enter your code here. Read input from STDIN. Print output to STDOUT */
		return 0;
	}

};