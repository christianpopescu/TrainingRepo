#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

int n=6;
vector<vector<int>> screen(n,vector(n,1));

class PaintFill{
public:
    PaintFill() {
		
	}
	int originalColor;
	
	void fill(int r, int c, int color) {
		originalColor = screen[r][c];
		fillDfs(r, c, color);
	}
	
	void fillDfs(int r, int c, int color) {
		if (r<0 || r>=n || c<0 || c >=n) return;
		if (screen[r][c] == color || screen[r][c] != originalColor) return;
		screen[r][c] = color;
		fillDfs(r+1, c, color);
		fillDfs(r, c-1, color);
		fillDfs(r-1, c, color);
		fillDfs(r, c+1, color);
	}
	
	void PrnScr(){
		for (auto r : screen){
			for(auto c : r) 
				cout << c << ' ';
			cout << endl;
		}
		
			
	}
};

int main(){
	PaintFill pf;
	pf.PrnScr();
	cout << endl;
	screen[1][1] = 3;
	screen[1][2] = 3;
	screen[2][3] = 3;
	screen[3][4] = 4;
	screen[4][5] = 5;
	screen[2][0] = 5;
	pf.fill(4,1,0);
	pf.PrnScr();
	return 0;
}