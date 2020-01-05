#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


class GroupAnagrams{
public:
    int a[2048];
	int b[256];
	vector<string> listOfStrings;
	vector<pair<string,string>> lstToSort;
	
	GroupAnagrams& AddString(string st) {
		listOfStrings.push_back(st);
		return *this;
	} 
	void sortByAnagram() {
		lstToSort.clear();
		string buff = "";
		for (auto s : listOfStrings) {
			buff = s;
			sort(buff.begin(), buff.end());
			lstToSort.push_back(make_pair(buff, s));
		}
		sort(lstToSort.begin(), lstToSort.end());
	}
	
	void PrintSorted(){
		for(auto ps : lstToSort) {
			cout << ps.first << "   " << ps.second << endl;
		}
	}
};

int main(){
	GroupAnagrams ga;
	ga.AddString("aba").AddString("baa").AddString("ccb").AddString("acb")
	.AddString("aab").AddString("cbc").AddString("bac");
	ga.sortByAnagram();
	ga.PrintSorted();
	return 0;
}