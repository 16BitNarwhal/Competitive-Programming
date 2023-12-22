// unsolved
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
struct ed { int v, w; };
int N, M, L, groups, ar[MM], ar2[MM], rad[MM];
vector<ed> g[MM];
vector<int> grp[MM]; 
bool vis[MM];
void dfs(int u, int prev, int ptr, int val, int a[]) {
    if (!vis[u]) grp[ptr].push_back(u);
    vis[u] = 1, a[u] = val; 
    for (ed e:g[u])
        if (e.v != prev)
            dfs(e.v, u, ptr, val+e.w, a); 
}
int findmax(int ptr, int a[]) {
    int ret=0,mx=0;
    for (int u:grp[ptr]) 
        if (a[u]>mx)
            mx = a[u], ret = u; 
    return ret;
}
int findrad(int ptr) {
    int ret=0, mn=2e9;
    for (int u:grp[ptr]) { 
        rad[u] = max(ar[u],ar2[u]);
        if (rad[u]<mn)
            mn = rad[u], ret = u;
    } 
    return ret;
}
int process(int u, int ptr) { 
    dfs(u, 0, ptr, 0, ar);  
    int start = findmax(ptr, ar); 
    dfs(start, 0, ptr, 0, ar); 
    int end = findmax(ptr, ar); 
    dfs(end, 0, ptr, 0, ar2);
    return rad[findrad(ptr)];
}
vector<int> connect;
int travelTime(int N_, int M_, int L_, int A_[], int B_[], int T_[]) {
    N = N_, M = M_, L = L_;
    for (int i=0;i<M;i++) {
        g[A_[i]].push_back({B_[i],T_[i]});
        g[B_[i]].push_back({A_[i],T_[i]});
    }
    int mx=0, pos=0;
    for (int i=0;i<N;i++) {
        if (!vis[i]) {
            int cur = process(i, groups++);
            connect.push_back(cur);
            if (rad[cur]>mx) {
                mx = rad[cur], pos = cur; 
            }
        }
    }
    for (int i:connect) {
        if (pos != i) {
            g[i].push_back({pos,L});
            g[pos].push_back({i,L});
        }
    }
    grp[groups].resize(N);
    for (int i=0;i<N;i++) grp[groups][i] = i;
    dfs(pos, 0, groups, 0, ar);  
    int start = findmax(groups, ar);
    dfs(start, 0, groups, 0, ar); 
    int end = findmax(groups, ar);
    return rad[end];
}
int main() {
    cout << "Sample test case: ";
    int A_[] = {0, 8, 2, 5, 5, 1, 1, 10, 12, 13, 12},
        B_[] = {8, 2, 7, 11, 1, 3, 9, 6, 13, 14, 15},
        T_[] = {4, 2, 4, 3, 7, 1, 5, 3, 2, 8, 5};
    cout << travelTime(16, 11, 3, A_, B_, T_) << '\n'; 
}