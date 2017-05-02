#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector < long > c, long *r){
  if (r[n] > 0) return r[n];      // get ways alerady computed
    // Complete this function
  long s = 0;
  for (int i=0; i < c.size(); i++) {
    if (c[i] <= n) s += getWays(n - c[i], c, r);
    
  }
  r[n] = s; 
  return s;  
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    long r[251];   // memoization 
    for (int i=0; i<251; i++)
      r[i] = -10000;
    r[0] = 1;
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c, r);
    cout << ways;
    return 0;
}
