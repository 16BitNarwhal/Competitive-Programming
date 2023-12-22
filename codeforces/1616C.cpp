#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-4;
int n;
ld ar[80], temp[80];
bool equal(ld a, ld b) { return fabs(a-b) < EPS; }
int calc(ld d, int st) {
  for (int i=0;i<n;i++) temp[i]=ar[i];
  int cnt=0;
  for (int i=st+1;i<n;i++) {
    if (!equal(temp[i], temp[i-1] + d)) {
      cnt++;
      temp[i] = temp[i-1]+d;
    }
  }
  for (int i=st-1;i>=0;i--) {
    if (!equal(temp[i], temp[i+1] - d)) {
      cnt++;
      temp[i] = temp[i+1]-d;
    }
  }
  return cnt;
}
int main() {
  int t;cin>>t;
  while(t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> ar[i]; 
    if (n<=2) {
      cout << "0\n";
      continue;
    }
    int ans = 1e9;
    for (int i=0;i<n;i++) {
      for (int j=i+1;j<n;j++) {
        ld d = ar[j]-ar[i];
        d /= (j-i);
        ans = min(ans, calc(d, i));
      }
    }
    cout << ans << '\n';
  }
} 