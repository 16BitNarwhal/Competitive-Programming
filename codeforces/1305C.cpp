#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[1001];
int main() {
  cin >> n >> m;
  if (n<=m) {
    for (int i=0;i<n;i++) cin>>a[i];
    ll ans=1;
    for (int i=0;i<n;i++) 
      for (int j=i+1;j<n;j++) 
        ans = ans * abs(a[i] - a[j]) % m; 
    cout << ans << '\n';
  } else {
    // more than M #s -> at least 1 pair duplicate (mod M)
    for (int i=0,x;i<n;i++) cin>>x;
    cout << 0 << '\n';
  }
}