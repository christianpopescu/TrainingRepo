#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    int result[n+1];
    for (int i=0; i<n+1; i++)
      result[i] = 0;
    for(int i = 0; i < m; i++){
        int a;
        int b;
        int k;
        cin >> a >> b >> k;
	for (int j=a; j<=b; j++)
	  result[j] += k;
    }
    int max = 0;
    for (int i=1; i<n+1; i++) if (max < result[i]) max = result[i];
    cout << max << endl;
    return 0;
}
