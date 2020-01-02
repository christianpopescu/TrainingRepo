#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int maxRow=10;
int maxCol=10;

class RecursiveMultiply{
public:
    int Mult(int a,int b) {
		if (b == 1) {
			return a;
		} else {
			int res = Mult(a, (b >> 1));
		
			return res + res + ((b&1 == 1) ? a : 0);
		}
	}
    int Multiply (int a, int b) {
		if (b > a) swap(a,b);

		return Mult(a,b);
	}
};

int main(){
	RecursiveMultiply rm;
	cout << rm.Multiply(10,15) << endl ;
	cout << rm.Multiply(25,25) << endl ;
	cout << rm.Multiply(13,13) << endl ;
	cout << "End of problem";
	
	return 0;
}