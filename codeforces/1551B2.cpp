#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int n, k, ar[MM], ans[MM];
vector<int> cnt[MM];
bool cmp(vector<int> a, vector<int> b) {
  return a.size() > b.size();
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while(t--) {
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin>>ar[i];
    
    for (int i=1;i<=n;i++) cnt[i].clear();
    for (int i=1;i<=n;i++) {
      if (cnt[ar[i]].size()<k)
        cnt[ar[i]].push_back(i);
    }
    sort(cnt+1, cnt+n+1, cmp);

    fill(ans, ans+n+1, 0);
    vector<int> temp;
    for (int i=1;i<=n;i++) {
      for (int x : cnt[i]) {
        temp.push_back(x);
        if (temp.size()==k) {
          for (int j=0;j<temp.size();j++) 
            ans[temp[j]] = j+1;
          temp.clear();
        }
      }
    }
    
    for (int i=1;i<=n;i++) 
      cout << ans[i] << ' ';
    cout << '\n';
  }

} 