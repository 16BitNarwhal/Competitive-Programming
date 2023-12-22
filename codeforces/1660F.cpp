#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int n, ft[2*MM][3], a[MM];
template <typename T>
struct fenwick_tree {
  int n;
  vector<int> ft;
  fenwick_tree(int n) : n(n), ft(n+1, 0) {}
  void add(int i, T x) {
    i++;
    for (;i<=n;i+=i&-i) ft[i] += x;
  }
  T sum(int i) {
    i++;
    T res=0;
    for (;i>0;i-=i&-i) res += ft[i];
    return res;
  }
};
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;cin>>t;
  while (t--) {
    cin >> n;
    string s; cin >> s; 
    a[0]=n;
    for (int i=1;i<=n;i++) { 
      a[i] = a[i-1] + (s[i-1]=='-'?1:-1);
    }
    long long ans=0;
    vector<fenwick_tree<int>> ft(3, fenwick_tree<int>(2*n+1));
    for (int i=0;i<=n;i++) {
      ans += ft[a[i]%3].sum(a[i]);
      ft[a[i]%3].add(a[i], 1);
    }
    cout << ans << '\n';
  }
}