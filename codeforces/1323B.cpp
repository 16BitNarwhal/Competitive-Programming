#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 40002;
ll a[MM], b[MM], pa[MM], pb[MM];
int main() {
  ll n, m, k;
  cin>>n>>m>>k;
  for (ll i=1;i<=n;i++) {
    cin>>a[i]; pa[i] = pa[i-1] + a[i];
  }
  for (ll i=1;i<=m;i++) {
    cin>>b[i]; pb[i] = pb[i-1] + b[i];
  }
  ll ans=0;
  for (ll p=1;p*p<=k;p++) {
    if (k%p!=0) continue;
    ll q = k/p;
    ll cnta=0, cntb=0;
    for (ll i=q;i<=n;i++) 
      if (pa[i] - pa[i-q] == q) cnta++;
    for (ll i=p;i<=m;i++) 
      if (pb[i] - pb[i-p] == p) cntb++;
    ans += cnta*cntb; 
    
    if (p==q) continue;
    cnta = cntb = 0;
    for (ll i=p;i<=n;i++)
      if (pa[i] - pa[i-p] == p) cnta++;
    for (ll i=q;i<=m;i++)
      if (pb[i] - pb[i-q] == q) cntb++;
    ans += cnta*cntb; 
  }
  cout << ans << '\n';
}

/*
// sliding window
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM  = 40002;
ll n, m, k, a[MM], b[MM];
ll calc(ll p, ll q) { 
	ll A=0, B=0, cnt=0;
	for (int i=0;i<min(p,n);i++) cnt += a[i];
	A += (cnt==p);
	for (int i=p;i<n;i++) {
		cnt += a[i] - a[i-p];
		A += (cnt==p);
	}
	cnt = 0;
	for (int i=0;i<min(q,m);i++) cnt += b[i];
	B += (cnt==q);
	for (int i=q;i<m;i++) {
		cnt += b[i] - b[i-q];
		B += (cnt==q);
	} 
	return A * B;
}
int main() { 
	cin >> n >> m >> k;
	for (int i=0;i<n;i++) cin >> a[i];
	for (int i=0;i<m;i++) cin >> b[i];  
	ll ans=0;
	for (ll p=1;p*p<=k;p++) {
		if (k%p != 0) continue;
		ll q = k/p;
		ans += calc(p, q);
		if (p != q) ans += calc(q, p);
	}
	cout << ans << '\n';
}
*/