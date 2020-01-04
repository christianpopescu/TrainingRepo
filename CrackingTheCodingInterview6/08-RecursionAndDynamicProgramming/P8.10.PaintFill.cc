#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int n=6;
vector<vector<int>> screen(n,vector(n,1));

class PaintFill{
public:
    PaintFill() {
		
	}
	int originalColor;
	queue<pair<int,int>> q;
	void fill(int r, int c, int color) {
		originalColor = screen[r][c];
		//fillDfs(r, c, color);
		fillBfs(r, c, color);
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
	void fillBfs(int r, int c, int color) {
		q.push(make_pair(r,c));
		pair<int,int> current;
		int x = 0;
		while (!q.empty()) {
			current = q.front();
			q.pop();
			int _r = current.first;
			int _c = current.second;
			
			screen[_r][_c] = color;
			if (_r > 0 && screen[_r-1][_c] == originalColor && screen[_r-1][_c] != color)  q.push(make_pair(_r-1,_c));
			if (_c > 0 && screen[_r][_c-1] == originalColor && screen[_r][_c-1] != color)  q.push(make_pair(_r,_c-1)); 
			if (_r < n-1 && screen[_r+1][_c] == originalColor && screen[_r+1][_c] != color)  q.push(make_pair(_r+1,_c)); 
			if (_c < n-1 && screen[_r][_c+1] == originalColor && screen[_r][_c+1] != color)  q.push(make_pair(_r,_c+1)); 
		}
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
	pf.PrnScr();
	cout << endl;
	pf.fill(0,1,0);
	pf.PrnScr();
	return 0;
}