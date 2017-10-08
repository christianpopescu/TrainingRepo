#include "DisjointSetGraph.h"
#include <map>


DisjointSetGraph::DisjointSetGraph()
{
	numberOfDisjointSet = 0;
}

DisjointSetGraph::DisjointSetGraph(int nbOfNodes)
{
	nodes.resize(nbOfNodes);
	numberOfDisjointSet = nbOfNodes;
	MakeAllNodes();
}

DisjointSetGraph::DisjointSetGraph(DisjointSetGraph& dsg)
{
	
	std::map<nodeSet*, int> reverseIndex;
	
	// fill nodes
	// fill revese index + copy values fields
	for (int i = 0; i < dsg.nodes.size(); i++)
	{
		reverseIndex[dsg.nodes[i]] = i;
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


DisjointSetGraph::~DisjointSetGraph()
{
	// clean allocated nodes
	for (nodeSet* n : nodes) delete n;
}



// Creates a disjoint set for each node
void DisjointSetGraph::MakeAllNodes()
{
	for (int i = 0; i < nodes.size(); i++) {
		nodes[i] = new nodeSet();
		nodes[i]->parent = nodes[i];
		nodes[i]->rank = 0;
		nodes[i]->nbOfNodesSet = 1;
	}
	numberOfDisjointSet = nodes.size();
}

void DisjointSetGraph::AddEdge(int i, int j)
{
	edge e;
	e.firstNode = nodes[i];
	e.secondNode = nodes[j];
	edges.push_back(e);
}

bool DisjointSetGraph::AddEdgeRecompute(int i, int j)
{ 
	bool result = false;
	AddEdge(i, j);
	nodeSet* elem1 = FindSet(nodes[i]);
	nodeSet* elem2 = FindSet(nodes[j]);
	if (elem1 != elem2) {
		Union(elem1, elem2);
		result = true;
	}
	return result;
}

DisjointSetGraph::nodeSet* DisjointSetGraph::FindSet(nodeSet * elem)
{
	if (elem->parent != elem) 	elem = FindSet(elem->parent);
	return elem->parent;
}

void DisjointSetGraph::Union(nodeSet* x, nodeSet* y)
{
	if (x->rank > y->rank) {
		y->parent = x;
		x->nbOfNodesSet = x->nbOfNodesSet + y->nbOfNodesSet ;
	}
	else {
		x->parent = y;
		y->nbOfNodesSet = y->nbOfNodesSet + x->nbOfNodesSet ;
		if (x->rank == y->rank) y->rank++;
	}
	numberOfDisjointSet--;
}

int DisjointSetGraph::GetNumberOfDisjointSet()
{
	return numberOfDisjointSet;
}
