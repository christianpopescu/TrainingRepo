#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

vector<stack<int>> tower(4);

class PermutationWithDups{
public:
    vector<char> permutation;
	vector<bool> choosen;
	string input;
	vector<char> buff;
	int n;
	int count;
	
	void SetInput(string in) {
		input = in;
		permutation.clear();
		n = input.size();
		choosen.clear();
		choosen.resize(input.size()+1, false);
		buff.push_back(' ');
		for (char c : input) buff.push_back(c);
		count = 1;
	}
	void Generate() {
	   if (permutation.size() == n) {
		   ProcessPermutation();
	   } else {
		   vector<bool> duplicate (127,false);
		   for (int i = 1; i<=n; ++i) {
			   if (choosen[i]) continue;
			   if (duplicate[(char)buff[i]]) continue;
			   duplicate[(char)buff[i]] = true;
			   permutation.push_back(buff[i]);
			   choosen[i] = true;
			   Generate();
			   choosen[i] = false;
			   permutation.pop_back();
		   }
	   }
		   

	}
	
	void ProcessPermutation() {

		for (auto c : permutation) cout << c;
		cout << "   " <<count++ << endl;
	}
	
	
};

int main(){
	PermutationWithDups pwd;
//	pwd.SetInput("abccba");
	pwd.SetInput("aaaaaa");
	pwd.Generate(); 
	return 0;
}