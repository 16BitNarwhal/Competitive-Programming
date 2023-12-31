#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, vector<ll>> mp;
ll sortdigits(ll num) {
  vector<ll> digits;
  while (num) {
    digits.push_back(num%10);
    num/=10;
  }
  sort(digits.begin(), digits.end(), greater<ll>());
  num=0;
  for (ll j=0;j<digits.size();j++) {
    num = num*10 + digits[j];
  }
  return num;
}

int main() {
  assert(sortdigits(420690)==964200);
  ll mx=0, res=0;
  for (ll i=1;i<=100000;i++) {
    ll num = i*i;
    num = sortdigits(num);
    mp[num].push_back(i*i);
    if (mp[num].size()>mx) {
      mx = mp[num].size();
      res = num;
    }
  }
  ll x = 1234321;
  x = sortdigits(x);
  for (ll y : mp[x]) {
    cout << y << " ";
  }
  // int t;cin>>t;
  // while (t--) {
  //   int n;cin>>n;
  //   for (int i=0;i<n;i++) {
  //     cout << mp[res][i] << " ";
  //   }
  //   cout<<endl;
  // }
}