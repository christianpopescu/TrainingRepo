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


class GetSuccessor{
public:
   BinaryTree bt;
   

   
   node* successor(node* nd) {
	   if (nd->r != nullptr) {
		   if (nd->r->l == nullptr) return nd->r;
		   node* cr = nd->r->l;
		   while (cr->l != nullptr) cr = cr->l;
		   return cr;
	   } else  {
			node* cr = nd;		   
			while (cr->p != nullptr && cr->p->r == cr) cr = cr->p;
			return cr->p; // nullptr if root successor otherwise
	   }

   }
};

int main(){
	GetSuccessor gs;

	return 0;
}