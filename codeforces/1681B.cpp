#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int a[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    int m;cin>>m;
    ll sum=0;
    for (int i=0;i<m;i++) {
      ll x;cin>>x;
      sum += x;
    }
    cout << a[sum%n] << '\n';
  }
}