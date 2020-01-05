#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

vector<stack<int>> tower(4);

class Coins{
public:
    vector<char> permutation;
	vector<bool> choosen;
	string input;
	vector<char> buff;
	int n;
	char set[2] = {'(',')'};
	int available_left;
	int available_right;
	int open = 0;
	
	int sum = 0;
	int count;
	int coin[4] {1, 5, 10, 25};

	
	void SetInput(int pn) {
	    n = pn;
		sum = 0;
		available_left = pn;
		available_right = pn;
		buff.push_back(' ');
		for (char c : input) buff.push_back(c);
		count = 1;
		open = 0 ;
	}
	
	void Generate() {
	   if (sum == n) {
		   ProcessPermutation();
	   } else {
		   for (int i=0; i<4; i++)
		   {
			   if (sum + coin[i] <= sum) {
				   sum += coin[i];
				   Generate();
				   sum -= coin[i];
			   }
		   }
	   }
	}
	
	void ProcessPermutation() {
		count++;
	}
};

int main(){
	Coins cns;
//	pwd.SetInput("abccba");
	cns.SetInput(3);
	cns.Generate(); 
	cout << cns.count << endl;
	return 0;
}