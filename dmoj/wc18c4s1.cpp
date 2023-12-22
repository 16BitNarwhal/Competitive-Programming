#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, M, K, ds[MM];
char val[MM]; 
int root(int u) {
    if (ds[u]!=u) return ds[u]=root(ds[u]);
    return u;
}
void join(int u, int v) {
    ds[root(u)] = root(v);
} 
int main() {
    cin >> N >> M >> K;
    for (int i=1;i<=N;i++) 
        cin >> val[i];
    for (int i=1;i<=N;i++) ds[i] = i;
    for (int i=0, u, v;i<M;i++) {
        cin >> u >> v; 
        if (val[u] == val[v])
            join(u, v);
    }
    int ans = 0;
    for (int i=0,u,v;i<K;i++) {
        cin >> u >> v;
        if (root(u) == root(v)) 
            ans++;
    }
    cout << ans << '\n';
}