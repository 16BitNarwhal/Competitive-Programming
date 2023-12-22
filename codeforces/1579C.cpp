#include <bits/stdc++.h>
using namespace std;
int ar[20][20];
int main() {
  ios::sync_with_stdio(0); cin.tie(0); 
  int t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    memset(ar, 0, sizeof ar);
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        char c;cin>>c;
        ar[i][j] = (c=='*');
      }
    }
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        int sz=0;
        for (int h=0;h<m;h++) {
          if (i>=h && j>=h && j<m && ar[i-h][j-h] && ar[i-h][j+h])
            sz++;
          else break;
        }
        if (sz > k) {
          for (int h=0;h<sz;h++) {
            if (i>=h && j>=h && j<m) 
              ar[i-h][j-h] = ar[i-h][j+h] = 2;
            else break;
          }
        }
      }
    }
    bool ans=1;
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) { 
        if (ar[i][j]==1) 
          ans=0; 
      }  
    }
    cout << (ans ? "YES\n" : "NO\n");
  }
}