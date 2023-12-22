#include <bits/stdc++.h>
using namespace std;
struct env {
  int w, h, id;
  bool operator<(const env &e) const {
    return w < e.w;
  }
} ar[5005];
int dp[5005], pa[5005];
int main() {
  int n, w, h;
  cin >> n >> w >> h;  
  fill(pa, pa+n, -1);
  for (int i=0;i<n;i++) {
    cin >> ar[i].w >> ar[i].h;
    ar[i].id = i+1;
  }
  sort(ar, ar+n);
  for (int i=n-1;i>=0;i--) {
    dp[i] = 1;
    for (int j=i+1;j<n;j++) {
      if (ar[j].w > ar[i].w && ar[j].h > ar[i].h) { 
        if (dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          pa[i] = j;
        }
      }
    }
  }
  int mx=-1, best=-1;
  for (int i=0;i<n;i++) {
    if (ar[i].w>w && ar[i].h>h && dp[i]>mx) {
      mx = dp[i];
      best = i;
    }
  }
  if (mx==-1) {
    cout << "0\n"; return 0;
  }
  cout << mx << '\n';
  for (int i=best;i!=-1;i=pa[i]) {
    cout << ar[i].id << ' ';
  }
}