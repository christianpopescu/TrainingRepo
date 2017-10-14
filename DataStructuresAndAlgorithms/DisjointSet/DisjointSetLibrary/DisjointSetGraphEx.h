#pragma once
#include <vector>

/*
 * Disjoint Set Graph without pointer
 * 12/10/2017
 * This allows to easily copy the object
 */

typedef int CollectionPointer;
class __declspec(dllexport) DisjointSetGraphEx
{
public:
	DisjointSetGraphEx();
	DisjointSetGraphEx(int nbOfNodes);
	//DisjointSetGraphEx(DisjointSetGraphEx& dsg);
	~DisjointSetGraphEx();
	
	struct nodeSet {
	public:
		CollectionPointer currentIndex;			// current index in the collection that keeps all nodes
		CollectionPointer parentIndex;			// parent index in the collection that keeps all nodes
		int rank;
		int nbOfNodesSet;
	};

	struct edge
	{
	public:
		CollectionPointer firstNodeIndex;
		CollectionPointer secondNodeIndex;
	};
	void MakeAllNodes();

	void AddEdge(CollectionPointer i, CollectionPointer j);
	bool AddEdgeRecompute(CollectionPointer i, CollectionPointer j); // Add edge and recomputs unions - returns true if union false otherwise
	
	CollectionPointer FindSet(CollectionPointer elem);  // FindSet with rank and path compression

	void Union(CollectionPointer xNode, CollectionPointer yNode);    // Union two disjoint sets

	int GetNumberOfDisjointSet() const;
protected:
	std::vector<nodeSet> nodes;
	std::vector<edge> edges;
	int numberOfDisjointSet;
};

