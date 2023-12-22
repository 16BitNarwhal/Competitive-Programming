#include <bits/stdc++.h>
using namespace std;
vector<int> adj[26];
int dst[26], from[26];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    string u, v;
    cin >> u >> v;
    adj[u[0]-'A'].push_back(v[0]-'A');
    adj[v[0]-'A'].push_back(u[0]-'A');
  }
  for (int i=0;i<m;i++) {
    string s, e;
    cin >> s >> e;
    memset(dst, -1, sizeof(dst));
    int u = s[0]-'A';
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
      u = q.front();
      q.pop();
      if (u==(int)(e[0]-'A')) break;
      for (int v : adj[u]) {
        if (dst[v]==-1) {
          dst[v] = dst[u]+1;
          from[v] = u;
          q.push(v);
        }
      }
    }
    u = (int)(e[0]-'A');
    string res="";
    while (u != (int)(s[0]-'A')) {
      res += (char)(u+'A');
      u = from[u];
    }
    res += s[0];
    reverse(res.begin(), res.end());
    cout << res << '\n';
  }
}