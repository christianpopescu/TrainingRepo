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
	static int minDice(int start, int end, vector<bool>& available)
	{
		bool minDicePossible = true;
		int nbDice = 0;
		if (end - start <= 6) return 1;
		int current = start;
		while ((end - current >0) && (minDicePossible))
		{
			// find next if exists 
			bool findNext = false;
			for (int m = 6; m > 1; m--)
			{
				if (current + m >= end)
				{
					nbDice++;
					return nbDice;
				}
				if (available[current + m])
				{
					current = current + m;
					nbDice++;
					findNext = true;
					break;
				}
			}
			if (!findNext) minDicePossible = false;
		}
		return 0;
	}

	static int main() {
		
		vector<int> sourceList;
		vector<int> destinationList;
		vector<bool> available;
		int t;
		cin >> t;
		vector<bool> isSnake;

		for (int i = 0; i < 101; i++)
			isSnake.push_back(false);

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
				/*efv.destination = j + 1;
				efv.weight = 1;
				v.adjList.push_back(efv);*/
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
			sourceList.clear();
			destinationList.clear();
			available.clear();
			for (int m = 0; m < 101; m++)
			{
				available.push_back(true);
			}
			sourceList.push_back(1); // add game start point

			int n;
			// ----------- ladders
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				int source, destination;
				cin >> source >> destination;
				//if (destination > source + 1)
				vD[k]->AddEdge(source, destination, 0);
				sourceList.push_back(destination);
				destinationList.push_back(source);
				available[source] = false;
			}
			
			int m;
			// ---------- snakes
			cin >> m;
			isSnake.clear();
			for (int i = 0; i < 101; i++)
				isSnake.push_back(false);

			for (int i = 0; i < m; i++)
			{
				int source, destination;
				cin >> source >> destination;
				//vD[k]->vertexList[source].adjList.clear();  // no vertex could leave a sneak source
				vD[k]->AddEdge(source, destination, 0);
				isSnake[source] = true;
				sourceList.push_back(destination);
				destinationList.push_back(source);
				available[source] = false;
			}
			
			destinationList.push_back(100); // add game end point

			for (int i = 0; i < sourceList.size(); i++)
				for (int j = 0; j < destinationList.size(); j++)
				{
					int weight = 0;
					if (sourceList[i] < destinationList[j])
						if ((weight = minDice(sourceList[i], destinationList[j], available)) > 0)
							vD[k]->AddEdge(sourceList[i], destinationList[j], weight);
				}
/*			// add jump snake edge if possible
			for (int j = 1; j < 100; j++)
			{
				if (isSnake[j] && !isSnake[j - 1])
					for (int i = 0; i < 5; i++)
					{
						if (!isSnake[j+1+i])
						{
							vD[k]->AddEdge(j-1, j+1+i, 2+i);
							break;
						}
					}
						
			}
*/
		}

		for (int k = 0; k < t; k++)
		{
			vD[k]->ComputeSingleSourceAlgorithm(1);
			if ((vD[k]->vertexList[100].precedent >99)||(vD[k]->vertexList[100].precedent <=0))
			{
				cout << -1 << endl;
				continue;
			}
			list<Dijkstra::PathElement> lpe = vD[k]->GetPath(1, 100);
			if (lpe.size() == 0 )
			{
				cout << -1 << endl;
				continue;
			}
			int result = 0;
			for (auto pe: lpe)
			{
				result += pe.weight;
			}

			cout << result << endl;
		}
		/* Enter your code here. Read input from STDIN. Print output to STDOUT */
		return 0;
	}

};