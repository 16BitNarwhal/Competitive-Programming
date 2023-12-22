#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; } 
ll b, db, nb, mxB;
ll c, dc, nc, mxC;
ll ans;
void fun(ll da) {
  if (ans==-1) return;
  ll g = gcd(da, db);
  ll l = da/g*db;
  if (l != dc) return; 

  if (c - l < b || mxC + l > mxB) { 
    ans = -1;
    return;
  }
  ans = (ans + (l/da * l/da)%MOD) % MOD;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> b >> db >> nb;
    cin >> c >> dc >> nc;

    mxB = b + db*(nb-1);
    mxC = c + dc*(nc-1);
    if (mxC > mxB || c < b || (b%db+db)%db != (c%db+db)%db) {
      cout << "0\n";
      continue;
    }
    
    ans = 0;
    for (ll da=1;da*da<=dc;da++) {
      if (dc%da==0) {
        fun(da);
        if (da*da != dc) fun(dc/da);
      }
    }
    cout << ans << '\n';
  }
}