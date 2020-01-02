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
	
	
	vector<int> ConvertIntToSet(int k, vector<int>& set) {
		vector<int> subset;
		int index = 0;
		for (int i = k; i>0; i>>=1) {
			if (i & 1 == 1) {
				subset.push_back(set[index]);
			}
			index++;
		}
		return subset;
	}
	
	// Combinatorics version
	// generates all the numbers from 1 to 2^n. For each number use the bit as index of set.
	vector<vector<int>> generateAllSubsets(vector<int>& set) {
	   int max = 1 << set.size();    // Computes 2^name
	   vector<vector<int>> result;
	   for (int i = 0; i < max; ++i) {
		   result.push_back(ConvertIntToSet(i, set));
	   }
	   return result;
	}
	
	void subset(int k, vector<int>& set, vector<vector<int>>& allsubsets, vector<int> input) {
		if (k == input.size()) allsubsets.push_back(set);
		else {
			subset(k+1, set, allsubsets, input);
			set.push_back(input[k]);
			subset(k+1, set, allsubsets, input);
			set.pop_back();
		}
	}
	
	// Recursive version
	vector<vector<int>> generateAllSubsetsRecursive(vector<int>& set) {
		vector<int> buf;
		vector<vector<int>> allsubsets;
		subset(0, buf, allsubsets, set);
		return allsubsets;
	}
		
	
	
	void PrintAllSubsets(vector<vector<int>>& subsets) {
		cout << "Number of subsets " << subsets.size() << endl;
		for (auto ss : subsets) {
			for (auto s : ss) {
				cout << s << " " ;
			}
			cout << endl;
		}
	}
};

int main(){
	Powerset ps;
	vector<int> set = {7, 8, 9, 30, 35};
	auto subsets = ps.generateAllSubsets(set);
	sort(subsets.begin(), subsets.end());
	ps.PrintAllSubsets(subsets);
	cout << "-----------------------------------------\n";
	subsets = ps.generateAllSubsetsRecursive(set);
	sort(subsets.begin(), subsets.end());
	ps.PrintAllSubsets(subsets);
	cout << "End of problem";
	
	return 0;
}