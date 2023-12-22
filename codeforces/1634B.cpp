#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int t;cin>>t;
  while (t--) {
    ll n, x, y;
    cin>>n>>x>>y;
    int cnt=0;
    for (int i=0;i<n;i++) {
      int a;cin>>a; 
      if (a&1) cnt++;
    }
    x += cnt;
    if (x%2 == y%2) {
      cout << "Alice\n";
    } else {
      cout << "Bob\n";
    }
  }
}