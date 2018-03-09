#include <bits/stdc++.h>

using namespace std;
class GraphForBFS{

  const int NIL= INT_MAX;
  
public:
  GraphForBFS(){
    size = 0;
  }
  enum color {white, gray, black};
  int size;
  struct Node{
    vector<int> adjList;
    int precedent;
    int distance;
    color clr;
  };

  queue<int> q;
  vector<Node> v;
  
  void InitGraph(int n)
  {
    for (int i=0; i<n; i++){
      Node n;
      n.precedent = -1;
      n.distance = INT_MIN;
      n.clr = color::white;
      v.push_back(n);
    }
  }

  void AddEdge(int begin, int end){
    v[begin].adjList.push_back(end);
  }

  void BFS(int start){
    v[start].precedent = NIL;
    v[start].distance = 0;
    v[start].clr = color::gray;
    q.push(start);
    while (!q.empty()){
      int current = q.front();
      q.pop();
      for ( auto n: v[current].adjList){
	if (v[n].clr == color::white)
	  {
	    v[n].clr = color::gray;
	    v[n].precedent = current;
	    v[n].distance = v[current].distance + 1;
	    q.push(n);
	  }
      }
      v[current].clr = color::black;
    }
  }
};


class VectorToGridConverter{
    int rows;
    int columns;
    public:
    VectorToGridConverter(int pRows, int pColumns){
        rows = pRows;
        columns = pColumns;
    }
    
    int GridToVector(int x, int y) {
        return (x*columns + y);
    }
    pair<int, int> VectorToGrid(int i){
        return make_pair(i/columns, i%columns);
    }
};

bool** getAllowedGrid(vector<string>& grid){
    bool** result;
    int rows = grid.size();
    int columns = grid[0].size();
    result = new bool*[rows];
    for (int i=0; i<rows; i++){
        result[i] = new bool[columns];
    }
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++)
            result[i][j] = (grid[i][j] == 'X') ? false : true;
    }
    return result;
} 

int minimumMoves(vector <string> grid, int startX, int startY, int goalX, int goalY) {
    // Complete this function
    int rows = grid.size();
    int columns = grid[0].size();
    // ---- useful classes      -------------------------------
    bool ** ag = getAllowedGrid(grid);
    VectorToGridConverter vtgc(rows, columns);
    // --- init graph structure -------------------------------
    GraphForBFS gfb;
        gfb.InitGraph (rows*columns);
    //cout << "in" << endl;
    for (int i=0; i < rows; i++)
        for (int j=0; j<columns; j++){
            if (!ag[i][j]) continue;   // ------------- >>>>>>> continue loop
            
            // while on grid and not blocked run in the 4 direction left, right, up, down
            // search on left
            for (int k = j-1; (k >= 0)      && (ag[i][k]); k--) gfb.AddEdge(vtgc.GridToVector(i, j),vtgc.GridToVector(i, k));
            // search on right
            for (int k = j+1; (k < columns) && (ag[i][k]); k++) gfb.AddEdge(vtgc.GridToVector(i, j),vtgc.GridToVector(i, k));
              // search up
            for (int l = i-1; (l >= 0)      && (ag[l][j]); l--) gfb.AddEdge(vtgc.GridToVector(i, j),vtgc.GridToVector(l, j));
              // search down
            for (int l = i+1; (l < rows)    && (ag[l][j]); l++) gfb.AddEdge(vtgc.GridToVector(i, j),vtgc.GridToVector(l, j));
        }
    gfb.BFS(vtgc.GridToVector(startX, startY));
    //cout <<gfb.v[vtgc.GridToVector(goalX, goalY)].distance << endl;
    return gfb.v[vtgc.GridToVector(goalX, goalY)].distance;
            
}

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
       cin >> grid[grid_i];
    }
    int startX;
    int startY;
    int goalX;
    int goalY;
    cin >> startX >> startY >> goalX >> goalY;
    int result = minimumMoves(grid, startX, startY, goalX, goalY);
    cout << result << endl;
    return 0;
}
