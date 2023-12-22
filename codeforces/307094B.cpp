#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
ll n, s, ar[MM];
int main() {
  cin >> n >> s;
  for (int i=0;i<n;i++) cin >> ar[i];
  ll sum=0, ans=0;
  int l=0;
  for (int r=0;r<n;r++) {
    sum += ar[r];
    while (sum > s) {
      sum -= ar[l];
      l++;
    }
    ans += 1LL * (r-l+1) * (r-l+2) /2;
  }
  cout << ans << '\n';
}