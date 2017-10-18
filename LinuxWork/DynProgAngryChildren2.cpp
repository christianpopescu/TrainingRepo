
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 10005;

void solve(int arr[], int N, int K) {
  unsigned long long  p[MAXN];
  unsigned long long a[MAXN];

  //sort table
  sort(arr, arr + N);

  //compute all version 
  for (int i = 1; i < K ; i++){
    for (int j=0; j < N - i ; j++)
      a[j] = arr[j+i] - arr[j];
    for (int j=0; j < N - i ; j++)
      for (int l=0; l < K-i; l++)
      p[j] +=  a[j+l];
  }
  // compute min solution
  unsigned long long  min = LONG_MAX;
  for (int i=0; i<N-K; i++)
    if (min > p[i]) min = p[i];
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
