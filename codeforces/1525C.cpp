#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+2;
struct bot {
  int x;
  char dir;
  int idx;
  bool operator<(const bot &b) const {
    return x < b.x;
  }
};
vector<bot> ar[2];
int n, m, X[MM], res[MM];
int main() {
  int t;cin>>t;
  while (t--) {
    ar[0].clear(); ar[1].clear();
    int n, m;
    cin >> n >> m;
    for (int i=0;i<n;i++) {
      cin >> X[i];
    }
    for (int i=0;i<n;i++) {
      char c;cin>>c;
      ar[X[i]&1].push_back({ X[i], c, i });
    }
    sort(ar[0].begin(), ar[0].end());
    sort(ar[1].begin(), ar[1].end());
    for (int i=0;i<2;i++) {
      stack<bot> st;
      for (bot cur : ar[i]) {
        if (cur.dir == 'L') {
          if (st.empty()) {
            st.push(cur);
          } else {
            bot prev = st.top(); st.pop();
            if (prev.dir == 'L')
              res[cur.idx] = res[prev.idx] = (cur.x + prev.x) / 2;
            else 
              res[cur.idx] = res[prev.idx] = (cur.x - prev.x) / 2;
          }
        } else {
          st.push(cur);
        }
      }
      while (st.size() >= 2) {
        bot cur = st.top(); st.pop();
        bot prev = st.top(); st.pop();
        if (prev.dir == 'L') 
          res[cur.idx] = res[prev.idx] = (m-cur.x + prev.x + m) / 2;
        else 
          res[cur.idx] = res[prev.idx] = (m-cur.x + m-prev.x) / 2;
      }
      if (!st.empty()) {
        res[st.top().idx] = -1;
        st.pop();
      }
      assert (st.empty());
    }
    for (int i=0;i<n;i++)
      cout << res[i] << ' ';
    cout << '\n';
  }
}