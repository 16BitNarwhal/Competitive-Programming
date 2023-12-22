#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main() {
  ll w, h;
  cin >> w >> h;
  ll res=4;
  for (int i=1;i<w;i++) 
    res = (res * 2) % mod;
  for (int i=1;i<h;i++)
    res = (res * 2) % mod;
  cout << res << '\n';
}