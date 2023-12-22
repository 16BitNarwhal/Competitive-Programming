#include <bits/stdc++.h>
using namespace std;
map<int, pair<int,int>> mp;
int n,m,s,f;
int main() {
  cin>>n>>m>>s>>f; 
  for (int i=0;i<m;i++) {
    int t, l, r;
    cin>>t>>l>>r;
    mp[t]={l,r};
  }
  string res="";
  int t=1;
  if (s<f) {
    while (s<f) {
      if (mp[t].first <= s+1 && s <= mp[t].second) {
        res += 'X';
      } else {
        res += 'R';
        s++;
      }
      t++;
    }
  } else if (s>f) {
    while (s>f) {
      if (mp[t].first <= s && s-1 <= mp[t].second) {
        res += 'X';
      } else {
        res += 'L';
        s--;
      }
      t++;
    }
  }
  cout << res << '\n';
}
 