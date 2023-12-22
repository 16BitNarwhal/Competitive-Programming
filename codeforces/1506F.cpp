#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int,int> pi;
const int MM = 2e5+2;
pi ar[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n; cin>>n;
    for (int i=0;i<n;i++) cin >> ar[i].ff;
    for (int i=0;i<n;i++) cin >> ar[i].ss;
    sort(ar,ar+n);
    pi cur = {1,1};
    ll ans=0;
    for (int i=0;i<n;i++) {
      if ((cur.ff + cur.ss)%2==0 &&
          ar[i].ff - cur.ff == ar[i].ss - cur.ss) {
        ans += ar[i].ff - cur.ff;
      } else {
        if ((cur.ff + cur.ss)%2==0) {
          cur.ff++;
        }
        int d = ar[i].ss - cur.ss;
        cur.ff += d; cur.ss += d;
        ans += (ar[i].ff - cur.ff + 1) / 2; 
      }
      cur = ar[i];
    }
    cout << ans << '\n';
  }
}