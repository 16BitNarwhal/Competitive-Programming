#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int n, c[MM], a[MM], suf[MM];
struct foo {
  int val, idx;
  bool operator < (const foo &rhs) const {
    return val < rhs.val;
  } 
};
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    cin >> n;
    for (int i=1;i<=n;i++) a[i]=0;
    ll sum=0;
    for (int i=1;i<=n;i++) {
      cin >> c[i];
      sum += c[i];
    }
    int k = sum/n;
    fill(suf, suf+n+2, 0);
    for (int i=n;i>=1;i--) {
      suf[i] += suf[i+1];
      suf[i-1]--;
      suf[i-k]++;
      int x = c[i] + suf[i];  
      if (x==i && k>0) {
        k--;
        a[i]=1;
      } else {
        a[i]=0;
      }
    } 
    for (int i=1;i<=n;i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
}