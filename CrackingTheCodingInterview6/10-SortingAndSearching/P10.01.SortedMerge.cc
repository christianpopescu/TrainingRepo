#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


class SortedMerge{
public:
    int a[2048];
	int b[256];
	void PrintA(){
		int* p = a;
		while (*p != 0){
			cout << (*p++) << " ";
		}
		cout << endl;
	}
	
	int* end(int * ar) {
		int* p = ar;
		while (*p != 0){
			p++;
		}
		return p;
	}
	
	void SortA(){
		sort(a,end(a));
	}
	
	void SortB(){
		sort(b,end(b));
	}
	
	void MergeABInPlace(){
		int* endA = end(a);
		int* endB = end(b);
		int* endMerged = a + (endA-a) + (endB - b);
		(*endMerged) = 0;
		int* cM = endMerged-1;
		int* cA = endA -1;
		int* cB = endB - 1;
		while (cB >=b) {
			if ((*cA) < (*cB)) {
				(*cM) = (*cB);
				cB--;
			} else {
				(*cM) = (*cA);
				cA--;
			}
			cM--;
		}
	}
	
};

int main(){
	SortedMerge sm;
	sm.a[0] = 18;
	sm.a[1] = 15;
	sm.a[2] = 1;
	sm.a[3] = 24;
	sm.a[4] = 2;
	sm.a[5] = 19;
	sm.a[6] = 0;

	sm.b[0] = 19;
	sm.b[1] = 17;
	sm.b[2] = 2;
	sm.b[3] = 27;
	sm.b[4] = 0;

	sm.SortA();
	sm.SortB();
	sm.PrintA();
	sm.MergeABInPlace();
	sm.PrintA();
	return 0;
}