#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

vector<stack<int>> tower(4);

class Parens{
public:
    vector<char> permutation;
	vector<bool> choosen;
	string input;
	vector<char> buff;
	int n;
	int count;
	char set[2] = {'(',')'};
	int available_left;
	int available_right;
	int open = 0;
	
	void SetInput(int pn) {
	    n = 2*pn;
		permutation.clear();
		available_left = pn;
		available_right = pn;
		buff.push_back(' ');
		for (char c : input) buff.push_back(c);
		count = 1;
		open = 0 ;
	}
	void Generate() {
	   if (permutation.size() == n) {
		   ProcessPermutation();
	   } else {
		   vector<bool> duplicate (127,false);
		   if (available_left > 0) {
			   available_left--;
			   permutation.push_back('(');
			   open ++;
			   Generate();
			   open --;
			   permutation.pop_back();
			   available_left++;
		   }
		   if (available_right > 0 && open > 0) {
			   available_right--;
			   permutation.push_back(')');
			   open--;
			   Generate();
			   open++;
			   permutation.pop_back();
			   available_right++;
		   }
	   }
		   

	}
	
	void ProcessPermutation() {

		for (auto c : permutation) cout << c;
		cout << "   " <<count++ << endl;
	}
	
	
};

int main(){
	Parens pwd;
//	pwd.SetInput("abccba");
	pwd.SetInput(3);
	pwd.Generate(); 
	return 0;
}