#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
const int MM = 1e5+2;
int n[4], ar[4][MM];
int main() {
  vector<pair<int,int>> v;
  for (int i=0;i<4;i++) {
    cin >> n[i];
    for (int j=0;j<n[i];j++) {
      cin >> ar[i][j];
      v.push_back({ar[i][j],i});
    }
  }
  sort(v.begin(),v.end());
  map<int,int> mp;
  int l=0,cnt=0;
  int lans=0, rans=v.size()-1;
  for (int r=0;r<v.size();r++) {
    mp[v[r].ss]++;
    if (mp[v[r].ss]==1) cnt++;
    while (cnt==4) {
      if (v[r].ff-v[l].ff < v[rans].ff-v[lans].ff) {
        lans = l;
        rans = r;
      }
      mp[v[l].ss]--;
      if (mp[v[l].ss]==0) cnt--;
      l++;
    }
  }
  mp.clear();
  vector<pair<int,int>> res;
  for (int i=lans;i<=rans;i++) {
    mp[v[i].ss]++;
    if (mp[v[i].ss]==1)
      res.push_back({v[i].ss, v[i].ff});
  }
  sort(res.begin(),res.end());
  for (auto i : res) cout << i.ss << ' ';
}