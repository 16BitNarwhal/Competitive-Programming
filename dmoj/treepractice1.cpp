#include <bits/stdc++.h>
using namespace std; 
#define f first
#define s second
struct ed{int v, w;};
const int MM = 5e5+2;
int N, ar[MM], ar2[MM], start, endd, radius=1e9;
vector<ed> g[MM]; 

void dfs(int u, int prev, int val, int a[MM]) {
    a[u] = val;
    for (ed e : g[u]) {
        if (e.v!=prev) 
            dfs(e.v, u, val+e.w, a);
    }
}
int findmax(int a[MM]) {
    int ret=0, mx=0;
    for (int i=1;i<=N;i++) {
        if (mx < a[i]) {
            mx = a[i];
            ret = i;
        }
    }
    return ret;
}
int main() {
    cin >> N;
    for (int i=0,u,v,w;i<N-1;i++) {
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1, 0, 0, ar);
    start = findmax(ar);
    dfs(start, 0, 0, ar);
    endd = findmax(ar);
    dfs(endd, 0, 0, ar2);
    for (int i=1;i<=N;i++)
        radius = min(radius, max(ar[i], ar2[i]));
    cout << ar[endd] << '\n' << radius << '\n';
}