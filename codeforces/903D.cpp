#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MM = 2e5+2;
ll ar[MM];
map<ll,ll> mp;
int main() {
  ll n;cin>>n;
  ll sum=0;
  for (int i=0;i<n;i++) {
    cin>>ar[i];
    mp[ar[i]]++;
    sum+=ar[i];
  }
  ull pos_ans=0, neg_ans=0;
  for (ll i=0;i<n;i++) {
    ll cur = sum - (ar[i]*(n-i)) - mp[ar[i]+1] + mp[ar[i]-1];
    if (cur < 0) {
      neg_ans -= cur;
    } else {
      pos_ans += cur;
    }
    if (pos_ans <= neg_ans) {
      neg_ans -= pos_ans;
      pos_ans = 0;
    } else {
      pos_ans -= neg_ans;
      neg_ans = 0;
    }
    mp[ar[i]]--;
    sum -= ar[i];
  }
  if (neg_ans == 0) {
    cout << pos_ans << '\n';
  } else {
    cout << "-" << neg_ans << '\n';
  }
}