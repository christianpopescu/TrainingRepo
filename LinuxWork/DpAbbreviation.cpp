#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char a[1001], b[1001];
int  memoP[1001][1001];
int m=0, n=0;

bool hasAsmallCapsToEnd(int i, int n)
{
  for (int k=i; k<n; k++)
    if (isupper(a[k])) return false;
  return true;
}

bool P(int i, int n, int j, int m)
{
  if (memoP[i][j] >=0) return  memoP[i][j];
  bool isAimaj = isupper(a[i]);
  
  //isAimaj and Ai != Bj
  if (isAimaj && a[i] != b[j]) return memoP[i][j] = false;
  
  //isAimaj and Ai = Bj
  if (isAimaj && a[i] == b[j])
   if (j!=m)
     if (i!=n) return memoP[i][j] = P(i+1, n, j+1, m);    // equal case
     else      return memoP[i][j] = false;
   else    // j == m
     if (i==n) return memoP[i][j] = true;
     else      return memoP[i][j] = hasAsmallCapsToEnd(i+1, n);

  //isAimaj= false and Ai = Bj
  if (!isAimaj && toupper(a[i]) == b[j])
   if (j!=m)
     if (i!=n) return memoP[i][j] = (P(i+1, n, j,m) ||         //delete case
		       P(i+1, n, j+1, m));    // equal case
     else      return memoP[i][j] = false;
   else    // j == m
     if (i==n) return memoP[i][j] = true;
     else      return memoP[i][j] = hasAsmallCapsToEnd(i+1, n);

   //isAimaj= false and Ai = Bj
  if (!isAimaj && toupper(a[i]) != b[j]) 
    if (i==n) return memoP[i][j] = false;
    else     return memoP[i][j] = P(i+1, n, j,m) ;         //delete case

  return memoP[i][j] = false;

}

int main() {
	int q =0;
	cin >> q;
	string sa;
	string sb;
	bool mem[10];
  

	for (int i=0; i<q; i++){
for (int i=0; i<1001; i++)
    for (int j=0; j<1001; j++)
      {
      memoP[i][j] = -1;	 
         a[j]=0;
	  b[j]=0;

      }
 cin >> sa;
	  cin >> sb;
 	  strcpy(a, sa.c_str());
	  strcpy(b, sb.c_str());
	  n=sa.size();
	  m=sb.size();
	  mem[i] = P(0,n-1, 0, m-1);
	}
	for (int i=0; i<q; i++) cout << (mem[i]? "YES": "NO") << endl;
	  

    return 0;
}
