#include <bits/stdc++.h>
using namespace std; 
int n,m,a[101],b[101];
bool dp[101][(1<<9)+1];
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) cin>>a[i];
  for (int i=0;i<m;i++) cin>>b[i];
  for (int x=0;x<(1<<9);x++) {
    bool ans=1;
    for (int i=0;i<n;i++) {
      bool flag=0;
      for (int j=0;j<m;j++) {
        if (((a[i]&b[j])|x)==x) flag=1;
      }
      if (!flag) ans=0;
    }
    if (ans) {
      cout << x << '\n';
      break;
    }
  }
}