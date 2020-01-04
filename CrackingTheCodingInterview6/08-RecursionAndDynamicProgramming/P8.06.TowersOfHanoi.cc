#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

vector<stack<int>> tower(4);

class TowersOfHanoi{
public:
    int n;
	TowersOfHanoi(int n)
	:n{n}{
		for (int i = n; i>0; --i) {
			tower[1].push(i);
		}
	}
	
	void Move(int n, int i, int j) {
		if ( n == 1) {
			int disk = tower[i].top();
			tower[j].push(disk );
			tower[i].pop();
			cout << "move disk " << disk << " from tower " << i << " to tower " << j << endl;
		} else {
			int otherTower = 6 - i -j;
			Move (n-1, i, otherTower);
			Move(1, i, j);
			Move(n-1,otherTower,j );
		}
	}
	
	void Move() {
		Move(n,1, 2);
	}
	
	void PrintStack(int i) {
		while (!(tower[i].empty())) {
			cout << tower[i].top() << " ";
			tower[i].pop();
		}
		cout << "good" <<endl;
	}
	
};

int main(){
	TowersOfHanoi toh(7);
//	toh.PrintStack(1);
	toh.Move();
	return 0;
}