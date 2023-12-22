#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
ll ar[MM];
int main() {
  int n;cin>>n;
  for (int i=0;i<n;i++) cin >> ar[i];
  int l=0,r=n-1;
  if (l==r) {
    cout << "0\n";
    return 0;
  }
  ll suml=ar[l],sumr=ar[r],ans=0;
  if (suml==sumr) ans=suml;
  while (l<r) {
    if (suml < sumr) {
      l++;
      suml += ar[l];
    }
    if (sumr < suml) {
      r--;
      sumr += ar[r];
    }
    if (suml==sumr) {
      ans = max(ans, suml);
      l++;
      suml += ar[l];
      r--;
      sumr += ar[r];
    }
  }
  cout << ans << '\n';
}