// rip ):
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
struct foo { int w, h, id; } ar[MM];
bool cmp(foo a, foo b) { return a.h < b.h; }
bool cmp2(foo a, foo b) { return a.id < b.id; }
int res[MM];
void solve() {
  int n;cin>>n;
  memset(ar, 0, sizeof ar);
  for (int i=0;i<n;i++) {
    cin >> ar[i].w >> ar[i].h;
    ar[i].id = 0;
  }
  sort(ar, ar+n, cmp);
  int mn1=1e9, mn2=1e9;
  for (int i=0;i<n;i++) {
    if (ar[i].w <= ar[mn1].w) {
      mn2 = mn1;
      mn1 = i;
    } else if (ar[i].w < ar[mn2].w) {
      mn2 = i;
    }
  }
  for (int i=0;i<n;i++) {
    int l=i, r=n;
    while (l < r) {
      
    }
  }
}
int main() {
  int t;cin>>t;
  while (t--) solve();
}