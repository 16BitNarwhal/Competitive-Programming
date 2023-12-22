#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
ll n, ar[MM], k, x, y, a, b;
bool check(int m) {
  int i=0;
  ll res=0; 
  int cX=0, cY=0, cXY=0;
  for (int i=1;i<=m;i++) {
    if (i%a==0 && i%b==0) cXY++;
    else if (i%a==0) cX++;
    else if (i%b==0) cY++;
  }
  while (cXY--) res+=ar[i++]*(x+y);
  while (cX--) res+=ar[i++]*x;
  while (cY--) res+=ar[i++]*y;
  return res>=k;
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin>>n;
    for (int i=0;i<n;i++) {
      cin >> ar[i];
      ar[i] /= 100;
    }
    sort(ar,ar+n,greater<ll>());
    cin >> x >> a >> y >> b >> k;
    if (x<y) {
      swap(a,b);
      swap(x,y);
    }
    int l=1,r=n,ans=-1;
    while (l<=r) {
      int m = l + (r-l)/2; 
      if (check(m)) {
        ans = m;
        r = m-1;
      } else l = m+1;
    }
    cout << ans << '\n';
  }
}