#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
typedef long long ll;
ll X[MM], Y[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    int n;cin>>n;
    for (int i=0;i<n;i++) 
      cin >> X[i] >> Y[i];
    sort(X, X+n);
    sort(Y, Y+n);
    ll xx = X[n/2] - X[(n-1)/2]+1;
    ll yy = Y[n/2] - Y[(n-1)/2]+1;
    cout << xx*yy << '\n';
  }

} 