#include <iostream>
#include <string>
#include <vector>
#include <queue>

const int NO_PARENT = -1;
const int ROOT = 0;
// depth first search
class Graph {
public:
    Graph(std::vector<std::vector<int>> graph) :
	_n(graph.size()),
	visited(_n+1, false),
	precedent(_n+1, NO_PARENT),
	g{graph}{
		
	}
	
	void Visit(int node,int parent) {
		visited[node] = true;
		precedent[node] = parent;
		if (node == _dest) { 
			found = true;
			return;
		}
		for (int i=0; i<g[node].size(); ++i){
			if (!visited[g[node][i]]) Visit(g[node][i], node);
			if (found) return;
		}
	}

	std::vector<int> GetPathDfs (int src, int dest) {
		found = false;
		_src = src;
		_dest = dest;
		Visit(_src, ROOT);

		std::vector<int> result;
		if (found) {
			int current = _dest;
			while (precedent[current] != ROOT) {
				result.push_back(current);
				current = precedent[current];
			}
			result.push_back(current);
		}
		return result;
	}
	std::vector<int> GetPathBfs (int src, int dest) {
		found = false;
		_src = src;
		_dest = dest;
		std::queue<int> q;
		precedent[_src] = ROOT;
		q.push(_src);
		int current;
        while (!q.empty() && !found) {
			current = q.front(); q.pop();
			visited[current] = true;
			if (current == _dest) {
				found = true;
			} else {
				for (auto nd : g[current]) {
					if (!visited[nd]) {
						precedent[nd] = current;
						q.push(nd);
					}
				}
			}
				
		}
		std::vector<int> result;
		if (found) {
			int current = _dest;
			while (precedent[current] != ROOT) {
				result.push_back(current);
				current = precedent[current];
			}
			result.push_back(current);
		}
		return result;
	}
private :
	std::vector<std::vector<int>> g;
	int _n ; 
	std::vector<bool> visited;
	std::vector<int> precedent;
	bool found = false;
	int _src;
	int _dest;
};

int main () {

	int n{0};
	int e{0};

	std::cin >> n;  // number of nodes
	std::cin >> e;  // number of edges

	std::vector<std::vector<int>> adjList(n + 1);
    int src, dest;
	for (int i = 0; i< e; ++i) {
		std::cout << "Edge " << i+1 << " / " << e << " : ";
		std::cin >> src >> dest;
		adjList[src].push_back(dest);
	}
	
	std::cout << "Source and destination" << std::endl;
	std::cin >> src >> dest;
	Graph gg(adjList);
	std::vector<int> r = gg.GetPathDfs(src, dest);
    std::cout << "Path from source to destination DFS" << std::endl;
	for (std::vector<int>::reverse_iterator it = r.rbegin(); it < r.rend(); it++)
		std::cout << (*it) << std::endl;
	
	r = gg.GetPathBfs(src, dest);
    std::cout << "Path from source to destination BFS" << std::endl;
	for (std::vector<int>::reverse_iterator it = r.rbegin(); it < r.rend(); it++)
		std::cout << (*it) << std::endl;

	
}

 

