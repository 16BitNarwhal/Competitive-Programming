#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int ar[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    int n;cin>>n; 
    string s;cin>>s;
    queue<int> q;
    int cur=0;
    ar[n-1] = 1;
    for (int i=n-2;i>=0;i--) {
      if (s[i] == s[i+1]) ar[i] = ar[i+1] + 1;
      else ar[i] = 1;
    }
    int i=0, j=0, ans=0;
    bool flag=0;
    while (j<n) {
      if (!flag) {
        while (i<n && ar[i]<2) i++;
        if (i<n) ar[i]=0;
      }
      if (i==n) flag=1;
      if (flag) {
        while (i>=0 && ar[i]==0) i--; 
        ar[i]=0;
        if (i<0) break;
      }
      while (j<n && ar[j] != 1) {
        ar[j]=0; j++;
      }
      ar[j]=0; 
      ans++;
    }
    cout << ans << '\n';
  }
}