#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int ar[MM], cnt[MM];
int main() {
  int n, q;
  cin >> n >> q;
  for (int i=1;i<=n;i++) {
    cin >> ar[i];
  }
  for (int i=0;i<q;i++) {
    int l, r;cin>>l>>r;
    cnt[l]++;
    cnt[r+1]--;
  }
  for (int i=1;i<=n;i++) {
    cnt[i] += cnt[i-1];
  }
  sort(cnt+1, cnt+n+1);
  sort(ar+1, ar+n+1);
  ll sum=0;
  for (int i=1;i<=n;i++) {
    sum += 1LL * ar[i] * cnt[i];
  }
  cout << sum << '\n';
}