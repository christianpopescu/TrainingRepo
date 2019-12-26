#include <iostream>

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
	node* righ; 
	int value;
};

class binary_tree{
public:
	node* root;
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
			return tmp2;
		}
		int r = (end+begin)/2;
		node* root new node();
		root->value = in[r];
		root->left = CreateMinimumHighTree(in, begin, r-1);
		root->right = CreateMinimumHighTree(in, r+1, end);
		root->left->parent = root;
		root->right->parent = root;
		return root;
	}
	void CreateMinimumHightTree(vector<int> input) {
		
	}
	
};

int main() {
	return 0;
}
