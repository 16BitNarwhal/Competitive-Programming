#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int ar[MM];
int root(int u) {
  if (ar[u]==u) return u;
  return ar[u]=root(ar[u]);
}
void join(int a, int b) {
  int ra = root(a), rb = root(b); 
  ar[ra] = rb;
}
int main() {
  int n,m;
  cin>>n>>m;
  for (int i=1;i<=n;i++) ar[i]=i;
  for (int i=0,u,v;i<m;i++) {
    cin >> u >> v;
    join(u, v);
  }
  set<int> s;
  for (int i=1;i<=n;i++) 
    s.insert(root(i));
  int c = s.size();
  cout << m - (n-c) << '\n';
}