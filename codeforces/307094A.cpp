#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1001;
ll ar[MM];
int main() {
  ll n, p;
  cin >> n >> p;
  for (int i=0;i<n;i++) cin >> ar[i];
  ll sumn=0;
  for (int i=0;i<n;i++) sumn += ar[i];
  ll cycle = (p+sumn-1)/sumn;
  cycle = max(cycle-1, 0LL);
  p -= cycle * sumn;
  int l=0;
  ll sum=0, start=-1, ans=1e18;
  for (int r=0;r<2*n;r++) {
    sum += ar[r%n];
    while (sum >= p) {
      if (r-l+1 < ans) {
        ans = r-l+1;
        start = l+1;
      }
      sum -= ar[l%n];
      l++;
    }
  }
  ans += cycle*n;
  cout << start << ' ' << ans << '\n';
}