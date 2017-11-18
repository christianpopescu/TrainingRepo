#pragma once
#include  "MinHeapAux.cpp"
#include <list>
#include <climits>

class Dijkstra
{
private:
	int size;
public:
	Dijkstra();
	Dijkstra(int n);
	~Dijkstra();

	struct edgeFromVertex
	{
		int destination;
		int weight;
	};

	struct Vertex
	{
		int id;
		int precedent;
		int distanceFromSource;
		int distanceFromPrecedent;
		std::vector<edgeFromVertex> adjList;
	};

	struct PathElement
	{
		int source;
		int destination;
		int weight;
	};


	struct CompareDistances
	{
		bool operator()(const Vertex& v1, const Vertex& v2);
	};

	Vertex* vertexList;

	void InitSingleSource(int s);

	void AddEdge(int source, int destination, int distance);

	void InitPriorityQueue();

	// Run the Dijkstra algorithm for the source <source>
	void ComputeSingleSourceAlgorithm(int source);

	std::list<PathElement> GetPath(int source, int dest);

private:
	CompareDistances lessDistance;
	MinHeapAux<Dijkstra::Vertex, CompareDistances>* pq;
};

inline bool operator==(const Dijkstra::PathElement& pe1, const Dijkstra::PathElement& pe2);
inline bool operator!=(const Dijkstra::PathElement& pe1, const Dijkstra::PathElement& pe2);

Dijkstra::Dijkstra()
{
}

Dijkstra::Dijkstra(int n)
{
	this->size = n+1;
	vertexList = new Vertex[n+1];
	for (int i = 1; i <= n; i++)
		vertexList[i].id = i;
}

Dijkstra::~Dijkstra()
{
	
}

void Dijkstra::InitSingleSource(int s)
{
	for (int i = 1; i <= size; i++)
	{
		vertexList[i].precedent = 0;
		vertexList[i].distanceFromSource = INT_MAX;
		vertexList[i].distanceFromPrecedent = INT_MAX;
		if (i == s)
		{
			vertexList[i].distanceFromSource = INT_MAX;
			vertexList[i].distanceFromPrecedent = INT_MAX;
		}
	}
	  
}

void Dijkstra::AddEdge(int source, int destination, int distance)
{
	edgeFromVertex efv;
	efv.destination = destination;
	efv.weight = distance;
	vertexList[source].adjList.push_back(efv);
}

void Dijkstra::InitPriorityQueue()
{
	pq = new MinHeapAux<Vertex, CompareDistances>(vertexList, size, lessDistance);
}

void Dijkstra::ComputeSingleSourceAlgorithm(int source)
{
	InitSingleSource(source);
	InitPriorityQueue();
	while (pq->size()>0)
	{
		int currentVertex = pq->Top();
		pq->RemoveTop();
		for(int i=0; i<vertexList[currentVertex].adjList.size(); i++)
		{
			
			int dst = vertexList[currentVertex].adjList[i].destination;
			//std::cout << currentVertex << " destination " << std::endl;
			if (vertexList[dst].distanceFromSource >
				vertexList[currentVertex].distanceFromSource + vertexList[currentVertex].adjList[i].weight)
			{
				vertexList[dst].distanceFromSource = 
					vertexList[currentVertex].distanceFromSource + vertexList[currentVertex].adjList[i].weight;
				vertexList[dst].precedent = currentVertex;
				vertexList[dst].distanceFromPrecedent = 
					vertexList[currentVertex].adjList[i].weight;
				pq->DecreseKey(dst);
			}
		}
	}
}

std::list<Dijkstra::PathElement> Dijkstra::GetPath(int source, int dest)
{
	std::list<Dijkstra::PathElement> result;
	if (source == dest) return result;
	int current = dest;
	while (current != source)
	{
		PathElement pe;
		pe.destination = current;
		pe.source = vertexList[current].precedent;
		pe.weight = vertexList[current].distanceFromPrecedent;
		result.push_front(pe);
		current = vertexList[current].precedent;
	}
	return result;
}

bool Dijkstra::CompareDistances::operator()(const Vertex& v1, const Vertex& v2)
{
	return v1.distanceFromSource < v2.distanceFromSource;
}

bool operator==(const Dijkstra::PathElement& pe1, const Dijkstra::PathElement& pe2)
{
	return ((pe1.source == pe2.source) && (pe1.destination == pe2.destination) && (pe1.weight == pe2.weight));
}

bool operator!=(const Dijkstra::PathElement& pe1, const Dijkstra::PathElement& pe2)
{
	return (!(pe1 == pe2));
}


