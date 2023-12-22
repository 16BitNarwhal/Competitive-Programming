#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
typedef long long ll;
int a[MM], b[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++) {
      cin >> a[i];
      b[i] = a[i]-(n-i);
    }
    sort(b+1, b+n+1);
    ll saved=0;
    for (int i=n-k+1;i<=n;i++) saved += b[i]; 
    ll total=0;
    for (int i=1;i<=n;i++) total += a[i];
    total = total - saved - 1LL*k*(k-1)/2;
    cout << total << '\n';
  }
}