#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n, m, a[MM], b[MM];
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<m;i++) cin >> b[i];
  ll ans=0, cnt=0;
  int i=0;
  for (int j=0;j<m;j++) {
    if (j>0 && b[j]==b[j-1]) {
      ans += cnt;
      continue;
    } else cnt=0;
    while (i<n && a[i]<=b[j]) {
      if (a[i]==b[j]) cnt++;
      i++;
    }
    ans += cnt;
  }
  cout << ans << '\n';
}

/*
// not using 2 pointers
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
ll n, m, a[MM], b[MM];
map<ll,ll> mp;
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	ll ans=0;
  for (int i=0;i<m;i++) {
		cin >> b[i];
		ans += mp[b[i]];
	}
  cout << ans << '\n';
}

*/