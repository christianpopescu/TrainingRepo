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
				// ---- init vertex
				v.id = j;
				efv.destination = j + 1;
				efv.weight = 1;
				v.adjList.push_back(efv);
				v.precedent = 0;
				v.distanceFromPrecedent = 0;
				v.distanceFromSource = 0;
				// --- add vertex to the vertex list
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
			if (vD[k]->vertexList[100].precedent >100)
			{
				cout << -1 << endl;
				break;
			}
			list<Dijkstra::PathElement> lpe = vD[k]->GetPath(1, 100);
			auto it = lpe.begin();
			int result = 0;
			int partialResult = 0;
			do
			{
				partialResult = 0;
				// compute contigous part of the path (with no zero weight edge)
				// 
				while (it != lpe.end() && (it->weight >0))
					// not end of path end not edge of weight 0
				{
					partialResult += it->weight;	
					++it;
				}
				result += ((partialResult / 6) + ((partialResult % 6 > 0) ? 1 : 0));
				if (it != lpe.end()) ++it;
			} while (it != lpe.end());
			cout << result << endl;
		}
		/* Enter your code here. Read input from STDIN. Print output to STDOUT */
		return 0;
	}

};