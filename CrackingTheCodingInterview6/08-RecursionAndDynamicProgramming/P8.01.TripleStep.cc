#include <iostream>
#include <vector>

int TripleStep(int n) {
  std::vector<int> result(n,0);

  result[0] = 0;
  result[1] = 1;   // 1
  result[2] = 2;   // 1+1 and 2
  result[3] = 4;     // 1+1+1 and 1+2 and 2+1 and 3
  for (int i = 4; i<=n; ++i)
    result[i] = result[i-1] + result[i-2] + result[i-3];
  return result[n];
}

int Solve(int n, std::vector<int>& memo) {
  if ( n < 4) return memo[n];
  if (memo[n] == 0) memo[n] = Solve(n-1, memo) + Solve(n-2, memo) + Solve(n-3, memo);
  return memo[n];
}

int TripleStepRecursive(int n) {
  std::vector<int> result(n,0);

  result[0] = 0;
  result[1] = 1;   // 1
  result[2] = 2;   // 1+1 and 2
  result[3] = 4;     // 1+1+1 and 1+2 and 2+1 and 3
  return Solve(n, result);
}



int main(){
  std::cout << TripleStep(20) << std::endl;
  std::cout << TripleStepRecursive(20) << std::endl;
  
}
