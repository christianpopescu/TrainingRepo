#pragma once
#include <vector>

class __declspec(dllexport) DisjointSetGraph
{
public:
	DisjointSetGraph();
	DisjointSetGraph(int nbOfNodes);
	DisjointSetGraph(DisjointSetGraph& dsg);
	~DisjointSetGraph();
	
	struct nodeSet {
	public:
		nodeSet* parent;
		int rank;
		int nbOfNodesSet;
	};

	struct edge
	{
	public:
		nodeSet* firstNode;
		nodeSet* secondNode;
	};
	void MakeAllNodes();

	void AddEdge(int i, int j);
	bool AddEdgeRecompute(int i, int j); // Add edge and recomputs unions - returns true if union false otherwise
	
	nodeSet* FindSet(nodeSet* elem);  // FindSet with rank and path compression

	void Union(nodeSet* xNode, nodeSet* yNode);    // Union two disjoint sets

	int GetNumberOfDisjointSet();
protected:
	std::vector<nodeSet*> nodes;
	std::vector<edge> edges;
	int numberOfDisjointSet;
};

