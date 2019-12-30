#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int maxRow=10;
int maxCol=10;

class Powerset{
public:
	vector<int> array;
	int countall = 0;
	int count = 0;
	int magic_index = -1;
	
	// Combinatorics version
	// generates all the numbers from 1 to 2^n. For each number use the bit as index of set.
	vector<vector<int>> all generateAllSubsets(vector<int> set) {
	   int max = 1 << set.size();    // Computes 2^name
	   
	   
	}
};

int main(){
    MagicIndex mi;
	mi.array.push_back(-10);
	mi.array.push_back(-5);
	mi.array.push_back(-3);
	mi.array.push_back(0);
	mi.array.push_back(4);
	mi.array.push_back(5);
	mi.array.push_back(6);
	mi.array.push_back(8);
	for (int i : mi.getMagicIndex())
		cout << i << endl;
	cout << "End of problem";
	
	return 0;
}