#include <bits/stdc++.h>
using namespace std;
int n, a[101], can[100001];
int main() {
  cin >> n;
  for (int i=1;i<=n;i++) cin>>a[i];
  while(1) {
    int odd=0;
    for (int i=1;i<=n;i++) { 
      if (a[i]&1) odd=1;
    }
    if (odd) break;
    for (int i=1;i<=n;i++) a[i]/=2;
  }
  int sum=0;
  for (int i=1;i<=n;i++) sum+=a[i];
  if (sum&1) {
    cout << "0\n"; return 0;
  }
  can[0]=1;
  for (int i=1;i<=n;i++) {
    for (int j=100000;j>=a[i];j--) can[j] |= can[j-a[i]];
  }
  if (!can[sum/2]) {
    cout << "0\n"; return 0;
  }
  int pos=0;
  for (int i=1;i<=n;i++) {
    if (a[i]&1) {
      pos=i; break;
    }
  }
  cout << "1\n" << pos << '\n';
}