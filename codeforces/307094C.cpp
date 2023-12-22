#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM =3e5+2;
int n, m, ar[MM];
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) cin >> ar[i];
  ll ans=0;
  int l=0;
  for (int r=0;r<n;r++) {
    while (ar[r] - ar[l+1] > m) 
      l++;
    if (ar[r] - ar[l] > m) 
      ans += l+1;
  }
  cout << ans << '\n';
}