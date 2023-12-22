#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7; 
int main() {
  int t;cin>>t;
  while (t--) {
    int x;cin>>x;
    string s;cin>>s;
    ll n=s.size();
    for (int i=1;i<=x;i++) {
      int v = s[i-1]-'1';
      if (s.size() < x) {
        string sub(s.begin()+i, s.end());
        for (int it=0;it<v;it++) s.insert(s.end(), sub.begin(), sub.end());
      }
      n = (n + (n-i)*v) % mod;
      n = (n+mod) % mod;
    }
    cout << n << '\n';
  }
}