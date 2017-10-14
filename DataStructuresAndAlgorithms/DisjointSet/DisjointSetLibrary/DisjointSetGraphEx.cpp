#include "DisjointSetGraphEx.h"
#include <map>


DisjointSetGraphEx::DisjointSetGraphEx()
{
	numberOfDisjointSet = 0;
}

DisjointSetGraphEx::DisjointSetGraphEx(int nbOfNodes)
{
	nodes.resize(nbOfNodes);
	numberOfDisjointSet = nbOfNodes;
	MakeAllNodes();
}
/*
DisjointSetGraphEx::DisjointSetGraphEx(DisjointSetGraphEx& dsg)
{
	
	std::map<nodeSet*, int> reverseIndex;
	
	nodes.resize(dsg.nodes.size());
	// fill nodes
	// fill revese index + copy values fields
	for (int i = 0; i < dsg.nodes.size(); i++)
	{
		//reverseIndex[dsg.nodes[i]] = i;
		reverseIndex.insert(std::make_pair(dsg.nodes[i], i));
		nodes[i] = new nodeSet();
		// copy values
		nodes[i]->nbOfNodesSet = dsg.nodes[i]->nbOfNodesSet;
		nodes[i]->rank = dsg.nodes[i]->rank;
	}

	for (int i = 0; i < dsg.nodes.size(); i++)
	{
		nodes[i]->parent = nodes[reverseIndex[dsg.nodes[i]->parent]];
	}; 

	// fill edges;
	edges.resize(dsg.edges.size());

	for (int i = 0; i < dsg.edges.size(); i++)
	{
		edges[i].firstNode = nodes[reverseIndex[dsg.edges[i].firstNode]];
		edges[i].secondNode = nodes[reverseIndex[dsg.edges[i].secondNode]];
	}

	// number of disjoint set
	numberOfDisjointSet = dsg.numberOfDisjointSet;

}

*/
DisjointSetGraphEx::~DisjointSetGraphEx()
{
	
}

// Creates a disjoint set for each node
void DisjointSetGraphEx::MakeAllNodes()
{
	for (int i = 0; i < nodes.size(); i++) {
		nodes[i].currentIndex = i;
		nodes[i].parentIndex = i;
		nodes[i].rank = 0;
		nodes[i].nbOfNodesSet = 1;
	}
	numberOfDisjointSet = nodes.size();
}

void DisjointSetGraphEx::AddEdge(CollectionPointer i, CollectionPointer j)
{
	edge e;
	e.firstNodeIndex = i;
	e.secondNodeIndex = j;
	edges.push_back(e);
}

bool DisjointSetGraphEx::AddEdgeRecompute(CollectionPointer i, CollectionPointer j)
{ 
	bool result = false;
	AddEdge(i, j);
	CollectionPointer elem1 = FindSet(i);
	CollectionPointer elem2 = FindSet(j);
	if (elem1 != elem2) {
		Union(elem1, elem2);
		result = true;
	}
	return result;
}

CollectionPointer DisjointSetGraphEx::FindSet(CollectionPointer elem)
{
	if (nodes[elem].parentIndex != elem) 	elem = FindSet(nodes[elem].parentIndex);
	return nodes[elem].parentIndex;
}

void DisjointSetGraphEx::Union(CollectionPointer xNode, CollectionPointer yNode)
{
	if (nodes[xNode].rank > nodes[yNode].rank) {
		nodes[yNode].parentIndex = xNode;
		nodes[xNode].nbOfNodesSet = nodes[xNode].nbOfNodesSet + nodes[yNode].nbOfNodesSet ;
	}
	else {
		nodes[xNode].parentIndex = yNode;
		nodes[yNode].nbOfNodesSet = nodes[yNode].nbOfNodesSet + nodes[xNode].nbOfNodesSet ;
		if (nodes[xNode].rank == nodes[yNode].rank) nodes[yNode].rank++;
	}
	numberOfDisjointSet--;
}

int DisjointSetGraphEx::GetNumberOfDisjointSet() const
{
	return numberOfDisjointSet;
}
