#include <bits/stdc++.h>
using namespace std;
int n;
char a[10001], b[10001];
int main() {
  cin >> n;
  for (int i=0;i<n;i++) cin>>a[i];
  for (int i=0;i<n;i++) cin>>b[i];
  int ans=0;
  for (int i=0;i<n;i++) {
    ans += (a[i]==b[i]);
  }
  cout << ans << '\n';
}