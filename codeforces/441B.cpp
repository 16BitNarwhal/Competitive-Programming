#include <bits/stdc++.h>
using namespace std;
int n, v, ar[3003];
int main() {
  memset(ar, 0, sizeof ar);
  cin>>n>>v;
  for (int i=0;i<n;i++) {
    int a,b;cin>>a>>b;
    ar[a] += b;
  }
  int ans=0, prev=0;
  for (int i=1;i<=3001;i++) {
    int amnt = min(prev + ar[i], v);
    ans += amnt;
    amnt = max(amnt-prev, 0);
    prev = ar[i] - amnt;
  }
  cout << ans << '\n';
}