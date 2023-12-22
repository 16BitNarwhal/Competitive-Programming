#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int a[MM], mx[MM], lst[100];
int qpow(int a, int b, int mod) {return b==0?1:(b&1?a:1)*qpow(a*a%mod,b/2,mod)%mod; }
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    int n, x;
    cin>>n>>x;
    for (int i=1;i<=n;i++) cin >> a[i];
    memset(lst, -1, sizeof lst);
    lst[1] = 0;
    int mx=0, len=0, s=1;
    for (int i=1;i<=n;i++) { // loop array pos
      s = s*a[i]%x;
      for (int j=1;j<x;j++) { // loop 'last seen' inverse (prefix)  
        if (lst[j] >= 0) {
          int prod = j*s%x; // multiply by inverse to get product from [lst[j], i]
          if (prod > mx) { // if product is greater than current max
            mx = prod; 
            len = i-lst[j]; // len = cur pos - last seen inverse
          } else if (prod%x==mx) {
            len = min(len, i-lst[j]);
          }
        }
      }
      lst[qpow(s, x-2, x)] = i; // len[1/s]  
    }
    cout << mx << ' ' << len << '\n';
  }
}
