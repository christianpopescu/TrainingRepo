#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Hackerrank Dynamic Programming Knapsack problem

 int maxx = 10000;
    int r[2001]; // memoization
int getDistmin(int n, int* a,  int l) {
  //cout << n << ' ' << l << endl;
  if ( l < 0) {
    //cout << n << ' ' << l << " min =" << maxx << endl;
return maxx;
  }
//  cout << "rl = " << r[l] << endl;
   
  if (r[l] < maxx) return r[l];
//  cout << '2' << endl;
  int min = maxx;
  for (int i=n-1; i>=0; i--) {
//    cout << i << endl;
    int stepi=maxx;
    stepi = getDistmin(n, a, l-a[i]);
    //    cout << "     " << i << "  stepi " << stepi << endl;
    if (stepi == maxx) stepi = l;
    if (stepi < min) min = stepi;
  }
  r[l] = min;
  //  cout << n << ' ' << l << " min =" << min << endl;
  return min;
}

int main() {
    int t;
    int n, k;
    int result[10];
   
    cin >> t;
    int a[2000];

    int sum=0;
    int dist=0;  // dist from maximum
    for (int i=0; i<t; i++){
      cin >> n >> k;
      for (int l=0; l<=2000; l++) {
	r[l] = maxx;
      }
      for (int j=0; j < n; j++){
	cin >> a[j];
	r[a[j]] = 0;   // momoization trivial computation
	
      }
//      cout << n << ' ' << k <<  endl;
      result[i] = k - getDistmin(n, a, k);
    }
    for (int i=0; i <t; i++)
      cout << result[i] << endl;
    return 0;
}


