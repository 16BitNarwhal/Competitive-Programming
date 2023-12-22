#include <bits/stdc++.h>
using namespace std;
const int MM = 70000;
bool vis[MM];
vector<int> vec[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    int n, k; cin>>n >> k;
    fill(vis, vis+MM, false);
    vector<pair<int,int>> ans;
    for (int i=16;i>=0;i--) {
      if ((1<<i) & k) {
        for (int x=0;x<n;x++) {
          if (vis[x]) continue;
          
        }
      }
    }
  }
}