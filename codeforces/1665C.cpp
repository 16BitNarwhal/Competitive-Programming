#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int t, n;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    map<int,int> cnt;
    for (int i=2;i<=n;i++) {
      int x;cin>>x;
      cnt[x]++;
    }
    vector<int> v;
    for (int i=1;i<=n;i++) {
      if (cnt[i]>0) v.push_back(cnt[i]);
    }
    sort(v.begin(), v.end());
    priority_queue<int> pq;
    int ans=0;
    while (1) {
      ans++;

      // spread
      priority_queue<int> tmp;
      while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        if (x-1 > 0) tmp.push(x-1);
      }
      pq = tmp;
      
      // inject
      if (v.empty()) {
        if (pq.empty()) break;
        int x = pq.top();
        pq.pop();
        pq.push(x-1);
      } else {
        int x = v.back();
        v.pop_back();
        pq.push(x-1);
      }
    }
    cout << ans << '\n';
  }
}