#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int ar[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    map<int,int> mp;
    for (int i=0;i<n;i++) {
      cin >> ar[i];
      mp[ar[i]]++;
    }
    int mex=0;
    for (int i=0;i<=n;i++) {
      if (mp[i]==0) {
        mex=i;
        break;
      }
    }
    set<int> s;
    int prv=-1;
    vector<int> ans;
    ans.push_back(mex);
    for (int i=0;i<n;i++) {
      if (ar[i] < mex)
        s.insert(ar[i]);
      if (s.size() == mex) {
        s.clear();
        for (int j=prv+1;j<=i;j++) {
          mp[ar[j]]--;
          if (mp[ar[j]] == 0)
            mex = min(mex, ar[j]);
        }
        prv = i;
        if (i<n-1) ans.push_back(mex);
      }
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }
}