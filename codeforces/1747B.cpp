#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    string s;
    for (int i=0;i<n;i++) {
      s += "BAN";
    } 
    vector<pair<int,int>> v;
    for (int i=0;i<3*n;i++) {
      if (s[i]=='A') {
        for (int j=3*n-1;j>i;j--) {
          if (s[j]=='N') {
            swap(s[i],s[j]);
            v.push_back({i,j});
            break;
          }
        }
      }
    } 
    cout << v.size() << '\n';
    for (int i=0;i<v.size();i++) {
      cout << v[i].first+1 << ' ' << v[i].second+1 << '\n';
    }
  }
}