#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
const int MM = 1e5+5;
struct query { int x, y, rev; };
int N, K, Q, a[MM], f[MM], bit[MM], t[MM];
vector<query> q;
unordered_map<int,int> inv[MM];
// gp_hash_table<int,int> inv[MM]; 
ll ans=0;
void upd(int pos, int val) {
  for (int i=pos;i<=N;i+=i&-i) bit[i] += val;
}
int qry(int pos) {
  int ret=0;
  for (int i=pos;i>0;i-=i&-i) ret+=bit[i];
  return ret;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K >> Q;
  for (int i=1;i<=N;i++) {
    cin>> a[i]; 
    f[a[i]]++;
    // qry(a[i]) are all non-inversions
    ans += (i-1) - qry(a[i]); 
    upd(a[i], 1);
  }
  for (int i=1;i<=K;i++) t[i]=i;
  for (int i=1, k, x, y, rev; i<=Q; i++) {
    cin >> k;
    x = t[k], y = t[k+1]; rev = 1;
    if (f[x] > f[y]) { swap(x, y); rev = -1; }
    q.push_back({x, y, rev});
    inv[x][y] = 0;
    swap(t[k], t[k+1]);
  }
  memset(f, 0, sizeof f);
  for (int i=1;i<=N;i++) {
    for (auto &e : inv[a[i]]) e.second += f[e.first];
    f[a[i]]++;
  }
  for (auto &e : q) {
    ans += (1LL * f[e.x]*f[e.y] - 2LL*inv[e.x][e.y]) * e.rev;
    cout << ans << '\n';
  }
}