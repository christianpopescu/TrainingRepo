#include <iostream>
#include <string>

const int NO_PARENT = -1;
// depth first search


std::vector<int> GetPathDfs (std::vector<std::vector<int>>& graph,int src, int dest) {
	vector<int> result;
	int _n = graph.size();
	vector<bool> visited (n+1, false);
	vector<int> precedent (n+1, NO_PARENT);
}


int main () {

	int n{0};
	int e{0};

	std::cin >> n;  // number of nodes
	std::cin >> e;  // number of edges

	std::vector<std::vector<int>> adjList(n + 1);
    int src, dest;
	for (int i = 0; i< e; ++i) {
		std::cin >> src >> dest >> endl;
		adjList[src].push_back(dest);
	}
}

 

