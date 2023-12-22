#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n,k;cin>>n>>k;
    string s;cin>>s;
    int cnt=0;
    string res1;
    vector<int> res2(n);
    for (int i=0;i<n-1;i++) {
      int x = (s[i]=='1');
      if (k%2 == x) {
        if (cnt < k) {
          cnt++;
          res1 += '1';
          res2[i] = 1;
        } else {
          res1 += '0';
          res2[i] = 0;
        }
      } else {
        res1 += '1';
        res2[i] = 0;
      }
    }
    int x = (s[n-1]=='1'); 
    res1 += cnt%2 == x ? '0' : '1';
    res2[n-1] = k-cnt;
    cout << res1 << '\n';
    for (int i:res2) cout << i << ' ';
    cout << '\n';
  }
}