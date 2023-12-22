#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+2;
ll ar[MM], stop[MM];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i=1;i<=n;i++) {
    cin >> ar[i];
  }
  // sum = sum of previous progressions, subtract from a[i] 
  // num = current num arithmetic progressions, subtract from sum
  // stop[i] = number of progressions that stop at i, subtract from num
  ll ans=0, sum=0, num=0;
  for (int i=n;i>=1;i--) {
    sum -= num;
    ar[i] -= sum;
    num -= stop[i];
    if (ar[i] <= 0)
      continue;
    ll x = (ar[i]-1)/min(k, i)+1;
    ans += x;
    sum += x * min(k, i);
    num += x;
    stop[max(0, i-k)] = x; // stop subtracting x at pos i-k
  }
  cout << ans << '\n';
}