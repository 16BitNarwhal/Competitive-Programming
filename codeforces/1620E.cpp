#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int op[MM], x[MM], y[MM], p[MM];
int main() {
  int q;cin>>q;
  for (int i=0;i<q;i++) {
    cin >> op[i];
    if (op[i]==1) {
      cin >> x[i];
    } else {
      cin >> x[i] >> y[i];
    }
  }
  for (int i=0;i<MM;i++) p[i]=i;
  vector<int> ans;
  for (int i=q-1;i>=0;i--) {
    if (op[i]==1) {
      ans.push_back(p[x[i]]);
    } else {
      p[x[i]] = p[y[i]];
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i:ans) cout << i << ' ';
}