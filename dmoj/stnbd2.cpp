// https://dmoj.ca/problem/stnbd2
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator
const int MXN = 1e5+10, MOD = 1e9+7;
int n, m, u, v, res=0;
ve<int> g[MXN], ar[MXN];
bool mp[MXN];

void dfs(int x) {
    if(g[x].empty())
        ar[x].push_back(0);

    for(int i:g[x]) {
        if(ar[i].empty())

        for(int j : ar[i])
            ar[x].push_back(j+1);
    }
    
}

void solve() {
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>u>>v;
        g[u].push_back(v);
        mp[v] = 1;
    }

    for(int i=1;i<=n;i++) {
        if(!mp[i]) {
            dfs(i);
            for(int j:ar[i]) {
                res = (res+j) % MOD;
            }
        }
    }
    cout<<res<<endl;
}

int main() {
    solve();
    return 0;
}