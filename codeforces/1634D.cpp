#include <bits/stdc++.h>
using namespace std;
struct dtype {
  int i, j, k;
  bool operator<(const dtype &a) const {
    if (i==a.i) {
      if (j==a.j) return k<a.k;
      return j<a.j;
    }
    return i<a.i;
  };
};
map<dtype, int> mp;
int qry(vector<int> v) {
  sort(v.begin(), v.end());
  int i=v[0], j=v[1], k=v[2];
  if (mp.count({i,j,k})!=0) return mp[{i, j, k}];
  cout << "? " << i << ' ' << j << ' ' << k << endl;
  int res; cin >> res; 
  return mp[{i, j, k}] = res;
}
int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    mp.clear();
    int mx=-1, idx1=0;
    for (int i=3;i<=n;i++) {
      int x = qry({1, 2, i});
      if (x > mx) {
        mx = x;
        idx1 = i;
      }
    }
    mx=-1;
    int idx2=0;
    for (int i=2;i<=n;i++) {
      if (i==idx1) continue;
      int x = qry({1, i, idx1});
      if (x > mx) {
        mx = x;
        idx2 = i;
      }
    }
    if (idx1 > idx2) swap(idx1, idx2);
    int tmp = 2;
    if (idx1==2) {
      tmp++;
      if (idx2==3) tmp++;
    }
    int a = qry({1, tmp, idx1});
    int b = qry({1, tmp, idx2});
    int c = qry({tmp, idx1, idx2});
    mx = max(a, max(b, c));
    if (a==mx) {
      cout << "! 1 " << idx1 << '\n';
    } else if (b==mx) {
      cout << "! 1 " << idx2 << '\n';
    } else {
      cout << "! " << idx1 << ' ' << idx2 << '\n';
    }
  }
}