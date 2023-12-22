#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, ar[MM];
map<int,int> mp;
int main() {
  cin >> n;
  for (int i=0;i<n;i++) cin >> ar[i];
  int best=0, idx=0;
  for (int i=0;i<n;i++) {
    mp[ar[i]] = max(mp[ar[i]], mp[ar[i]-1]+1);
    if (mp[ar[i]] > best) {
      best = mp[ar[i]];
      idx = i;
    }
  } 
  int x = ar[idx];
  stack<int> s;
  while (idx>=0) { 
    if (ar[idx]==x) {
      s.push(idx+1);
      x--;
    }
    idx--;
  }
  cout << s.size() << '\n';
  while (!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }
}