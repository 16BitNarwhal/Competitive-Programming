#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int MM = 105;
int N; bool vis[MM];
vector<int> g[MM];
int main() {
    cin >> N;
    // for (int i=1;i<=N;i++) {
    //     for (int j=1, x;j<=N;j++) {
    //         cin >> x;
    //         if (x) g[i].push_back(j);
    //     }
    // }
    int m;cin>>m;
    while(m--) {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    queue<pi> q; 
    q.push({1,0});
    vis[1] = 1;
    while(!q.empty()) {
        int u = q.front().first, d = q.front().second; q.pop(); 
        if (u==N) { cout << d; return 0; }
        for (int v:g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push({v, d+1}); 
            }
        }
    }
}