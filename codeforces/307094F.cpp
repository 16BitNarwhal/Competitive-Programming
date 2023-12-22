#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<char, int> cntA, cntB;
int main() {
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  for (char x : b) cntB[x]++;
  int l=0;
  ll ans=0;
  for (int r=0;r<n;r++) {
    cntA[a[r]]++;
    while (cntA[a[r]]>cntB[a[r]]) {
      cntA[a[l]]--;
      l++;
    }
    ans += r-l+1;
  }
  cout << ans << '\n';
}