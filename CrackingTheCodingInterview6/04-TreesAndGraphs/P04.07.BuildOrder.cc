#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>

// not realy tested
// !!!!!!!!!!!!!!!!!!!!!

using namespace std;

class GraphNode {
	public:
	GraphNode(char _key):key{key} {};
	vector<int> children;
	char key;
};

class Graph{
	public:
	enum struct visit {
		not_visited,
		visiting,
		visited
	};
	vector<GraphNode> nodes;
	vector<visit> visited_status;
	unordered_map<char,int>index;
	Graph& addNode(char c) {
		nodes.push_back(GraphNode(c));
		visited_status.push_back(visit::not_visited);
		index[c] = nodes.size()-1;
		return *this;
	}
	Graph& addEdge(char u, char v) {
		nodes[index[u]].children.push_back(index[v]);
		return *this;
	}

};




int main(){
	Graph gs;
	gs.addNode('a').addNode('b').addNode('c').addNode('d').addNode('e').addNode('f');
	gs.addEdge('a','b').addEdge('f','b').addEdge('b','d').addEdge('f','a').addEdge('d','c');

	return 0;
}