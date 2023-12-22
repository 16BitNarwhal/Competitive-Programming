#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;
struct E { int u, v, d; };
bool cmp(E x, E y) { return x.d < y.d; }
int n, x[MM], y[MM], mx[MM], dp[MM], tmp[MM]; vector<E> e;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x[i]>>y[i];
        for(int j=0;j<i;j++) {
            int dis = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            e.push_back({j,i,dis});
        }
    }
    sort(e.begin(), e.end(), cmp);
    for(E ed : e) {
        int u = ed.u, v = ed.v, d = ed.d; 
        if(d > mx[u]) mx[u] = d, tmp[u] = dp[u];
        if(d > mx[v]) mx[v] = d, tmp[v] = dp[v];
        dp[u] = max(dp[u], tmp[v] + 1);
        if(u!=0) dp[v] = max(dp[v], tmp[u] + 1);
    }
    cout<<dp[0]<<'\n';
}