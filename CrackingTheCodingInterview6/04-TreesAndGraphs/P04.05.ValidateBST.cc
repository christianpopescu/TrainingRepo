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

class node {
	public:
	node() :
	p{nullptr},
	l{nullptr},
	r{nullptr},
	k{0} {
	}
	
	node* p;
	node* l;
	node* r; 
	int k;
};

class BinaryTree{
	public:
	node* root;
	BinaryTree() : root{nullptr}
		{}
};


class ValidBst{
public:
   BinaryTree bt;
   
   bool validate() {
	   return (bt.root, INT_MIN, INT_MAX);
   }
   
   bool validate(node* nd, int min, int max) {
	   if (nd == nullptr) return true;
	   if (nd->k <= min || nd->k >= max) return false;
	   return validate(nd->l, min, nd->k) && validate(nd->r, nd->k, max);
   }
};

int main(){
	ValidBst vb;
	cout << vb.validate();
	return 0;
}