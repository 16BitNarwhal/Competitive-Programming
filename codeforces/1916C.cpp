#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    vector<int> a(n);
    for (int &i:a) cin>>i;
    ll sum=0;
    int evens=0, odds=0;
    for (int i=0;i<n;i++) {
      evens += (a[i]%2==0);
      odds += (a[i]%2==1);
      sum += a[i];
      if (i==0) cout << a[i] << ' ';
      else cout << sum - odds/3 - (odds%3==1) << ' ';
    }
    cout << endl;
  }
}