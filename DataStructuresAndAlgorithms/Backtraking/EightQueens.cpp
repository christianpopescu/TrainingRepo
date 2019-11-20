#include <iostream>
#include <vector>

#define N 8
using namespace std;
std::vector<int> solution(N + 1, 0);

void visit(const std::vector<int>& sol) {
  for (int i=1; i <= N; ++i) {
    std :: cout << "(" << i << ", " << sol[i] << ")  ";    
} 
  std::cout << std::endl;
}

// Class that keeps the "covered" areas by Queens
class OccupiedCells{
public:
  OccupiedCells() : 
    column(N,false),
    diag1(2*N-1,false),
    diag2(2*N-1,false)  {
  }
public:
  bool trySet(int line, int col) {
    // try to position queen at line and column,
    //    if possible - block the corresponding column and diags
    //       returns true;
    //    else - returns false;
    if (column[col] ) return false;
    int d1 = col - line + 3 ;
    int d2 = col + line - 2;
    if (diag1[d1] ) return false;
    if (diag2[d2] ) return false;
    column[col] = true;
    diag1[d1] = true;
    diag2[d2] = true;
    return true;
  }
  bool unSet(int line, int col) {
    int d1 = col - line + 3 ;
    int d2 = col + line - 2;
    column[col] = false;
    diag1[d1] = false;
    diag2[d2] = false;
        
  }
private :
  std::vector<bool> column;
  std::vector<bool> diag1;
  std::vector<bool> diag2;

};

void Backtrack(int k) {
  cout << k << endl;
  OccupiedCells oc;
  for (int i=1; i<= N; ++i) {
    if (oc.trySet(k, i) ) {
          solution[k] = i;
          if (k == N) {
	    visit(solution);
	  }
	  else  {
	    Backtrack(k+1);
	    solution[k] = i;
	}
    }
  }
}

int main(){
  Backtrack(1);
  
  std::cout << "End" << std::endl;
  
}
