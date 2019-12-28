#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

class node {
	public:
	node() :
	parent{nullptr},
	left{nullptr},
	right{nullptr},
	value{0} {
	}
	
	node* parent;
	node* left;
	node* right; 
	int value;
};

class binary_tree{
private:
	int level = 0;
public:
	node* root;
    vector<list<node*>> llNodes;
	node* CreateMinimumHighTree(vector<int>& in, int begin, int end) {
		if (begin == end){
			node* tmp = new node();
			tmp->value = in[begin];
			return tmp;
		} else if (end - begin == 1) {
			node* tmp = new node();
			tmp->value = in[begin];
			node* tmp2 = new node();
			tmp2->value = in[end];
			tmp2->left = tmp;
			tmp->parent = tmp2;
			return tmp2;
		}
		int r = (end+begin)/2;
		node* root = new node();
		root->value = in[r];
		root->left = CreateMinimumHighTree(in, begin, r-1);
		root->right = CreateMinimumHighTree(in, r+1, end);
		root->left->parent = root;
		root->right->parent = root;
		return root;
	}
	void CreateMinimumHighTree(vector<int> input) {
		root = CreateMinimumHighTree(input,1, input.size()-1);
	}
	void print(string st, bool endl = false) {
		cout << st;
		if (endl) cout << "\n";
	} 
	
	void printNodeValue(node* nd) {
		if (nd == nullptr) 
			cout << "null";
		else 
			cout << nd->value;
	}
	
	void actionPrint(node* nd) {
		printNodeValue(nd);
		print("  Level : "); print (to_string(level));
		print("  Parent : ");	printNodeValue(nd->parent);
		print("  Left : "); printNodeValue(nd->left);
		print("  Right : "); printNodeValue(nd->right);
		print(" ;", true);
	}

	void actionLink(node* nd) {
		list<node*> l;
		while (llNodes.size() < level+1) llNodes.push_back(l);
		llNodes[level].push_back(nd);
	}


	void visit(node* nd) {
		if ( nd == nullptr) return;
		actionPrint(nd);
		actionLink(nd);
		level++;
		visit(nd->left);
		visit(nd->right);
		level--;
	}
	
	void visit() { 
		level = 0;
		visit(root);
	}
	
	void PrintLinkList() {
		for (auto l : llNodes) {
			for (auto it=l.begin(); it != l.end(); ++it)
				cout << (*it)->value << " : ";
			cout << endl;
		}
	}
};

int main() {
	vector<int> in;
	in.push_back(0);
	in.push_back(10);
	in.push_back(9);
	in.push_back(20);
	in.push_back(11);
	in.push_back(8);
	in.push_back(19);
	in.push_back(7);
	in.push_back(210);
	in.push_back(29);
	in.push_back(220);
	in.push_back(211);
	in.push_back(28);
	in.push_back(219);
	in.push_back(27);
	
	sort(in.begin(), in.end());
	binary_tree bt;
	bt.CreateMinimumHighTree(in);
	bt.visit();
	bt.PrintLinkList();
	return 0;
}
