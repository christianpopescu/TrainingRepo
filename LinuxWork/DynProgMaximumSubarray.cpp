#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

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

void DoComputation(int& pSumMaxCont, int& pSumMaxNoCont ){
  for (int i = 1, k = n-2; i < n; i++, k--) {
    sml[i] = a[i-1];
    if (sml[i-1] > 0) sml[i] += sml[i-1];
    
    smr[k] = a[k+1];
    if (smr[k+1] > 0) smr[k] += smr[k+1];
  }
    int sumMaxCont = INT_MIN;
    int sumMaxNotCont = 0;
    bool atLeastOnePositive = false;
    int maxNegative = INT_MIN;
    int buff;
    for (int i=0; i < n; i++) {
      if ((buff = (a[i] +
	  (sml[i]>0?sml[i]:0) +
		  (smr[i]>0?smr[i]:0))) > sumMaxCont)
	  sumMaxCont = buff;
      if (a[i] >= 0) {sumMaxNotCont+= a[i]; atLeastOnePositive = true;}
      else if (a[i] > maxNegative )  maxNegative = a[i];

	  }

    pSumMaxCont = sumMaxCont;
    if (atLeastOnePositive) pSumMaxNoCont = sumMaxNotCont;
    else pSumMaxNoCont = maxNegative;

}





int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int t;
  cin >> t;
  int memSC[10];
  int memSNC[10];
  for (int i = 0; i<t; i++){
    cin >> n;
    initAarrays();
   
    for (int j = 0; j < n; j++) cin >> a[j];
    DoComputation(memSC[i], memSNC[i]);
  }
  for (int i = 0; i<t; i++){
    cout << memSC[i] << " " << memSNC[i] << endl;
  }
    return 0;
}
