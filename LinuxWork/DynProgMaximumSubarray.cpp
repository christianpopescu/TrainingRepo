#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAXN 10000
using namespace std;

int a[MAXN];
int sml[MAXN];   // Maximum sum at right
int smr[MAXN];   // Maximum sum at left
int n;

void initAarrays(){
  for (int i=0; i<MAXN; i++) {
    a[i]=0;
    sml[i] = 0;
    smr[i] = 0;
  }
}

void DoComputation(){
  for (int i = 1, k = n-1; i < n; i++, k--) {
    sml[i] = a[i-1];
    if (sml[i-1] > 0) sml[i] += sml[i-1];
    
    smr[k] = a[k+1];
    if (smr[k+1] > 0) smr[k] += smr[k+1];
    int sumMaxCont = INT_MIN;
    int buff;
    for (int i=1; i<MAXN; I++) {
      if ((buf = (a[i] +
	  (sml[i]>0?sml[i]:0) +
		  (smr[i]>0?smr[i]:0)) > sumMaxCont)
	  sumMaxCont = buff;

  }



}





int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int t;
  cin >> t;
  for (int i = 0; i<t; i++){
    cin >> n;
    for (int j = 0; j < n; j++) cin >> a[j];

  }

    return 0;
}
