#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n, a[MM];
bool ans;
void solve(int i, int sum, int cnt) {
  if (i==n) {
    if (sum==0 && cnt>0) ans=true;
    return;
  } 
  solve(i+1, sum+a[i], cnt+1); 
  solve(i+1, sum-a[i], cnt+1); 
  solve(i+1, sum, cnt);
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    ans=false;
    solve(0, 0, 0);
    cout << (ans ? "YES" : "NO") << '\n'; 
  }
}