#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int n;
ll s, ar[MM];
int main() {
  cin >> n >> s;
  for (int i=0;i<n;i++) cin >> ar[i];
  int l=0;
  ll ans=0, sum=0;
  for (int r=0;r<n;r++) {
    sum += ar[r]; 
    while (sum - ar[l] >= s) {
      sum -= ar[l];
      l++;
    }
    if (sum >= s)
      ans += l+1;
  }
  cout << ans << '\n';
}