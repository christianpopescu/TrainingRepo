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
		count = 0;
//		cout << coin[0] << coin[1]<< coin[2]<< coin[3]<< endl;
		
	}
	
	void Generate(int start) {
//	   cout << sum << endl;
	   if (sum == n) {
		   ProcessPermutation();
	   } else {
		   for (int i=start; i<4; i++)
		   {
			   if (sum + coin[i] <= n) {
				   sum += coin[i];
				   Generate(i);
				   sum -= coin[i];
			   }
		   }
	   }
	}
	
	void ProcessPermutation() {
		count++;
//		cout << count << endl;
	}
};

int main(){
	Coins cns;
//	pwd.SetInput("abccba");
	cns.SetInput(6);
	cns.Generate(0); 
	cout << cns.count << endl;
	return 0;
}