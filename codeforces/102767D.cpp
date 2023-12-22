#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2, mod=1e9+7;
ll qpow(ll a, ll b) { return b==0?1:(b&1?a:1)*qpow(a*a%mod,b>>1) % mod; }
int ar[MM];
map<int,int> freq;
int main() { 
  int t;cin>>t;
  while (t--) {
    freq.clear();
    int n;cin>>n;
    int mx=0;
    for (int i=0;i<n;i++) {
      cin >> ar[i];
      freq[ar[i]]++;
      mx = max(mx, ar[i]);
    }
    bool flag=0;
    int c=0;
    for (auto p : freq) {
      if (p.second>2) {
        flag=1; break;
      } else if (p.second==1) {
        c++;
      }
    }
    if (flag || freq[mx]>1) {
      cout << "0\n";
      continue;
    }
    cout << qpow(2, c-1) << '\n';
  }
}