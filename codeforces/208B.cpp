#include <bits/stdc++.h>
using namespace std;
int n;
string ar[53];
bool ans=false;
map<string, bool> vis[53];
void solve(int x, string a, string b, string c) {
  if (x==1) {
    ans=true;
    return;
  }
  if (ans) return;
  if (vis[x][a+b+c]) return;
  vis[x][a+b+c]=true;
  if (x>=3) {
    if (ar[x-3][0]==c[0] || ar[x-3][1]==c[1])
      solve(x-1, c, a, b);
  }
  if (x>=1) {
    if (b[0]==c[0] || b[1]==c[1])
      solve(x-1, x>=3?ar[x-3]:"", a, c);
  }
}
int main() {
  cin >> n;
  for (int i=1;i<=n;i++)
    cin >> ar[i];
  if (n==1) {
    cout << "YES\n";
    return 0;
  }
  solve(n, ar[n-2], ar[n-1], ar[n]);
  cout << (ans ? "YES" : "NO") << '\n';
}