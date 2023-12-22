#include <bits/stdc++.h>
using namespace std;
#define ed pair<int,int>
#define u first
#define v second
vector<ed> vec;
bool vis[26], adj[26][26]; int ans;
int toint(char c) { return (int)(c-'A'); }
char toch(int n) { return (char)(n+'A'); }
void dfs(int u) { // is cyclic
    if (vis[u]) return;
    vis[u] = 1;
    for (int v=0;v<26;v++) {
        if (adj[u][v]) dfs(v);
    }    
}
int main() {
    while(1) {
        string inp;cin>>inp;
        if(inp[0]=='*') break;
        int u=toint(inp[0]), v=toint(inp[1]);
        adj[u][v] = adj[v][u] = 1;
        vec.push_back({u,v});
    } 
    for(ed e:vec) {
        memset(vis, 0, sizeof vis);
        adj[e.u][e.v] = adj[e.v][e.u] = 0;
        dfs(e.u); 
        if(!vis[e.v]) {
            cout<<toch(e.u)<<toch(e.v)<<'\n';
            ans++;
        }
        adj[e.u][e.v] = adj[e.v][e.u] = 1;
    }
    cout << "There are "<<ans<<" disconnecting roads.\n";
}