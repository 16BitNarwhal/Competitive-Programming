#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2, mod=1e9+7;
int n, m=3, k=2, a[MM]; 
int main() {
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;cin>>t;
  while(t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a, a+n); 
    int l=0, r=0;
    ll tot=0;
    for (;l<n;l++) {
      while (r<n-1 && a[r+1]-a[l] <= k) r++;
      ll x = (r-l);
      tot += x*(x-1)/2;
    }
    cout << tot << '\n';
  }
}