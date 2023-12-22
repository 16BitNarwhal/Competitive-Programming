#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
typedef long long ll;
int ar[MM];
int main() { 
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    for (int i = 0; i < n; i++) cin>>ar[i];
    ll sum=0;
    int cur=ar[0];
    for (int i=1;i<n;i++) { 
      if ((cur>0) ^ (ar[i]>0)) {
        sum += cur;
        cur = ar[i]; 
      } else {
        cur = max(cur, ar[i]);
      }
    }
    sum += cur;
    cout << sum << '\n';
  }
}