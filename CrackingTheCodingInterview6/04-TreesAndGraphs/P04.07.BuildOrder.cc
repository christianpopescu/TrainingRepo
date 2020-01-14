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
	GraphNode(char _key):key{_key} {};
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
	deque<int> sorted_list;
	
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
	
	bool dfs(int node, deque<int>& sorted_list) {
		visited_status[node] = visit::visiting;
		for (auto n : nodes[node].children) {
			if (visited_status[n] == visit::visiting) return false;
			if (visited_status[n] == visit::visited) continue;
			bool b = dfs(n, sorted_list);
			if (!b) return false;				
		}
		visited_status[node] = visit::visited;
		sorted_list.push_front(node);
		return true;
	}
	
	bool TopologicalSort() {
		bool b = true;
		for (int i = 0; i < nodes.size(); ++i ) {
			if (visited_status[i] == visit::not_visited) {
				b = dfs(i, sorted_list);
				if (!b) return false;
			}
		}
		return true;
	}

};




int main(){
	Graph gs;
	gs.addNode('a').addNode('b').addNode('c').addNode('d').addNode('e').addNode('f');
	gs.addEdge('a','b').addEdge('f','b').addEdge('b','d').addEdge('f','a').addEdge('d','c');
    if (gs.TopologicalSort()) {
		for (auto n : gs.sorted_list){
			cout << gs.nodes[n].key << ' ';
		}
		cout << endl;
	} else {
		cout << "not possible to Topological Sort the given graph" << endl;
	}
	return 0;
}