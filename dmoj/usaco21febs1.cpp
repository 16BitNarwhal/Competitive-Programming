#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MM = 1e5+2;
int N, ans, adj[3000][3000];
bool cows[3000][3000];
vector<pair<int,int>> help = {{-1,0},{1,0},{0,-1},{0,1}};
void add(int x, int y ) {
    if (cows[x][y]) return; 
    cows[x][y]=1; ans++;
    if (adj[x][y]==3) {
        for (auto i:help)
            add(x+i.f, y+i.s);
    }
    for (auto i:help) {
        int u = x+i.f, v = y+i.s;
        adj[u][v]++;
        if (cows[u][v] && adj[u][v] == 3) {
            for (auto j:help)
                add(u+j.f, v+j.s);
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> N; ans=0;
    for (int i=0,x,y; i<N; i++) {
        cin >> x >> y;
        x+=1000, y+=1000; 
        add(x, y); 
        ans--; // remove initial cow
        cout << ans << '\n';
    }
}