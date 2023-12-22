#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[(int)(2e5+5)], pfx[(int)(2e5+5)];
int main() {
  int N,Q;
  cin >> N >> Q;
  for (int i=1;i<=N;i++) {
    cin >> a[i];
  }
  sort(a+1, a+N+1, greater<ll>());
  for (int i=1;i<=N;i++) {
    pfx[i] = a[i] + pfx[i-1];
  }
  while (Q--) {
    int n, m;
    cin >> n >> m;
    int l=n-m, r=n;
    cout << pfx[r] - pfx[l] << '\n';
  }
}