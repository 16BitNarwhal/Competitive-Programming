#include <bits/stdc++.h>
using namespace std;
set<int> adj[26];
bool vis[26];
int main() {
  int t;cin>>t;
  while(t--) {
    for (int i=0;i<26;i++) adj[i].clear();

    string pw;cin>>pw;
    int n=pw.length();
    if (n==1) {
      cout << "YES\n";
      for (char c='a';c<='z';c++) 
        cout << c;
      cout << '\n';
      continue;
    }

    for (int i=1;i<n;i++) {
      int u = (int)(pw[i-1]-'a');
      int v = (int)(pw[i]-'a');
      adj[u].insert(v);
      adj[v].insert(u);
    }
    bool flag=0;
    int u=-1;
    for (int i=0;i<26;i++) {
      int x = adj[i].size();
      if (x==1) {
        u = i;
      } else if (x > 2) {
        flag=1; break;
      }
    }
    if (flag || u==-1) {
      cout << "NO\n";
      continue;
    }

    fill(vis, vis+26, 0);
    string res = "";
    res += (char)(u+'a');
    vis[u] = 1;
    int p=-1;
    while (1) { 
      bool flag=0;
      for (int v : adj[u]) {
        if (adj[u].size()==1 && v==p) flag=1;
        if (v==p) continue;
        p = u;
        u = v;
        res += (char)(u + 'a');
        vis[u] = 1;
        break;
      }
      if (flag) break;
    }
    cout << "YES\n";
    cout << res;
    for (int i=0;i<26;i++) 
      if (!vis[i]) cout << (char)(i+'a');
    cout << '\n';
  }
}