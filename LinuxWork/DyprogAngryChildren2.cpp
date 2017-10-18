
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 10000;

void solve(int arr[], int N, int K) {
  int p[2] [MAXN];
  // init computation table  
  for (int i=0; i < N; i++){
    p[0][i] = 0;
    p[1][i] = 0;
  }
  //sort table
  sort(arr, arr + N);
  //compute all version 
  for (int i = 1; i < K ; i++)
    for (int j=0; j < N-i; j++){
      p[i%2][j] = p[(i-1)%2][j];
      for (int k=0; k<i; k++)
	p[i%2][j] += arr[j + k + 1] - arr[j];
    }    
  // compute min solution
  int min = INT_MAX;
  for (int i=0; i<N-K; i++)
    if (min > p[(K-1)%2][i]) min = p[(K-1)%2][i];
  cout << min;
}

int main() {
    int N, K;
     cin >> N >> K;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
     solve(arr, N, K);
    return 0;
}
