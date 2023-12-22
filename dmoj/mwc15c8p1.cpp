#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n;cin>>n;
  ll sum=0;
  for (int i=0;i<n-1;i++) {
    int x;cin>>x;
    sum += x;
  }
  ll ans = 1LL*n*(n+1)/2 - sum;
  cout << ans << '\n';
}