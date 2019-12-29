#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

int maxRow=10;
int maxCol=10;

class grid{
public:
	vector<vector<bool>> maze = vector<vector<bool>>(maxRow+1, vector<bool>(maxCol+1,true));
	int countall = 0;
	int count = 0;
	vector<vector<bool>> visited = vector<vector<bool>>(maxRow+1, vector<bool>(maxCol+1,false));
	
	// search solution from <1,1> to 
	bool solution(pair<int,int> dest, list<pair<int,int>>& path) {
		countall++;
		if (visited[dest.first][dest.second]) return false;
		count++;
		if (dest.first == 0 || dest.second == 0 || !(maze[dest.first][dest.second])) {
			visited[dest.first][dest.second] = true;
			return false;
		}
		path.push_front(dest);
		if (dest == make_pair(1,1)) return true;
		if (solution(make_pair(dest.first - 1, dest.second), path) ||
			solution(make_pair(dest.first, dest.second - 1), path)) {
				return true;
			} else {
				path.pop_front();
				visited[dest.first][dest.second] = true;
				return false;
			}
	}
	
	bool solution(list<pair<int,int>>& path) {
		if (solution(make_pair(maxRow, maxCol), path))
			return true;
		else
			return false;
			
		
	}
};

int main(){
	grid g;
	list<pair<int,int>> path;
	
	g.maze[2][10] = false;
	g.maze[2][9] = false;
	g.maze[2][8] = false;
	g.maze[3][8] = false;
	g.maze[4][8] = false;
	g.maze[4][7] = false;
	g.maze[4][6] = false;
	g.maze[4][5] = false;
	g.maze[4][4] = false;
	g.maze[4][3] = false;
	g.maze[4][2] = false;
	g.maze[5][2] = false;
	g.maze[6][2] = false;
	g.maze[7][2] = false;
	g.maze[8][2] = false;
    g.maze[9][2] = false;
	g.maze[9][3] = false;
    g.maze[9][4] = false;


	
	if (g.solution(path)) {
		for (auto pr : path) {
			cout << pr.first << " : " << pr.second << endl;
		}
	} else {
		cout << " there is no solution" << endl;
	}
	cout << g.count << " from : " << g.countall << endl;
		
	cout << "End of problem";
	return 0;
}