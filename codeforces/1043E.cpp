#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+5;
struct person {
  ll idx, x, y;
} ar[MM];
bool cmp(person a, person b) {
  return a.y-a.x < b.y-b.x;
}
ll calc(person a, person b) {
  return min(a.x + b.y, a.y + b.x);
}
int n, m, pos[MM];
ll res[MM], X[MM], Y[MM];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i=1;i<=n;i++) {
    cin >> ar[i].x >> ar[i].y;
    ar[i].idx = i;
  }
  sort(ar+1, ar+n+1, cmp); 
  for (int i=n;i>=1;i--) 
    X[i] = ar[i].x + X[i+1]; 
  for (int i=1;i<=n;i++)
    Y[i] = ar[i].y + Y[i-1]; 
  for (int i=1;i<=n;i++) 
    pos[ar[i].idx] = i;
  for (int i=1;i<=n;i++) {
    res[i] = ar[i].x * (i-1) + Y[i-1] 
           + ar[i].y * (n-i) + X[i+1];
  }
  for (int i=0;i<m;i++) {
    int a, b;
    cin >> a >> b;
    ll v = calc(ar[pos[a]], ar[pos[b]]);
    res[pos[a]] -= v;
    res[pos[b]] -= v;
  }
  for (int i=1;i<=n;i++) {
    cout << res[pos[i]] << ' ';
  }
}