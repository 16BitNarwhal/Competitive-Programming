#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int a[MM], L[MM], R[MM], cntL[MM], cntR[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, q;
  cin >> n >> q;
  for (int i=1;i<=n;i++) 
    cin >> a[i];

  for (int i=1;i<=n;i++) {
    if (L[i-1]>=a[i]) {
      L[i] = L[i-1];
      cntL[i] = cntL[i-1] + (L[i-1]==a[i]);
    } else {
      L[i] = a[i];
      cntL[i] = 1;
    } 
  }
  
  for (int i=n;i>0;i--) {
    if (R[i+1]>=a[i]) {
      R[i] = R[i+1];
      cntR[i] = cntR[i+1] + (R[i+1]==a[i]);
    } else {
      R[i] = a[i];
      cntR[i] = 1;
    }
  }
   
  while (q--) {
    int l, r; cin>>l>>r;
    if (L[l-1] == R[r+1]) { 
      cout << L[l-1] << ' ' << cntL[l-1] + cntR[r+1] << '\n';
    } else if (L[l-1] > R[r+1]) { 
      cout << L[l-1] << ' ' << cntL[l-1] << '\n';
    } else { 
      cout << R[r+1] << ' ' << cntR[r+1] << '\n';
    }

  }
}