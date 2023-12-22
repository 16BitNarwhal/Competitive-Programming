#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, x;
  cin >> n >> x;
  set<ll> s;
  queue<pair<ll,int>> q;
  q.push({x,0}); 
  while (!q.empty()) {
    ll x = q.front().first;
    int cnt = q.front().second;
    q.pop();
    ll tmp = x;
    int num_dig = 0;
    while (tmp) {
      num_dig++;
      ll y = tmp%10;
      tmp /= 10;
      if (y>1 && s.count(x*y)==0) {
        q.push({x*y,cnt+1});
        s.insert(x*y);
      }
    }
    if (num_dig >= n) {
      cout << cnt << '\n';
      return 0;
    }
  }
  cout << "-1\n";
}