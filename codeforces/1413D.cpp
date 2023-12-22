#include <bits/stdc++.h>
using namespace std;
struct thing {
  int mn, id;
};
int res[100005];
int main() {
  int n;cin>>n;
  stack<thing> s;
  int idx=0;
  bool flag=true;
  for (int i=0;i<2*n;i++) {
    char op;cin>>op;
    if (op=='+') {
      s.push({0, idx++});
    } else {
      int x;cin>>x;
      if (s.empty()) {
        flag=false;
        continue;
      }
      thing cur = s.top();
      s.pop();
      if (x >= cur.mn) {
        res[cur.id] = x;
        if (!s.empty()) {
          s.top().mn = max(x, s.top().mn);
        }
      } else {
        flag=false;
      }
    }
  }
  if (!flag) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i=0;i<n;i++) 
      cout << res[i] << ' ';
    cout << '\n';
  }
}