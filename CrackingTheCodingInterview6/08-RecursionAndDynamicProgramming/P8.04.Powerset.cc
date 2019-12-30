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
	
	vector<int> getMagicIndex() {
		vector<int> result;
		getMagicIndex(0, array.size()-1);
		if (magic_index >-1) {
			result.push_back(magic_index);
			int current = magic_index-1;
			while (current > 0 && array[current] == current) {
				result.push_back(current);
				--current;
			}
			current = magic_index + 1;
			while (current < array.size() && array[current] == current) {
				result.push_back(current);
				++current;
			}
			sort(result.begin(), result.end());
		}
		return result;
		
	}
	
	bool getMagicIndex(int b, int e)
	{
		if (b > e) return false;
		if (b == e) {
			if (array[b] == b) {
				magic_index = b;
				return true;
			} else
				return false;
		} else {
			 int middle = (e + b)/2;
			 if (array[middle] == middle) {
				 magic_index = middle;
				 return true;
			 } else if (array[middle] < middle)
				 return getMagicIndex(middle + 1, e);
			 else
				 return getMagicIndex(b, middle - 1);
		}
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